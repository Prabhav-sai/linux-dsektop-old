I used a form in html that sends input through post to flask server

it takes input and assigns it to user directory that i am converting to json before printing it to users.txt file

Next I am taking data from users.txt and comparing it with user id to check if it exists before printing output

I am assuming that we will only be using this password for verifying password in login, hence hashing is more appropriate , i will hash the password while taking input and compare if i have to implement login kind of thing