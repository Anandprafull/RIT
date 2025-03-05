#!/usr/bin/awk -f 
BEGIN { 
    print "Removing duplicated lines..." 
    no = 0 
} 
 
{ 
    line[++no] = $0  # Store the current line in the array and increment the counter 
   } 
END { 
    for (i = 1; i <= no; i++) { 
        flag = 1  # Assume the line is unique 
        for (j = 1; j < i; j++) { 
            if (line[i] == line[j]) { 
                flag = 0  # Found a duplicate 
                break;    # No need to check further 
            } 
        } 
        if (flag == 1) { 
            print line[i] >> "out13a.txt"  # Print unique line to the output file 
        } 
    } 
} 
