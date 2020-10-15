#!/bin/bash

# file converter.sh
# brief Takes in an input file and a case, checks if the input is valid, and outputs the given file
#   in the given case
# author chronowski
# date 15/10/2020

usage()
{
    echo "$0 usage: [-f input file] [-c U(upper) or L(lower)]"
    exit 1
}

# Input flag processing
while getopts ":f:c:" options;
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
        c)
            c=${OPTARG}
            if [[ ${c} != "U" && ${c} != "L" ]]; then
                echo "Unrecognized arguments for -c"
                usage
            fi
            ;;
        *)
            usage
            ;;
    esac
done

# Conversion logic
while read line
do
    if [ ${c} == "U" ]; then
        echo $line | tr [:lower:] [:upper:]
    else
        echo $line | tr [:upper:] [:lower:]
    fi
done < $f

exit 0