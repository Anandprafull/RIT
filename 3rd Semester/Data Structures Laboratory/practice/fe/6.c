// #include<stdio.h>
// #include<stdlib.h>

// int  binarySearch(int arr[],int low, int high, int key){
// 	if(low>high) return -1;
// 	int mid=(low+high)/2;
// 	if(arr[mid]==key) return mid;
// 	return (arr[mid]>key)? (binarySearch(arr,low,mid-1,key)): (binarySearch(arr,mid+1,high,key));
// }

// int main(){
// 	int n,x;
// 	printf("Enter the size of array: ");
// 	scanf("%d",&n);
// 	int arr[n];
// 	printf("Enter array elements in sorted manner:");
// 	for(int i=0;i<n;i++){
// 		scanf("%d",&arr[i]);
// 	}
// 	printf("Enter element to search: ");
// 	scanf("%d",&x);
// 	int result=binarySearch(arr,0,n-1,x);
// 	return (result!=-1)? (printf("Element %d present at index %d\n ",x,result)): (printf("Element not found"));
// }
#include<stdio.h>
#include<stdlib.h>

int step=0;

void ToH(int n, char source, char spare, char dest){
	if(n==1){
		printf("Step %d: Move Disk %d from %c to %c\n",++step,n,source,dest);
	}
	else{
		ToH(n-1,source,dest,spare);
		printf("Step %d: Move disk %d from %c to %c\n",++step,n,source,dest);
		ToH(n-1,spare,source,dest);
	}
}

int main(){
	int n;
	printf("Enter no of disks: ");
	scanf("%d",&n);
	ToH(n,'A','B','C');
	return 0;
}


