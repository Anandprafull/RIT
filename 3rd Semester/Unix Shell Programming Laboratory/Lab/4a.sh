#!/bin/bash

# Get the disk usage percentage for the root file system
space_usage=$( df -h / | awk 'NR==2 {print $6}' | sed 's/%//')

# Display system space usage
echo "System space usage: ${space_usage}%"

# Check if space usage is greater than 80%
if [ ${space_usage} -gt 80 ]; then
    echo "Low system space"
    
    # Find files larger than 1GB and list them
    files=$(find / -type f -size +1G -exec ls -lh {} \; 2>/dev/null)
    
    # If any files are found, display them
    if [ -n "$files" ]; then
        echo "$files"
    else
        echo "No files larger than 1GB found"
    fi
else
    echo "System space under control"
fi

