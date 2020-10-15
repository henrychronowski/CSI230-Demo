#!/bin/bash

# file hostlookup.sh
# brief 
# author chronowski
# date 15/10/2020

for h in champlain.edu uvm.edu umd.edu doesnotexist.edu
do
    out=$(host -W1 -t A $h)
    if [ $? -eq 0 ]; then
        ip=$(echo $out | cut -d " " -f 4)
        echo $h,$ip
    else
        echo "${h},no DNS record found"
    fi
done