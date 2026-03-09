#!/data/data/com.termux/files/usr/bin/bash
#
if [ -n "$__OO_NAMESPACE_LOADED" ]; then
    return
fi
__OO_NAMESPACE_LOADED=1
#
#
wdir="/data/data/com.termux/files/home/Documents"
hdir="/data/data/com.termux/files/home"
fdir="/data/data/com.termux/files"
tdir="/data/data/com.termux"
bdir="/data/data/com.termux/files/usr/bin"
lbdir="/data/data/com.termux/files/usr/local/bin"
oodir="/data/data/com.termux/files/usr/local/etc"
msdir="/data/data/com.termux/files/storage/microSD"
#
#
export PATH="$lbdir:$PATH"
# export PATH="$lbdir/system:$lbdir/app:$lbdir/doc:$lbdir/dev:$lbdir/net:$lbdir/tool":$PATH
# export PATH="$lbdir/info":$PATH
#
# OO Linux namespace initialization
_ns_exec() {
    local path="$1"
    shift
    local cmd

    # walk through namespace path components
    while [ $# -gt 0 ]; do
        cmd="$1"
        shift

        if [ -d "$path/$cmd" ]; then
            # normal sub-namespace traversal → continue silently
            path="$path/$cmd"
            continue
        fi

        if [ -x "$path/$cmd" ]; then
            # normal execution → silent
            "$path/$cmd" "$@"
            return
        fi

        if [ -f "$path/$cmd" ] && [ ! -x "$path/$cmd" ]; then
            # file exists but not executable → unexpected
            printf '%s [%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "WARN" "$cmd: exists but not executable in $path" >> "$oodir/oo.log"
            echo "$cmd: not executable"
            return 126
        fi

        # command does not exist → unexpected
        printf '%s [%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "WARN" "$cmd: command not found in $path" >> "$oodir/oo.log"
        echo "$cmd: command not found"
        return 127
    done

    # all arguments consumed, path is directory → listing happens normally, silent
    # if we ever reach here in some unexpected state
    if [ ! -d "$path" ]; then
        printf '%s [%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "WARN" "Unexpected termination: path=$path is not a directory" >> "$oodir/oo.log"
        echo "Unexpected error"
        return 2
    fi
}
#
system() { _ns_exec "$lbdir/system" "$@"; }
app()    { _ns_exec "$lbdir/app" "$@"; }
doc()    { _ns_exec "$lbdir/doc" "$@"; }
dev()    { _ns_exec "$lbdir/dev" "$@"; }
net()    { _ns_exec "$lbdir/net" "$@"; }
tool()   { _ns_exec "$lbdir/tool" "$@"; }
info()   { _ns_exec "$lbdir/info" "$@"; }
#
#
ns() {
    local path="$lbdir"

    # walk namespace path
    for part in "$@"; do
        path="$path/$part"
    done

    # unexpected: namespace does not exist
    if [ ! -d "$path" ]; then
        printf '%s [%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "WARN" "ns: namespace not found: $*" >> "$oodir/oo.log"
        echo "ns: namespace not found: $*"
        return 1
    fi

    # top-level call: list only directories (sub-namespaces)
    if [ $# -eq 0 ]; then
        for d in "$path"/*/; do
            [ -d "$d" ] || continue
            system basename "$d"
        done
        return
    fi

    # inside namespace: list everything (dirs + commands)
    for item in "$path"/*; do
        [ -e "$item" ] || continue
        system basename "$item"
    done
}
#
shell() {
    local cmd="$1"; shift
    if [ "$cmd" = "-h" ] || [ "$cmd" = "--help" ]; then
        cat <<EOF
Usage: builtin [OPTIONS] COMMAND [ARGS...]
Options:
  -h, --help    Show this help
  -l, --list    List all Bash builtins
EOF
        return 0
    fi

    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        compgen -b
        return 0
    fi

    if [ "$(type -t "$cmd")" = "builtin" ]; then
        builtin "$cmd" "$@"
    else
        echo "builtin: '$cmd' is not a shell builtin"
        return 1
    fi
}
#
fallback() {
    cmd="$1"
    shift
    if [ -x "$bdir/$cmd" ]; then
        "$bdir/$cmd" "$@"
    else
        echo "fallback: '$cmd' not found"
        return 1
    fi
}
#
# deterministic, minimal-logging completion
_ns_complete() {
    local ns_name="$1"
    local ns_path="$lbdir/$ns_name"

    # unexpected: namespace missing
    if [ ! -d "$ns_path" ]; then
        printf '%s [%s] %s\n' "$(date '+%Y-%m-%d %H:%M:%S')" "WARN" "completion: namespace not found: $ns_name" >> "$oodir/oo.log"
        return
    fi

    # list only executables and subdirectories for completion
    local items=()
    for item in "$ns_path"/*; do
        [ -e "$item" ] || continue
        items+=("$(system basename "$item")")
    done

    # feed completion
    COMPREPLY=("${items[@]}")
}

# register completions for all namespaces dynamically
for ns_dir in "$lbdir"/*/; do
    [ -d "$ns_dir" ] || continue
    ns_name=$(system basename "$ns_dir")
    complete -F _ns_complete "$ns_name"
done
#
# run this on git repo folders:
# git remote set-url origin git@github.com:BitNibble/<repo>.git
#
#
