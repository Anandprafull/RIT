#!/bin/bash
file_name="example.txt"

if [ -e "$file_name" ]
then

	echo "File exist"
	mv "$file_name" "${file_name}_old"
	echo "file renamed to '${file_name}_old'."
	touch '$filename'
	echo "Empty new File created with name '${file_name}'"
else
	echo "File does not exist"
	touch "${file_name}"
	echo "New Empty file '${file_name}' created"
fi

