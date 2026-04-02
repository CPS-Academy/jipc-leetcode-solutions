#!/usr/bin/env bash
# generate_readmes.sh – robust version that creates a README.md in every directory
# It handles spaces and special characters safely using null‑delimited find.
set -euo pipefail

# Determine the root directory (the directory where this script resides)
ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Helper: URL‑encode spaces for Markdown links
url_encode() {
  local str="$1"
  echo "${str// /%20}"
}

# Iterate over every directory (including the root) while ignoring hidden directories like .git
find "$ROOT_DIR" -type d -not -path "*/.*" -print0 |
while IFS= read -r -d '' dir; do
  # Ensure it is a directory (safety)
  [[ -d "$dir" ]] || continue

  # Collect all files in this directory (exclude any existing README.md)
  mapfile -t files < <(find "$dir" -maxdepth 1 -type f ! -name "README.md" -print0 | xargs -0 -n1)

  # Relative path for heading ("." for root)
  rel="${dir#$ROOT_DIR/}"
  [[ -z "$rel" ]] && rel="."

  readme_path="$dir/README.md"
  {
    echo "# Solutions in ${rel}"
    echo
    if [[ ${#files[@]} -eq 0 ]]; then
      echo "*(No solution files in this directory)*"
    else
      echo "## File Index"
      echo
      for f in "${files[@]}"; do
        filename="$(basename "$f")"
        encoded=$(url_encode "$filename")
        echo "- [${filename}](./${encoded})"
      done
    fi
  } > "$readme_path"
done

echo "✅ README generation completed."
