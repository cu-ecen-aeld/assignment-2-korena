#!/usr/bin/env bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Missing file path or string argument"
    exit 1
fi

writefile=$1
str=$2

mkdir -p $(dirname $writefile) || ( echo "Failed to create write file directories"; exit 1 )
echo "$str" > $writefile
