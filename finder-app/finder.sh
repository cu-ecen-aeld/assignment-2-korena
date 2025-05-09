#!/usr/bin/env bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Missing filesdir or searchstr argument"
    exit 1
fi


if [ ! -d "$1" ]; then
    echo "filesdir is not a directory"
    exit 1
fi

filesdir=$1
searchstr=$2

# number of files in the directory and all subdirectories
files_num=$(find "$filesdir" -type f | wc -l)

# number of matching lines found in respective files
match_num=$(grep -ri "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $files_num and the number of matching lines are $match_num"
