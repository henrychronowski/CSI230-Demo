## 1/Start

I have never touched markdown or done a writeup of this form before so I will try my best to come up with something.

### Goal

Get basic script functionality implemented:

- check for root
- take in filename flag
- usage statement
- iterate through lines in file
- print cut usernames

## 2

All features implemented, no impediments.

### Goal

Implement user creation (and deletion for sanity's sake), with the CSI230 group

- create CSI230 group if it doesn't exist
- create a user with the username given by the file
- assign a known test string password
- put newly created user in CSI230 group
- write a seperate simple script to delete all users in the CSI230 group

### References

- https://www.cyberciti.biz/tips/howto-write-shell-script-to-add-user.html
- https://www.commandlinux.com/man-page/man8/deluser.8.html
- https://raymii.org/s/snippets/OpenSSL_Password_Generator.html
- http://linuxcommand.org/lc3_man_pages/grep1.html

## 3

All features implemented and also implemented random password generation. Figuring out how to set the password was a bit of a roadblock but I think I arrived at a semi-decent method. Probably still not really secure but better than nothing, at least as far as I can tell.

### Goal

Password updating:

- make sure the user has to update their password on login
- if the user already exists, change their password

### References

- https://linux.die.net/man/1/chage
- https://man7.org/linux/man-pages/man1/passwd.1.html
- https://man7.org/linux/man-pages/man8/chpasswd.8.html

## 4

All features implemented. Changing the password for pre-existing accounts was particularly troublesome, and I don't particularly like the way I am doing it since users can view the password in the history. It's encrypted at that point so I don't think it's a huge security risk or anything but I'm not an expert. I went through trying to use 'passwd' and then eventually settled on 'chpasswd' as it was easier. Also, although it's suggested to research the 'chage' command for requiring the user to reset their password upon login I found it easier to use 'passwd --expire' to hard set the user's password as expired rather than find the right combination of password age settings to trigger the automatic reset requirement.

### Goal

Email time:

- send the user an e-mail
- include their initial username/password in the email

### References

- https://wiki.debian.org/sSMTP
- https://mailutils.org/
- https://linuxhint.com/bash_script_send_email/?fbclid=IwAR388v2Zi72ERYuJf66L5F5iBjW46d41CpmtyIMb6NmaXMSdvvCyRqhCPR4

# 5/Review

It took a bit to actually get it to send an email, and the Google credential side was a bit of a pain. Honestly the hardest part was actually figuring out the command syntax since I am either blind or an explanation of it in the documentation for sSMTP or mailutils doesn't exist. I don't think I fully understand exactly how it accesses the email account to send it but it works. I configured it so that the credentials that it uses to send the email are stored in '/etc/ssmtp/ssmtp.config' as I couldn't figure out how to have them entered at runtime. Another thing that gave me a bit of trouble was getting the proper message body due to me continually mixing up and messing up my single and double quotes. Other than those impediments all of the functionality is implemented and running properly.