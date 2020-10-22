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

# constants
GROUP="CSI230"
RIGHT_NOW=$(date)

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
if grep -q $GROUP /etc/group
    then
        echo "CSI230 group exists"
    else
        echo "Creating CSI230 group"
        groupadd CSI230
fi

while read line
do
    username=$(echo $line | cut -d "@" -f 1)
    password=$(openssl rand -base64 20)
    echo $password
    epass=$(perl -e 'print crypt($ARGV[0], "password")' $password)
    useradd -s /bin/bash -G CSI230 -p $epass $username
    if [ $? -eq 9 ]; then
        echo "$username:$epass" | chpasswd -e
        echo "$username password updated"
    else
        echo "$username account created"
    fi
    passwd -q --expire $username
    
done < $f

exit 0