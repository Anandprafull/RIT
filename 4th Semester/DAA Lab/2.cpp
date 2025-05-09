#include <chrono>
#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

void bubbleSort(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; ++i) {
    for (int j = 0; j < arr.size() - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Iterative Linear Search
int iterativeSearch(const vector<int> &arr, int target) {
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

// Recursive Linear Search
int recursiveSearch(const vector<int> &arr, int target, int index = 0) {
  if (index >= arr.size()) {
    return -1;
  }
  if (arr[index] == target) {
    return index;
  }
  return recursiveSearch(arr, target, index + 1);
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

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
int recursiveBinarySearch(const vector<int> &arr, int target, int left, int right) {
  if (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return mid;
    }
    if (arr[mid] < target) {
      return recursiveBinarySearch(arr, target, mid + 1, right);
    } else {
      return recursiveBinarySearch(arr, target, left, mid - 1);
    }
  }
  return -1;
}

int main() {
  vector<int> array = {22, 31, 45,1089,689, 10, 40,98};
  int target = 10;


  // Linear Search - Iterative
  auto startIterLin = chrono::high_resolution_clock::now();
  int iterLinResult = iterativeSearch(array, target);
  auto endIterLin = chrono::high_resolution_clock::now();
  auto iterLinTime = chrono::duration_cast<chrono::nanoseconds>(endIterLin - startIterLin);

  // Linear Search - Recursive
  auto startRecLin = chrono::high_resolution_clock::now();
  int recLinResult = recursiveSearch(array, target);
  auto endRecLin = chrono::high_resolution_clock::now();
  auto recLinTime = chrono::duration_cast<chrono::nanoseconds>(endRecLin - startRecLin);

  
  // Binary Search - Iterative
  auto startIterBin = chrono::high_resolution_clock::now();
  bubbleSort(array);
  int iterBinResult = iterativeBinarySearch(array, target);
  auto endIterBin = chrono::high_resolution_clock::now();
  auto iterBinTime = chrono::duration_cast<chrono::nanoseconds>(endIterBin - startIterBin);

  // Binary Search - Recursive
  auto startRecBin = chrono::high_resolution_clock::now();
  bubbleSort(array);
  int recBinResult = recursiveBinarySearch(array, target, 0, array.size() - 1);
  auto endRecBin = chrono::high_resolution_clock::now();
  auto recBinTime = chrono::duration_cast<chrono::nanoseconds>(endRecBin - startRecBin);

  cout << fixed << setprecision(9); // Force output in decimal format

  cout << "Iterative Linear Search: Index " << iterLinResult
       << ", Time taken: " << iterLinTime.count() << " nanoseconds\n";

  cout << "Recursive Linear Search: Index " << recLinResult
       << ", Time taken: " << recLinTime.count() << " nanoseconds\n";

  cout << "Iterative Binary Search: Index " << iterBinResult
       << ", Time taken: " << iterBinTime.count() << " nanoseconds\n";

  cout << "Recursive Binary Search: Index " << recBinResult
       << ", Time taken: " << recBinTime.count() << " nanoseconds\n";

  return 0;
}

