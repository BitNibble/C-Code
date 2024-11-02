#!/bin/bash
# author: Sergio Manuel Salazar dos Santos
# sergio.salazar.santos@gmail.com
# mobile: 916919898
# CVS: $Header$
# help improving is always welcome
#####################################################################
set -e # Exit on error
shopt -s -o nounset
# Global declarations
declare -rx SCRIPT=${0##*/}
# Sanity check
if [[ -z "$BASH" ]]; then
    printf "%s: Please run this script with the BASH shell\n" "$SCRIPT" >&2
    exit 192
fi
#####################################################################
RED=1
GREEN=2
declare -a EXTENSIONLIB=(
    asm bmp brd c cpp dll doc docx epub exe gif gz h ini ino jpg jsp
    mp3 msi ods odt pdb pde pdf png pps ppt ps rar sch sh spq svg txt
    vsd wxm xls xlsx xps zip pdn iso
)

echo "$(tput setaf $GREEN)--------------------------------------------------------------------------$(tput sgr0)"
# preset
IFS_OLD="$IFS"
IFS=$'\0'

# function to handle directory input
resolve_path() {
    local path="$1"
    if [[ "$path" == "." ]]; then
        echo "$(pwd)"
    elif [[ "$path" == ".." ]]; then
        echo "${PWD%/*}"
    else
        echo "$path"
    fi
}

# function exit on interrupt catch
control_c() {
    # Cleanup
    IFS="$IFS_OLD"
    exit # all is well
}
trap control_c SIGINT

TIMESTAMP=$(date +"%Y:%m:%d-%H:%M:%S")
echo "$(tput setaf $GREEN)INICIO $TIMESTAMP$(tput sgr0)"
echo "$(tput setaf $GREEN)--------------------------------------------------------------------------$(tput sgr0)"

# filter
if (( $# != 2 )); then
    echo "Usage: $0 SOURCE LOCATION"
    echo "PARAMETER MISSING !!!"
    exit
fi

SOURCEVAR="$1"
LOCATIONVAR="$2"
SOURCE=$(resolve_path "$SOURCEVAR")
LOCATION=$(resolve_path "$LOCATIONVAR")

FOLDER=$(basename "$SOURCE")
if [[ ! -d $SOURCE ]]; then
    echo "Folder «$SOURCE» does not exist!"
    exit
else
    echo "Confirmed «$FOLDER»"
fi

FOLDER=$(basename "$LOCATION")
if [[ ! -d $LOCATION ]]; then
    echo "Folder «$LOCATION» does not exist!"
    exit
else
    echo "Confirmed «$FOLDER»"
fi

echo "-----BACKUP-----"
echo "Source: $SOURCE"
echo "Destination: $LOCATION"

# make sure you want to proceed
read -p "Press [Enter] key to start"

echo "CYCLE START"
for extension in "${EXTENSIONLIB[@]}"; do
    echo "$(tput setaf $RED)$extension$(tput sgr0)"
    LOCATIONPATH="$LOCATION/${extension^^}ALL"
    mkdir -pv "$LOCATIONPATH" || {
        echo "Failed to create directory: $LOCATIONPATH" >&2
        continue
    }
    
    # Check if there are any files to copy
    if find "$SOURCE" -iname "*.$extension" -type f | grep -q .; then
        find "$SOURCE" -iname "*.$extension" -type f -print0 | xargs -0 cp --verbose --update --target-directory="$LOCATIONPATH"
    else
        echo "No files found for extension: $extension"
    fi
done

echo "CYCLE END"
TIMESTAMP=$(date +"%Y:%m:%d-%H:%M:%S")
# Cleanup
IFS="$IFS_OLD"
exit # all is well
