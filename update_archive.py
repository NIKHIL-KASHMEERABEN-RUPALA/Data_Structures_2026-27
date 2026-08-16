import os
import re
import json
import subprocess
import requests
from collections import defaultdict

REPO_BASE_URL = "https://github.com/NIKHIL-KASHMEERABEN-RUPALA/Data_Structures_2026-27/tree/master"
README_PATH = "README.md"
TAG_CACHE_FILE = ".topic_cache.json"
LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

def get_currently_modified_folders():
    """Detects newly added or modified problem folders in the current git workspace."""
    try:
        status_output = subprocess.check_output(
            ["git", "status", "--porcelain"], text=True, errors="ignore"
        )
        changed_folders = set()
        for line in status_output.splitlines():
            # Format: ' M folder/file' or '?? folder/'
            path = line[3:].strip().strip('"')
            parts = path.split(os.sep)
            if parts and re.match(r"^\d+-", parts[0]):
                changed_folders.add(parts[0])
        return changed_folders
    except Exception:
        return set()

def fetch_leetcode_topics_api(slug):
    """Fetches exact official topic tags from LeetCode GraphQL API."""
    query = """
    query getQuestionTopicTags($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
        }
      }
    }
    """
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36",
        "Referer": f"https://leetcode.com/problems/{slug}/",
        "Content-Type": "application/json"
    }
    try:
        response = requests.post(
            LEETCODE_GRAPHQL_URL,
            json={"query": query, "variables": {"titleSlug": slug}},
            headers=headers,
            timeout=6
        )
        if response.status_code == 200:
            data = response.json()
            tags = data.get("data", {}).get("question", {}).get("topicTags", [])
            return [t["name"] for t in tags if "name" in t]
    except Exception as e:
        print(f"  [API Warning] Could not fetch tags for '{slug}': {e}")
    return []

def extract_local_tags(folder_path):
    """Fallback: Extracts tags directly from the folder's local README.md."""
    readme_path = os.path.join(folder_path, "README.md")
    if not os.path.exists(readme_path):
        return []

    with open(readme_path, "r", encoding="utf-8", errors="ignore") as f:
        text = f.read()

    # Match LeetHub HTML list format: <h3>Related Topics</h3>...<li>Tag</li>
    html_match = re.search(r"<h3[^>]*>.*?(?:Topics|Related Topics).*?</h3>\s*<ul>(.*?)</ul>", text, re.DOTALL | re.IGNORECASE)
    if html_match:
        items = re.findall(r"<li[^>]*>(.*?)</li>", html_match.group(1))
        tags = [re.sub(r"<.*?>", "", item).strip() for item in items if item.strip()]
        if tags:
            return tags

    # Match Markdown format: **Topics:** [Tag1](url), [Tag2](url)
    md_match = re.search(r"\*\*(?:Topics|Related Topics|Tags)\*\*[:\s]+(.*)", text, re.IGNORECASE)
    if md_match:
        raw_line = md_match.group(1).split("\n")[0]
        items = re.findall(r"\[([^\]]+)\]\([^\)]+\)", raw_line) or raw_line.split(",")
        tags = [t.strip(" `*") for t in items if t.strip()]
        if tags:
            return tags

    return []

def load_cache():
    if os.path.exists(TAG_CACHE_FILE):
        try:
            with open(TAG_CACHE_FILE, "r", encoding="utf-8") as f:
                return json.load(f)
        except Exception:
            return {}
    return {}

def save_cache(cache):
    try:
        with open(TAG_CACHE_FILE, "w", encoding="utf-8") as f:
            json.dump(cache, f, indent=2, sort_keys=True)
    except Exception as e:
        print(f"Warning: Could not save topic cache: {e}")

def main():
    cache = load_cache()
    changed_folders = get_currently_modified_folders()
    
    if changed_folders:
        print(f"🚀 Detected active/staged changes in: {', '.join(changed_folders)}")

    all_folders = [f for f in sorted(os.listdir(".")) if os.path.isdir(f) and re.match(r"^\d+-", f)]
    print(f"📁 Found {len(all_folders)} total problem folders.")

    topic_map = defaultdict(set)

    for folder in all_folders:
        slug = re.sub(r"^\d+-", "", folder).strip()
        tags = []

        # If it's a newly added folder or not in cache, query LeetCode API
        if folder in changed_folders or folder not in cache:
            print(f"🔍 Classifying tags for: {folder} (slug: {slug})")
            tags = fetch_leetcode_topics_api(slug)
            
            # If API fails or throttles, check local README tags
            if not tags:
                tags = extract_local_tags(folder)
            
            if tags:
                cache[folder] = tags
            else:
                tags = cache.get(folder, ["Uncategorized"])
        else:
            tags = cache.get(folder, [])
            if not tags:
                tags = extract_local_tags(folder) or ["Uncategorized"]

        print(f"  ✔ {folder} -> {tags}")
        for t in tags:
            topic_map[t].add(folder)

    # Save cached tags to minimize redundant API calls
    save_cache(cache)

    # Generate the Markdown block
    lines = ["<!---LeetCode Topics Start-->", "# My Leet_Code Archive\n"]
    for topic in sorted(topic_map.keys()):
        lines.append(f"## {topic}\n")
        lines.append("| Problem |")
        lines.append("| :--- |")
        for problem in sorted(topic_map[topic]):
            url = f"{REPO_BASE_URL}/{problem}"
            lines.append(f"| [{problem}]({url}) |")
        lines.append("")
    lines.append("<!---LeetCode Topics End-->")
    archive_block = "\n".join(lines)

    # Write updates into root README.md
    if os.path.exists(README_PATH):
        with open(README_PATH, "r", encoding="utf-8") as f:
            content = f.read()

        pattern = r"<!---LeetCode Topics Start-->.*?<!---LeetCode Topics End-->"
        if re.search(pattern, content, re.DOTALL):
            new_content = re.sub(pattern, archive_block, content, flags=re.DOTALL)
        else:
            new_content = content.rstrip() + "\n\n" + archive_block

        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(new_content)
        print("\n🎉 README.md archive updated with dynamic topics!")
    else:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(archive_block)
        print("\n🎉 README.md created and populated.")

if __name__ == "__main__":
    main()
