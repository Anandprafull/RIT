#!/bin/bash

space_usage=$(df -h / | awk 'NR==2 {print $6 }' | sed 's/%//')

if [ ${space_usage} -gt 80 ];
then 
	echo "Low system space"
	file=$(find / -type f -size +1G ls -lh {} ; 2>/dev/null)

	if [ -n "$file" ];
	then
		echo "$file"
	else
		echo "no file greter found"
	fi
else
	echo "space under control"
fi
