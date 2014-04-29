#!/bin/bash

passwd=$(perl -e 'print crypt($ARGV[0], "wtf")' "chaoyli")
useradd -d /home/chaoyli -p $passwd chaoyli
