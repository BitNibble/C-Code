#!/data/data/com.termux/files/usr/bin/bash
#
# Move tools from system namespace to tool namespace
#

SYSTEM_DIR="/data/data/com.termux/files/usr/local/bin/system"
TOOL_DIR="/data/data/com.termux/files/usr/local/bin/tool"

# Make sure the tool directory exists
mkdir -p "$TOOL_DIR"

# List of tool binaries to move (adjust as needed)
TOOLS=("grep" "sed" "awk" "perl" "rg")  # add more as needed

for cmd in "${TOOLS[@]}"; do
    if [ -x "$SYSTEM_DIR/$cmd" ]; then
        echo "Moving $cmd from system to tool..."
        mv "$SYSTEM_DIR/$cmd" "$TOOL_DIR/"
    else
        echo "Skipping $cmd: not found in system"
    fi
done
#
