// Program 6 Recursion applications
//  Write recursive functions for the following and demonstrate their use.
//  a) Binary Search
//  b) Tower of Hanoi problem

// #include<stdio.h>
// #include<stdlib.h>

// int binarySearch(int arr[],int low,int high,int key){
//     if(low>high) return -1;
//     int mid=(low+high)/2;
//     if(arr[mid]==key) return mid;

//     return (arr[mid]>key)? (binarySearch(arr,low,mid-1,key)):(binarySearch(arr,mid+1,high,key));
// }

// int main(){
//     int n,x;
//     printf("Enter noof elements: ");
//     scanf("%d",&n);
//     printf("Enter %d elements in sorted order: ",n);
//     int arr[n];
//     for(int i=0;i<n;i++){
//     scanf("%d",&arr[i]);
//     }
//     printf("Enter element to search");
//     scanf("%d",&x);
//     int result=binarySearch(arr,0,n-1,x);
//     return (result==-1)? (printf("Elememt not present"),-1): (printf("Element Present at %d index\n",result),0);
// }

#include<stdio.h>

int step=0;

void ToH(int n,char source,char spare,char dest){
    if(n==1) {
        printf("step %d: Move %d ring from %c to %c\n",++step,n,source,dest);
    }
    else{
        ToH(n-1,source,dest,spare);
        printf("step %d: Move %d ring from %c to %c\n",++step,n,source,dest);
        ToH(n-1,spare,source,dest);
    }
}

int main(){
    int n;
    printf("Enter no of rings:");
    scanf("%d",&n);
    ToH(n,'A','B','C');
    return 0;
}