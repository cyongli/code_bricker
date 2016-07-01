#!/bin/bash

showUsage(){
	echo "Usage:"
	echo -e "\tuseradd.sh username"
}

username=$1
stty -echo
echo -n "Enter password:" 
read word 
stty echo
echo
passwd=$(perl -e 'print crypt($ARGV[0], "wtf")' "$word")
useradd -d /home/$username -p $passwd $username
