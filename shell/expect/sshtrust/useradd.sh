#!/bin/bash

stty -echo
echo -n "Enter password:" 
read word 
stty echo
echo
passwd=$(perl -e 'print crypt($ARGV[0], "wtf")' "$word")
useradd -d /home/chaoyli -p $passwd chaoyli
