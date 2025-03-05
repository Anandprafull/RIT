#!/usr/bin/awk -f
{
	split($0,arr,"-")
	day=arr[1]
	month=arr[2]
	year=arr[3]

	if( day<1 || day>31 || month<1 || month>12 ){
		print "Invalid date"
		exit(0)
	}
	print day

	if(month==1){print "Jan"}
	else if(month==2){print "Feb"}
		else if(month==3){print "Mar"}
		else if(month==4){print "APr"}
		else if(month==5){print "May"}

		print year
	}
