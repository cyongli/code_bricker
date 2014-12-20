#!/bin/bash

showUsage(){
	echo "Usage:"
	echo -e "\ttrust.sh path  passwd"
	echo "Note:"
        echo -e "\tpath is the location where .ssh is"
	echo -e "\tpasswd is password of current user"
}

if [ $# -lt 1 ] 
then
	echo "Error:no path or passwd defined"
	showUsage
	exit
fi

path=$1
passwd=$2
./gen_key.exp $passwd
cat $path/.ssh/id_rsa.pub >> $path/.ssh/authorized_keys
chmod 600 $path/.ssh/authorized_keys

for host in `cat hosts`
do
   if [ $host != `hostname` ]
   then
      ./emit_yes.exp $host $passwd
   fi
done

for host in `cat hosts`
do
   if [ $host != `hostname` ]
   then
      ./scp_trust.exp $path $host $passwd 
   fi
done