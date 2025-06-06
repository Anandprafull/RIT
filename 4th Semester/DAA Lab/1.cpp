#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

/*
Middle School Procedure
1. Input 2 numbers a & b
2. Find all divisors of a & b
3. Identify common divisors between the sets
4. Return the largest common divisor
*/

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
    for (int i = min(a, b); i >= 1; i--) {
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
    return b == 0 ? a : gcdEuclideanRecursive(b, a % b);
}

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    // GCD using Middle School
    auto start = high_resolution_clock::now();
    cout << "GCD using Middle School: " << gcdM(a, b) << endl;
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<microseconds>(end - start).count();
    cout << "Time taken: " << time_taken << " microseconds\n\n";

    // GCD using Consecutive Integer Checking
    start = high_resolution_clock::now();
    cout << "GCD using consecutive integer checking: " << gcdConsecutive(a, b) << endl;
    end = high_resolution_clock::now();
    time_taken = duration_cast<microseconds>(end - start).count();
    cout << "Time taken: " << time_taken << " microseconds\n\n";

    // GCD using Euclidean Algorithm (Iterative)
    start = high_resolution_clock::now();
    cout << "GCD using Euclidean algorithm (Iterative): " << gcdEuclideanIterative(a, b) << endl;
    end = high_resolution_clock::now();
    time_taken = duration_cast<microseconds>(end - start).count();
    cout << "Time taken: " << time_taken << " microseconds\n\n";

    // GCD using Euclidean Algorithm (Recursive)
    start = high_resolution_clock::now();
    cout << "GCD using Euclidean algorithm (Recursive): " << gcdEuclideanRecursive(a, b) << endl;
    end = high_resolution_clock::now();
    time_taken = duration_cast<microseconds>(end - start).count();
    cout << "Time taken: " << time_taken << " microseconds\n\n";

    return 0;
}

