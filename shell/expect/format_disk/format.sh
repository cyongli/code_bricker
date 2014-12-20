#!/bin/bash
for x in {b..m}
do
	./exec.format.sh "/dev/sd$x"
done

