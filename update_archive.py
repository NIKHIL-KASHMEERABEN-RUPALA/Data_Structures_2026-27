import os
import re
import requests
from collections import defaultdict

REPO_BASE_URL = "https://github.com/NIKHIL-KASHMEERABEN-RUPALA/Data_Structures_2026-27/tree/master"
README_PATH = "README.md"
LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

def get_topics_from_leetcode(title_slug):
    """Fetch official topic tags from LeetCode GraphQL API."""
    query = """
    query getQuestionTopics($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
        }
      }
    }
    """
    try:
        response = requests.post(
            LEETCODE_GRAPHQL_URL,
            json={"query": query, "variables": {"titleSlug": title_slug}},
            headers={"User-Agent": "Mozilla/5.0"},
            timeout=8
        )
        if response.status_code == 200:
            data = response.json()
            tags = data.get("data", {}).get("question", {}).get("topicTags", [])
            return [t["name"] for t in tags if "name" in t]
    except Exception as e:
        print(f"API query failed for {title_slug}: {e}")
    return []

def get_local_topics(folder_path):
    """Fallback: Parse HTML tags from local README.md."""
    readme = os.path.join(folder_path, "README.md")
    if not os.path.exists(readme):
        return []
    
    with open(readme, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    match = re.search(r"<h3[^>]*>.*?(?:Topics|Related Topics).*?</h3>\s*<ul>(.*?)</ul>", content, re.DOTALL | re.IGNORECASE)
    if match:
        raw_tags = re.findall(r"<li[^>]*>(.*?)</li>", match.group(1))
        return [re.sub(r"<.*?>", "", t).strip() for t in raw_tags if t.strip()]
    return []

def main():
    topic_map = defaultdict(set)
    problem_folders = []

    # Detect problem folders (e.g., 0104-maximum-depth-of-binary-tree)
    for folder in sorted(os.listdir(".")):
        if os.path.isdir(folder) and re.match(r"^\d+-", folder):
            problem_folders.append(folder)

    print(f"Found {len(problem_folders)} problem folders.")

    for folder in problem_folders:
        # Extract title slug by stripping the leading problem number
        slug = re.sub(r"^\d+-", "", folder).strip()
        
        # 1. Try fetching directly from LeetCode API
        topics = get_topics_from_leetcode(slug)

        # 2. Fallback to local README if API fails
        if not topics:
            topics = get_local_topics(folder)

        # 3. Default fallback
        if not topics:
            topics = ["Uncategorized"]

        print(f"[{folder}] -> {', '.join(topics)}")
        for topic in topics:
            topic_map[topic].add(folder)

    # Generate Markdown Block
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
    archive_block = "\n".join(lines)

    # Update README.md
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
        print("Updated README.md successfully.")
    else:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(archive_block)
        print("Created README.md.")

if __name__ == "__main__":
    main()