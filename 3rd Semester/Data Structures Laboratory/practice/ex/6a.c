//  Program 6 Recursion applications
//  Write recursive functions for the following and demonstrate their use.
//  a) Binary Search
//  b) Tower of Hanoi problem

// #include<stdio.h>

// int binarySearch(int arr[],int low, int high, int key){
//     if(low>high) return -1;
//     int mid=(high+low)/2;
//     if (arr[mid]==key) return mid;

//     return (arr[mid]>key) ? binarySearch(arr,low,mid-1,key): binarySearch(arr,mid+1,high,key);
// }

// int main(){
//     int n, x;
//     printf("Enter no of elements: ");
//     scanf("%d",&n);
//     int arr[n];
//     printf("Enter %d elements in sorted order",n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     printf("Enter the element to serach: ");
//     scanf("%d",&x);

//     int result=binarySearch(arr,0,n-1,x);
//     return (result ==-1) ? (printf("Element Not Present")) : (printf("ELement present at index %d",result));
// }

#include<stdio.h>

 int step=0;

void ToH(int n, char source, char spare, char destination){
    if(n==1){
        printf("\n Step %d: Move disk %d from %c to %c",++step,n,source,destination);
    }
    else{
        ToH(n-1,source,destination,spare);
        printf("\n Step %d: Move disk %d from %c to %c",++step,n,source,destination);
        ToH(n-1,spare,source,destination);
    }
}

int main(){
    int n;
    printf("Enter no of rings: ");
    scanf("%d",&n);
    ToH(n,'A','B','C');
    return 0;
}