#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// Method 1: GCD using Middle School
int gcdM(int a, int b) {
    int gcd = 1;
    for (int factor = 2; factor <= min(a, b); factor++) {
        while (a % factor == 0 && b % factor == 0) {
            a /= factor;
            b /= factor;
            gcd *= factor;
        }
        if (a == 1 || b == 1) break;
    }
    return gcd;
}

// Method 2: Consecutive integer checking method
int gcdConsecutive(int a, int b) {
    int gcd = 1;
    int limit = min(a, b);
    for (int i = 1; i <= limit; i++) {
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
    auto startM = high_resolution_clock::now();
    int resultM = gcdM(a, b);
    auto endM = high_resolution_clock::now();
    auto timeM = duration_cast<nanoseconds>(endM - startM);

    // GCD using Consecutive Integer Checking
    auto startC = high_resolution_clock::now();
    int resultC = gcdConsecutive(a, b);
    auto endC = high_resolution_clock::now();
    auto timeC = duration_cast<nanoseconds>(endC - startC);

    // GCD using Euclidean Algorithm (Iterative)
    auto startEI = high_resolution_clock::now();
    int resultEI = gcdEuclideanIterative(a, b);
    auto endEI = high_resolution_clock::now();
    auto timeEI = duration_cast<nanoseconds>(endEI - startEI);

    // GCD using Euclidean Algorithm (Recursive)
    auto startER = high_resolution_clock::now();
    int resultER = gcdEuclideanRecursive(a, b);
    auto endER = high_resolution_clock::now();
    auto timeER = duration_cast<nanoseconds>(endER - startER);

    cout << fixed << setprecision(9);
    cout << "GCD using Middle School: " << resultM << ", Time taken: " << timeM.count() << " nanoseconds\n";
    cout << "GCD using Consecutive Integer Checking: " << resultC << ", Time taken: " << timeC.count() << " nanoseconds\n";
    cout << "GCD using Euclidean (Iterative): " << resultEI << ", Time taken: " << timeEI.count() << " nanoseconds\n";
    cout << "GCD using Euclidean (Recursive): " << resultER << ", Time taken: " << timeER.count() << " nanoseconds\n";

    // Additional detailed timing for Euclidean algorithms
    auto startEI2 = high_resolution_clock::now();
    resultEI = gcdEuclideanIterative(a, b);
    auto endEI2 = high_resolution_clock::now();
    auto timeEI2 = duration_cast<nanoseconds>(endEI2 - startEI2);

    auto startER2 = high_resolution_clock::now();
    resultER = gcdEuclideanRecursive(a, b);
    auto endER2 = high_resolution_clock::now();
    auto timeER2 = duration_cast<nanoseconds>(endER2 - startER2);

    cout << "Detailed Timing:\n";
    cout << "Euclidean (Iterative) 2nd run: " << timeEI2.count() << " nanoseconds\n";
    cout << "Euclidean (Recursive) 2nd run: " << timeER2.count() << " nanoseconds\n";

    return 0;
}
