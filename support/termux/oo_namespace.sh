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
export PATH="$lbdir"
# export PATH="$lbdir/system:$lbdir/app:$lbdir/doc:$lbdir/dev:$lbdir/net:$lbdir/tool":$PATH
export PATH="$lbdir/info":$PATH
#
# OO Linux namespace initialization
_ns_exec() {
    local ns_dir="$1"; shift
    local cmd="$1"; shift

    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$ns_dir"
        return 0
    fi

    if [ -x "$ns_dir/$cmd" ]; then
        "$ns_dir/$cmd" "$@"
    else
        echo "$cmd: command not found in $ns_dir"
        return 1
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
# export -f system
#
ns() {
    if [ -z "$1" ]; then
        # list namespaces (directories)
        for d in "$lbdir"/*/; do
            [ -d "$d" ] && system basename "$d"
        done
    else
        # list commands inside namespace
        for f in "$lbdir/$1"/*; do
            [ -f "$f" ] && system basename "$f"
        done
    fi
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
for ns in system app doc dev net tool info; do
    complete -W "$(system find "$lbdir/$ns" -maxdepth 1 \( -type f -o -type l \) -executable -printf "%f\n")" $ns
done
#
# run this on git repo folders:
# git remote set-url origin git@github.com:BitNibble/<repo>.git
#
#
