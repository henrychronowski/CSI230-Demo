#!/bin/bash

# file delUser.sh
# brief Deletes all users with usernames in the given file
# author chronowski
# date 22/10/2020

usage()
{
    echo "$0 usage: [-f input file]"
    exit 1
}

if ! [ "$(id -u)" = "0" ]; then
    echo "Must Run as Root"
    usage
fi

# input flag processing
while getopts ":f:" options;
do
    case "${options}" in
        f)
            f=${OPTARG}
            test -r "${f}"
            if [ $? -ne 0 ]; then
                echo "Invalid input file"
                usage
            fi
            ;;
        *)
            usage
            ;;
    esac
done

# Script logic
while read line
do
    username=$(echo $line | cut -d "@" -f 1)
    deluser --remove-home $username
done < $f

exit 0