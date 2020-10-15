#!/bin/bash

# file hostlookup.sh
# brief Takes in an input file of hosts and iterates through the hosts,
#   outputting the associated IP or an error if the host is invalid
# author chronowski
# date 15/10/2020

usage()
{
    echo "$0 usage: [-f input file]"
    exit 1
}

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
    out=$(host -W1 -t A $line)
    if [ $? -eq 0 ]; then
        ip=$(echo $out | cut -d " " -f 4)
        echo $line,$ip
    else
        echo "${line},no DNS record found"
    fi
done < $f

exit 0