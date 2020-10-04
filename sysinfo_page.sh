#!/bin/bash

# file sysinfo_page.sh
# brief Script that displays system information as an html page
# author chronowski
# date 04/10/2020

if ! [ "$(id -u)" = "0" ]; then
    echo "Must Run as Root"
    exit 1
fi

# variables
TITLE="System Information for $HOSTNAME"
RIGHT_NOW="$(date +"%x %r %Z")"
TIME_STAMP="Updated on $RIGHT_NOW by $USER"


# functions

# brief basic system information
system_info()
{
    if ls /etc/*release 1>/dev/null 2>&1; then
        echo "<h2>System release info</h2>"
        echo "<pre>"
        for i in /etc/*release; do
            head -n 1 "$i"
        done
        uname -orp
        echo "</pre>"
    fi
}

# brief shows system uptime
show_uptime()
{
    echo "<h2>System uptime</h2>"
    echo "<pre>"
    uptime
    echo "</pre>"
}

# brief shows system primary IP
show_IP()
{
    echo "<h2>System's primary IP</h2>"
    echo "<pre>"
    hostname -I
    echo "</pre>"
}

# brief shows free memory, physical and swap
show_mem() 
{
    echo "<h2>System free memory</h2>"
    echo "<pre>"
    free -h -w -t
    echo "</pre>"
}

# brief shows filesystem space
drive_space()
{
    echo "<h2>Filesystem space</h2>"
    echo "<pre>"
    df -h -T
    echo "</pre>"
}

# brief shows each shell user and their groups
show_users()
{
    echo "<h2>Shell users and their groups</h2>"
    echo "<pre>"
    #cat /etc/passwd | grep bash |  cut -d: -f1
    for user in "$(cat /etc/passwd | grep bash |  cut -d: -f1)"; do groups $user; done
    echo "</pre>"
}

# brief shows log of user logins
show_logins()
{
    echo "<h2>Log of user logins"
    echo "<pre>"
    last -a -i -w -F | grep -v "reboot"
    echo "</pre>"
}

# brief shows home directory space sorted by user
home_space()
{
    echo "<h2>Home directory space by user</h2>"
    echo "<pre>"
    du -s /home/* | sort -nr
    echo "</pre>"
}

# brief writes page
write_page()
{
    cat << _EOF_
<html>
<head>
    <title>$TITLE</title>
</head>

<body>
    <h1>$TITLE</h1>
    <p>$TIME_STAMP</p>
    $(system_info)
    $(show_IP)
    $(show_uptime)
    $(show_mem)
    $(drive_space)
    $(show_users)
    $(home_space)
    $(show_logins)
</body>
</html>
_EOF_
}

# brief displays script usage
usage() 
{
    echo "usage: sysinfo_page [[[-f file] [-i]] | [-h]]"
}


# main
interactive=
filename=~/sysinfo_page.html

while [ "$1" != "" ]; do
    case $1 in
        -f | --file )           shift
                                filename="$1"
                                ;;
        -i | --interactive )    interactive=1
                                ;;
        -h | --help )           usage
                                exit 1
                                ;;
        * )                     usage
                                exit 1
    esac
    shift
done

if [ "$interactive" = "1" ]; then
    response=

    read -p "Enter name of output file [$filename] > " response
    if [ -n "$response" ]; then
        filename="$response"
    fi

    if [ -f $filename ]; then
        echo -n "Output file exists. Overwrite? (y/n) > "
        read response
        if [ "$response" != "y" ]; then
            echo "Exiting program."
            exit 1
        fi
    fi
fi

write_page > $filename

exit 0