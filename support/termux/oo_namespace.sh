#!/data/data/com.termux/files/usr/bin/bash
#
if [ -n "$__OO_NAMESPACE_LOADED" ]; then
    return
fi
__OO_NAMESPACE_LOADED=1
#
# export PATH="/data/data/com.termux/files/usr/local/bin:$PATH"
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
export PATH="$lbdir:$lbdir/app:$lbdir/system:$lbdir/fallback:$lbdir/net:$lbdir/doc:$lbdir/dev:$lbdir/tool:$lbdir/video:$lbdir/audio:$lbdir/image:$lbdir/manager"
#
# OO Linux namespace initialization
ns() {
    if [ -z "$1" ]; then
        # list namespaces (directories)
        for d in "$lbdir"/*/; do
            [ -d "$d" ] && basename "$d"
        done
    else
        # list commands inside namespace
        for f in "$lbdir/$1"/*; do
            [ -f "$f" ] && basename "$f"
        done
    fi
}
#
app() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/app"
        return 0
    fi
    if [ -x "$lbdir/app/$cmd" ]; then
        "$lbdir/app/$cmd" "$@"
    else
        echo "app: command '$cmd' not found"
        return 1
    fi
}
#
system() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/system"
        return 0
    fi
    if [ -x "$lbdir/system/$cmd" ]; then
        "$lbdir/system/$cmd" "$@"
    else
        echo "system: command '$cmd' not found"
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
doc() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/doc"
        return 0
    fi
    if [ -x "$lbdir/doc/$cmd" ]; then
        "$lbdir/doc/$cmd" "$@"
    else
        echo "doc: command '$cmd' not found"
        return 1
    fi
}
#
dev() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/dev"
        return 0
    fi
    if [ -x "$lbdir/dev/$cmd" ]; then
        "$lbdir/dev/$cmd" "$@"
    else
        echo "dev: command '$cmd' not found"
        return 1
    fi
}
#
net() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/net"
        return 0
    fi
    if [ -x "$lbdir/net/$cmd" ]; then
        "$lbdir/net/$cmd" "$@"
    else
        echo "net: command '$cmd' not found"
        return 1
    fi
}
#
tool() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/tool"
        return 0
    fi
    if [ -x "$lbdir/tool/$cmd" ]; then
        "$lbdir/tool/$cmd" "$@"
    else
        echo "tool: command '$cmd' not found"
        return 1
    fi
}
#
video() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/video"
        return 0
    fi
    if [ -x "$lbdir/video/$cmd" ]; then
        "$lbdir/video/$cmd" "$@"
    else
        echo "video: command '$cmd' not found"
        return 1
    fi
}
#
audio() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/audio"
        return 0
    fi
    if [ -x "$lbdir/audio/$cmd" ]; then
        "$lbdir/audio/$cmd" "$@"
    else
        echo "audio: command '$cmd' not found"
        return 1
    fi
}
#
image() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/image"
        return 0
    fi
    if [ -x "$lbdir/image/$cmd" ]; then
        "$lbdir/image/$cmd" "$@"
    else
        echo "image: command '$cmd' not found"
        return 1
    fi
}
#
manager() {
    cmd="$1"
    shift
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        ls "$lbdir/manager"
        return 0
    fi
    if [ -x "$lbdir/manager/$cmd" ]; then
        "$lbdir/manager/$cmd" "$@"
    else
        echo "manager: command '$cmd' not found"
        return 1
    fi
}
#
shell() {
    local cmd="$1"
    shift

    # Help
    if [ "$cmd" = "-h" ] || [ "$cmd" = "--help" ]; then
        cat <<EOF
Usage: builtin [OPTIONS] COMMAND [ARGS...]
Options:
  -h, --help    Show this help
  -l, --list    List all Bash builtins
EOF
        return 0
    fi

    # List
    if [ "$cmd" = "-l" ] || [ "$cmd" = "--list" ]; then
        compgen -b
        return 0
    fi

    # Execute builtin safely
    if [ "$(type -t "$cmd")" = "builtin" ]; then
	    builtin "$cmd" "$@"
    else
	    echo "builtin: '$cmd' is not a shell builtin"
	    return 0
    fi
}
#
#
complete -W "$(find "$lbdir/app" -maxdepth 1 -type f -executable -printf "%f ")" app
complete -W "$(find "$lbdir/system" -maxdepth 1 -type f -executable -printf "%f ")" system
complete -W "$(find "$lbdir/fallback" -maxdepth 1 -type f -executable -printf "%f ")" fallback
complete -W "$(find "$lbdir/doc" -maxdepth 1 -type f -executable -printf "%f ")" doc
complete -W "$(find "$lbdit/dev" -maxdepth 1 -type f -executable -printf "%f ")" dev
complete -W "$(find "$lbdir/net" -maxdepth 1 -type f -executable -printf "%f ")" net
complete -W "$(find "$lbdir/tool" -maxdepth 1 -type f -executable -printf "%f ")" tool
complete -W "$(find "$lbdir/video" -maxdepth 1 -type f -executable -printf "%f ")" video
complete -W "$(find "$lbdir/audio" -maxdepth 1 -type f -executable -printf "%f ")" audio
complete -W "$(find "$lbdir/image" -maxdepth 1 -type f -executable -printf "%f ")" image
complete -W "$(find "$lbdir/manager" -maxdepth 1 -type f -executable -printf "%f ")" manager
#
# run this on git repo folders:
# git remote set-url origin git@github.com:BitNibble/<repo>.git
#
#
