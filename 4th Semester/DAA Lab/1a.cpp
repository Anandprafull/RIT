#include<bits/stdc++.h>
#include <ctime>
using namespace std;

// Method 1: GCD using Middle School
int gcdM(int a, int b) {
    int gcd = 1;
    for (int i = 2; i <= min(a, b); i++) {
        while (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
            gcd *= i;
        }
        if (a == 1 || b == 1) break;
    }
    return gcd;
}

// Method 2: Consecutive integer checking method
int gcdConsecutive(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= min(a,b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// Method 3: Euclidean algorithm (iterative method)
int gcdEuclideanIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Method 4: Euclidean algorithm (Recursive Method)
int gcdEuclideanRecursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcdEuclideanRecursive(b, a % b);
    }
}

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    // GCD using Middle School
    clock_t startM = clock();
    int resultM = gcdM(a, b);
    clock_t endM = clock();
    double timeM = double(endM - startM) / CLOCKS_PER_SEC;

    // GCD using Consecutive Integer Checking
    clock_t startC = clock();
    int resultC = gcdConsecutive(a, b);
    clock_t endC = clock();
    double timeC = double(endC - startC) / CLOCKS_PER_SEC;

    // GCD using Euclidean Algorithm (Iterative)
    clock_t startEI = clock();
    int resultEI = gcdEuclideanIterative(a, b);
    clock_t endEI = clock();
    double timeEI = double(endEI - startEI) / CLOCKS_PER_SEC;

    // GCD using Euclidean Algorithm (Recursive)
    clock_t startER = clock();
    int resultER = gcdEuclideanRecursive(a, b);
    clock_t endER = clock();
    double timeER = double(endER - startER) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(9);
    cout << "GCD using Middle School: " << resultM << ", Time taken: " << timeM << " seconds\n";
    cout << "GCD using Consecutive Integer Checking: " << resultC << ", Time taken: " << timeC << " seconds\n";
    cout << "GCD using Euclidean (Iterative): " << resultEI << ", Time taken: " << timeEI << " seconds\n";
    cout << "GCD using Euclidean (Recursive): " << resultER << ", Time taken: " << timeER << " seconds\n";

    // Additional detailed timing for Euclidean algorithms
    clock_t startEI2 = clock();
    resultEI = gcdEuclideanIterative(a, b);
    clock_t endEI2 = clock();
    double timeEI2 = double(endEI2 - startEI2) / CLOCKS_PER_SEC;

    clock_t startER2 = clock();
    resultER = gcdEuclideanRecursive(a, b);
    clock_t endER2 = clock();
    double timeER2 = double(endER2 - startER2) / CLOCKS_PER_SEC;

    cout << "Detailed Timing:\n";
    cout << "Euclidean (Iterative) 2nd run: " << timeEI2 << " seconds\n";
    cout << "Euclidean (Recursive) 2nd run: " << timeER2 << " seconds\n";

    return 0;
}
