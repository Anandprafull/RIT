#!/bin/bash

for i in $(seq 1 10);
do
	mkdir "$i"
done

for dir in $(find . -maxdepth 1 -type d);
do
	for j in $(seq -f "%003g" 1 10);
	do
		touch "$dir/name_date.txt_$j"
	done
done
