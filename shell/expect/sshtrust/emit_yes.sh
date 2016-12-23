#!/bin/bash

for host in `cat hosts`
do
   if [ $host != `hostname` ]
   then
      ./emit_yes.exp $host passwd
   fi
done
