#!/bin/bash
if [ $# -eq 0 ];
then
	echo "File doesnot exist"
else
	ls -l $1 >t2
	x=`cut -d ' ' -f 1,6,7,8,9 t2`
	echo $x
fi
	
