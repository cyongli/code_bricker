#!/bin/bash

showUsage(){
	echo "Usage:"
	echo -e "\tnew_trust.sh path"
	echo "Note:"
        echo -e "\tpath is the location where .ssh is"
}

if [ $# -lt 1 ] 
then
	echo "Error:no path defined"
	showUsage
	exit
fi

path=$1
stty -echo
echo -n "Enter password:" 
read passwd 
stty echo
echo

./gen_key.exp
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
