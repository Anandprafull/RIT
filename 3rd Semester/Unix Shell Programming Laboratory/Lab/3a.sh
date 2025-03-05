#/bin/bash

#Loops through all arguments passed to the script.
for i in $*
do
#Checks if the argument i is a valid directory. The -d flag returns true if i is a directory, and false otherwise.
	if [ -d $i ];
	then
		echo "Large file name size is:"
#lists all the files and directories under the directory $i (including nested subdirectories) with detailed information.
#grep "^-" filters the ls output to include only lines that start with a -, which corresponds to regular files (ignoring directories or special files like symlinks).
#This command compresses multiple spaces between fields into a single space.
#The cut command extracts sections from each line of input.
#-n: Sorts the lines numerically (in this case, based on the file size)
#The tail command is used to output the last part of the input.
		echo `ls -Rl $i | grep "^-" | tr -s ' ' | cut -d ' ' -f 5,8 | sort -n| tail -1`
	else
		echo "Not directory"
	fi
done
