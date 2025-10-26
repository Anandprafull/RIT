#include<bits/stdc++.h>
using namespace std;

//linearSearchI o(n)
int linSearchI(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

//linearSearchRec o(n)
int linSearchR(int arr[],int n,int key,int idx=0){
    if(idx>=n){
        return -1;
    }
    if(arr[idx]==key){
        return idx;
    }
    return linSearchR(arr,n,key,idx+1);
}

//bubble sort O(n^2) - FIXED
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
//binarySearchI O(logn) - sorted array
int binarySearchI(int arr[],int n,int key){
    int left=0,right=n-1;
    
    while(left <= right){
        int mid=left+(right-left)/2;
        
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Binary Search Recursive - O(log n)
int binarySearchR(int arr[], int left, int right, int key) {
    if(left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if(arr[mid] == key) {
        return mid;
    }
    else if(arr[mid] < key) {
        return binarySearchR(arr, mid + 1, right, key);
    }
    else {
        return binarySearchR(arr, left, mid - 1, key);
    }
}

int main(){
    int arr[]={3,5,6,1,7,9,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key = 1;
    
    cout << "Original array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Searching for: " << key << endl << endl;

    // Linear Search Iterative
    clock_t start1=clock();
    int r1=linSearchI(arr,n,key);
    clock_t end1=clock();
    double t1=double(end1-start1)/CLOCKS_PER_SEC;

    // Linear Search Recursive
    clock_t start2=clock();
    int r2=linSearchR(arr,n,key);
    clock_t end2=clock();
    double t2=double(end2-start2)/CLOCKS_PER_SEC;

    // Sort array for binary search
    bubbleSort(arr,n);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Binary Search Iterative
    clock_t start3=clock();
    int r3=binarySearchI(arr,n,key);
    clock_t end3=clock();
    double t3=double(end3-start3)/CLOCKS_PER_SEC;

    // Binary Search Recursive
    clock_t start4=clock();
    int r4=binarySearchR(arr,0,n-1,key);
    clock_t end4=clock();
    double t4=double(end4-start4)/CLOCKS_PER_SEC;

    // Display results
    cout << "Linear Search Iterative : " << r1 << " | Time: " << t1*1e6 << " μs" << endl;
    cout << "Linear Search Recursive : " << r2 << " | Time: " << t2*1e6 << " μs" << endl;
    cout << "Binary Search Iterative : " << r3 << " | Time: " << t3*1e6 << " μs" << endl;
    cout << "Binary Search Recursive : " << r4 << " | Time: " << t4*1e6 << " μs" << endl;
    return 0;
}