#!/usr/bin/env bash

SRC_DIR="$1"
DEST_DIR="/data/data/com.termux/files/usr/bin"

if [ -z "$SRC_DIR" ]; then
    echo "Usage: $0 <source-folder>"
    exit 1
fi

for file in "$SRC_DIR"/*; do
    [ -f "$file" ] || continue

    name=$(basename "$file")
    target="$DEST_DIR/$name"

    if [ -e "$target" ]; then
        # Use absolute paths to avoid PATH issues
        /data/data/com.termux/files/usr/bin/rm -f "$file"
        /data/data/com.termux/files/usr/bin/ln -s "$target" "$file"
        echo "replaced $name with link -> $target"
    else
        echo "skip $name: no matching file in DEST_DIR"
    fi
done
#
