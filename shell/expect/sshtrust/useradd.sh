#!/bin/bash

showUsage(){
	echo "Usage:"
	echo -e "\tuseradd.sh username"
}

if [ $# -lt 1 ]
then
	echo "Error:no path defined"
	showUsage
	exit
fi

username=$1
stty -echo
echo -n "Enter password:" 
read word 
stty echo
echo
passwd=$(perl -e 'print crypt($ARGV[0], "wtf")' "$word")
for host in $(cat hosts)
do
	ssh $host useradd -d /home/$username -p $passwd $username
done
