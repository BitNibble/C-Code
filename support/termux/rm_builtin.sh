#!/data/data/com.termux/files/usr/bin/bash
SYSTEM_DIR="/data/data/com.termux/files/usr/local/bin/system"  # adjust to your system folder

# get all Bash builtins
BUILTINS=$(compgen -b)

for cmd in "$SYSTEM_DIR"/*; do
    [ -e "$cmd" ] || continue   # works for regular files, symlinks, etc.
    fname=$(basename "$cmd")

    for b in $BUILTINS; do
        if [ "$fname" = "$b" ]; then
            echo "Removing builtin from system: $fname"
            rm -f "$cmd"
        fi
    done
done
#
