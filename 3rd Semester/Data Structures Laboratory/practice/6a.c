#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1; // Base case: element not found
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid; // Element found
    return (arr[mid] > key) ? binarySearch(arr, low, mid - 1, key) : binarySearch(arr, mid + 1, high, key);
}

int main(void) {
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n]; 
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    printf(result == -1 ? "Element not present\n" : "Element present at index %d\n", result);

    return 0;
}