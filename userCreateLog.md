## 1/Start

I have never touched markdown in any significant amount before so aplogies if formatting is off

### Goal

Get basic script functionality implemented:

- check for root
- take in filename flag
- usage statement
- iterate through lines in file
- print cut usernames

## 2

All features implemented, no issues.

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

All features implemented. Changing the password for pre-existing accounts was particularly troublesome, and I don't like the way that I ended up doing it since it echoes the password. It's encrypted at that point so I don't think it's a huge security risk but I'm not an expert. I went through trying to use passwd and then eventually settled on chpasswd as it was easier. Also, although it's suggested to research the chage command for requiring the user to reset their password upon login I found it easier to use the passwd command to hard set the user's password as expired rather than find the right combination of password age settings to trigger the automatic reset requirement.

### Goal

Email time:

- send the user an e-mail
- include their initial username/password in the email