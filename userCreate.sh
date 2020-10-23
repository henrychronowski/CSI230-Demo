#!/bin/bash

# file userCreate.sh
# brief Takes in an input file of email addresses, creates accounts for them,
#   generates random passwords for them, and sends an email to the given address
#   with the generated username and password
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


# Check for group existence, create if it doesn't already exist
if grep -q $GROUP /etc/group
    then
        echo "CSI230 group exists"
    else
        echo "Creating CSI230 group"
        groupadd CSI230
fi

# Read in addresses from file and process them
while read line
do
    username=$(echo $line | cut -d "@" -f 1)
    password=$(openssl rand -base64 20)
    echo $password
    epass=$(perl -e 'print crypt($ARGV[0], "password")' $password)
    useradd -s /bin/bash -G CSI230 -p $epass $username

    # Checks to see if useradd returned the code for a pre-existing user
    if [ $? -eq 9 ]; then
        echo "$username:$epass" | chpasswd -e
        echo "$username password updated"
        mail -s 'Account Password Reset' $line <<< "Your account with username $username has had its password reset to the one-time password $password. Please log in and set a new password."
    else
        echo "$username account created"
        mail -s 'Account Created' $line <<< "Your account with username $username has been created with one-time password $password. Please log in and set a new password."
    fi

    # Set the password to expire in order to force one-time use
    passwd -q --expire $username
    
done < $f

exit 0