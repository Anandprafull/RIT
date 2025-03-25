#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip> // Include iomanip for setting precision
using namespace std;

// Function to find the median-of-three pivot
int medianOfThree(vector<int> &arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    return mid; // Returning index instead of value
}

// Partition function using median-of-three
int partition(vector<int> &arr, int left, int right) {
    int medianIndex = medianOfThree(arr, left, right);
    int pivot = arr[medianIndex];
    swap(arr[medianIndex], arr[right]); // Move pivot to end

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]); // Move pivot to correct place
    return i + 1;
}

// QuickSort implementation
void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main() {
    int n = 5; 
    vector<int> arr = {9,2,6,1,4}; 

    clock_t start_time = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_time = clock();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double cpu_time = (double(end_time - start_time) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds
    cout << fixed << setprecision(9); // Set precision to 9 digits
    cout << "Time taken: " << cpu_time << " microseconds\n";

    return 0;
}
