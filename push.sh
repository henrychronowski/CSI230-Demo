#!/bin/bash

# file push.sh
# brief used to push apache content to a remote server using rsync, based on demonstrated script
# author chronowski
# Lab 9, Scheduled Tasks
# date 11/3/2020

#Constants
AWSHOST="ec2-54-235-58-174.compute-1.amazonaws.com"
AWSUSER="push-web"
LOCALDIR="web-content"
KEYPATH="keys/push-web"
ADDRESS="henry.chronowski@mymail.champlain.edu"

#Change to working directory
cd /root/cron-lab

#Rsync
rsync -e "ssh -i ${KEYPATH}" -vra0 --no-perms --delete --chmod=660 --chown=push-web:www-data "${LOCALDIR}/" "${AWSUSER}@${AWSHOST}":

# Write an entry to syslog and send an email
logger -t $0 "apache content pushed to ${AWSHOST}"
mail -s 'Apache content pushed' ${ADDRESS} <<< "Apache content has been pushed to ${AWSHOST}"