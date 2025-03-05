#!/usr/bin/awk -f

BEGIN {
    print "Removing duplicate lines..."
}

{
    if (!seen[$0]++)  # If line is seen for the first time, store and print
        print $0 >> "out13a.txt"
}

