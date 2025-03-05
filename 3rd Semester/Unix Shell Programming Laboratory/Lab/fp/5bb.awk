#!/usr/bin/awk -f
BEGIN {
	print "Removing Duplicate lines"
	no=0
      }
      {
	      arr[++no]=$0
	      
      }
END {
	      for(i=1;i<=no;i++){
		      flag=1
		      for(j=1;j<i;j++){
			      if(arr[i] == arr[j]){
				      flag=0
				      break;
			      }
		      }
		      if(flag==1){
			      print arr[i] >> "out13a.txt"
		      }
	      
	 }
 }

