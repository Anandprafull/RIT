#!/usr/bin/awk -f

{
    split($0, arr, "-") # Split input by "-" into the arr array
    day = arr[1]
    month = arr[2]
    year = arr[3]

    # Validate day and month
    if (day < 1 || day > 31 || month < 1 || month > 12) {
        print "Invalid date"
        exit 0
    }

    # Print the day
    print day

    # Print month name based on the value of month
    if (month == 1) {
        print "Jan"
    } else if (month == 2) {
         print "Feb"
    } else if (month == 3) {
        print "March"
    } else if (month == 4) {
        print "April"
    } else if (month == 5) {
        print "May"
    } else if (month == 6) {
        print "Jun"
    } else if (month == 7) {
        print "Jul"
    } else if (month == 8) {
        print "Aug"
    } else if (month == 9) {
        print "Sep"
    } else if (month == 10) {
        print "Oct"
    } else if (month == 11) {
        print "Nov"
    } else if (month == 12) {
        print "Dec"
    }

    # Print the year
    print year
}


