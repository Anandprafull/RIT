#!/usr/bin/awk -f

BEGIN{
	print "Removing duplicate lines..."
}

{
	if(!seen[$0]++)
		print $0 > "out13a.txt"
}
