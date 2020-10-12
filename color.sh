#!/bin/bash

# file color.sh
# brief Script that takes user input of a color and if the color is one of the options
#   prints text in that color
# author chronowski
# date 12/10/2020

red='\033[0;31m'
green='\033[0;32m'
yellow='\033[0;33m'
blue='\033[0;34m'
magenta='\033[0;35m'
default='\033[0m'

read -p "What is your favorite color (red, green, blue, yellow, or magenta)? " color
color=${color^^}

case ${color} in
"RED")
    selected_color=$blue
    ;;
"GREEN")
    selected_color=$green
    ;;
"YELLOW")
    selected_color=$yellow
    ;;
"BLUE")
    selected_color=$blue
    ;;
"MAGENTA")
    selected_color=$magenta
    ;;
*)
    echo "You didn't enter anything!"
    exit 1
    ;;
esac

echo -e "${selected_color}Your selected color is ${color}${default}"

exit 0