#!/bin/bash

# file userCreate.sh
# brief Takes in an input file of email addresses, creates accounts for them,
#   generates random passwords for them, and sends an email to the given address
#   with the generated username and password
# author chronowski
# date 15/10/2020

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
    out=$(echo $line | cut -d "@" -f 1)
    #if [ $? -eq 0 ]; then
    #    ip=$(echo $out | cut -d " " -f 4)
    #    echo $line,$ip
    #else
    #    echo "${line},no DNS record found"
    #fi
    echo $out
done < $f

exit 0