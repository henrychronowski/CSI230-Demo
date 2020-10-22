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