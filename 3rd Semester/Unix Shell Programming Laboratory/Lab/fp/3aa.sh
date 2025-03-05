#!/bin/bash
for i in $*
do
	if [ -d $i ];
	then
		echo "The largest file is"
		echo `ls -Rl $i | grep "^-" | tr -s ' ' | cut -d ' ' -f 5,8 | sort -n | tail -1 `
	else
		echo "Not a directory"
	fi
done

