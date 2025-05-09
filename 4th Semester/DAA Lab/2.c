#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative Linear Search
int iterativeSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Recursive Linear Search
int recursiveSearch(int arr[], int size, int target, int index) {
    if (index >= size) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return recursiveSearch(arr, size, target, index + 1);
}

// Iterative Binary Search
int iterativeBinarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            return recursiveBinarySearch(arr, mid + 1, right, target);
        } else {
            return recursiveBinarySearch(arr, left, mid - 1, target);
        }
    }
    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 10;

    clock_t start, end;
    double time_taken;

    // Linear Search - Iterative
    start = clock();
    int iterLinResult = iterativeSearch(array, size, target);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iterative Linear Search: Index %d, Time taken: %f seconds\n", iterLinResult, time_taken);

    // Linear Search - Recursive
    start = clock();
    int recLinResult = recursiveSearch(array, size, target, 0);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Linear Search: Index %d, Time taken: %f seconds\n", recLinResult, time_taken);

    // Binary Search - Iterative
    start = clock();
    int iterBinResult = iterativeBinarySearch(array, size, target);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Iterative Binary Search: Index %d, Time taken: %f seconds\n", iterBinResult, time_taken);

    // Binary Search - Recursive
    start = clock();
    int recBinResult = recursiveBinarySearch(array, 0, size - 1, target);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive Binary Search: Index %d, Time taken: %f seconds\n", recBinResult, time_taken);

    return 0;
}
