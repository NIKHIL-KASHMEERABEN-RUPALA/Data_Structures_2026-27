import os
import re
import requests
from collections import defaultdict

REPO_BASE_URL = "https://github.com/NIKHIL-KASHMEERABEN-RUPALA/Data_Structures_2026-27/tree/master"
README_PATH = "README.md"
LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

def fetch_leetcode_topics(slug):
    """Fetch tags from LeetCode GraphQL with complete browser headers."""
    query = """
    query getQuestionDetails($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
        }
      }
    }
    """
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
        "Referer": f"https://leetcode.com/problems/{slug}/",
        "Content-Type": "application/json"
    }
    try:
        res = requests.post(
            LEETCODE_GRAPHQL_URL,
            json={"query": query, "variables": {"titleSlug": slug}},
            headers=headers,
            timeout=5
        )
        if res.status_code == 200:
            data = res.json()
            tags = data.get("data", {}).get("question", {}).get("topicTags", [])
            return [t["name"] for t in tags if "name" in t]
    except Exception:
        pass
    return []

def extract_local_topics(folder_path):
    """Multi-pattern extractor for local problem README.md files."""
    readme_path = os.path.join(folder_path, "README.md")
    if not os.path.exists(readme_path):
        return []

    with open(readme_path, "r", encoding="utf-8", errors="ignore") as f:
        text = f.read()

    topics = []

    # Pattern 1: LeetHub HTML tags (<h3>...Related Topics...</h3>...<li>...</li>)
    html_match = re.search(r"<h3[^>]*>.*?(?:Topics|Related Topics).*?</h3>(.*?)<(?:h3|hr|div|$)", text, re.DOTALL | re.IGNORECASE)
    if html_match:
        items = re.findall(r"<li[^>]*>(.*?)</li>", html_match.group(1))
        topics.extend([re.sub(r"<.*?>", "", item).strip() for item in items if item.strip()])

    # Pattern 2: Markdown bold tags (e.g. **Topics:** [Array](url), [Tree](url))
    if not topics:
        md_match = re.search(r"\*\*(?:Topics|Related Topics|Tags)\*\*[:\s]+(.*)", text, re.IGNORECASE)
        if md_match:
            raw_line = md_match.group(1).split("\n")[0]
            items = re.findall(r"\[([^\]]+)\]\([^\)]+\)", raw_line) or raw_line.split(",")
            topics.extend([t.strip(" `*") for t in items if t.strip()])

    # Pattern 3: LeetCode topic badge links
    if not topics:
        badge_matches = re.findall(r"/tag/([a-z0-9\-]+)/?", text, re.IGNORECASE)
        if badge_matches:
            topics.extend([b.replace("-", " ").title() for b in badge_matches])

    return list(dict.fromkeys(topics))

def main():
    topic_map = defaultdict(set)
    folders = [f for f in sorted(os.listdir(".")) if os.path.isdir(f) and re.match(r"^\d+-", f)]

    print(f"Discovered {len(folders)} problem directories.")

    for folder in folders:
        # Extract clean title slug (e.g., "0104-maximum-depth-of-binary-tree" -> "maximum-depth-of-binary-tree")
        slug = re.sub(r"^\d+-", "", folder).strip()

        # Step A: Local extraction first (fastest and immune to API rate limits)
        topics = extract_local_topics(folder)

        # Step B: LeetCode API if local file doesn't list tags
        if not topics:
            topics = fetch_leetcode_topics(slug)

        # Step C: Fallback topic
        if not topics:
            topics = ["Uncategorized"]

        print(f"✔ {folder} -> {topics}")
        for t in topics:
            topic_map[t].add(folder)

    # Generate Markdown archive
    lines = ["<!---LeetCode Topics Start-->", "# LeetCode Solved Questions Archive\n"]
    for topic in sorted(topic_map.keys()):
        lines.append(f"## {topic}\n")
        lines.append("| Problem |")
        lines.append("| :--- |")
        for problem in sorted(topic_map[topic]):
            url = f"{REPO_BASE_URL}/{problem}"
            lines.append(f"| [{problem}]({url}) |")
        lines.append("")
    lines.append("<!---LeetCode Topics End-->")
    new_archive = "\n".join(lines)

    # Replace or append in README.md
    if os.path.exists(README_PATH):
        with open(README_PATH, "r", encoding="utf-8") as f:
            content = f.read()

        pattern = r"<!---LeetCode Topics Start-->.*?<!---LeetCode Topics End-->"
        if re.search(pattern, content, re.DOTALL):
            updated_content = re.sub(pattern, new_archive, content, flags=re.DOTALL)
        else:
            updated_content = content.rstrip() + "\n\n" + new_archive

        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(updated_content)
        print("\n✅ Successfully updated README.md archive with all topics.")
    else:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(new_archive)
        print("\n✅ README.md created.")

if __name__ == "__main__":
    main()