#!/bin/bash
file_name="example.txt"

if [ -e "$file_name" ]
then
	echo "File '$file_name' exists"
	mv "$file_name" "${file_name}_old"
	echo "File name changed to '${file_name}_old'"
	touch "$file_name"
	echo "New empty file created with name '$file_name'"
	echo "Both conditions done together"
else
	touch "$file_name"
	echo "File '$file_name' does not exist. New empty file created."
fi

