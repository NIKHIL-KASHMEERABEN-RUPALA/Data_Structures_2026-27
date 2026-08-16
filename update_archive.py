import os
import re
from collections import defaultdict

REPO_BASE_URL = "https://github.com/NIKHIL-KASHMEERABEN-RUPALA/Data_Structures_2026-27/tree/master"
README_PATH = "README.md"

topic_map = defaultdict(set)

# Scan all problem folders (e.g., 0104-maximum-depth-of-binary-tree)
for folder in sorted(os.listdir(".")):
    if os.path.isdir(folder) and re.match(r"^\d{4}-", folder):
        readme_file = os.path.join(folder, "README.md")
        
        if os.path.exists(readme_file):
            with open(readme_file, "r", encoding="utf-8") as f:
                content = f.read()
                
                # Match tags from LeetHub v2/v3 or standard topic lists
                match = re.search(r"<h3>(?:Related Topics|Topics)</h3>(.*?)</ul>", content, re.DOTALL)
                if match:
                    topics = re.findall(r"<li>(.*?)</li>", match.group(1))
                    for topic in topics:
                        clean_topic = re.sub(r"<.*?>", "", topic).strip()
                        if clean_topic:
                            topic_map[clean_topic].add(folder)

# Construct updated archive block
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
new_archive_content = "\n".join(lines)

# Inject into README.md
if os.path.exists(README_PATH):
    with open(README_PATH, "r", encoding="utf-8") as f:
        readme = f.read()

    pattern = r"<!---LeetCode Topics Start-->.*?<!---LeetCode Topics End-->"
    if re.search(pattern, readme, re.DOTALL):
        updated_readme = re.sub(pattern, new_archive_content, readme, flags=re.DOTALL)
    else:
        updated_readme = readme.rstrip() + "\n\n" + new_archive_content

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(updated_readme)
