#include<stdio.h>
#include<time.h>

//Middle school approach  O(min(a,b))

int gcdM(int a, int b){
    int gcd =1;
    for(int i=2;i<=(a<b?a:b);i++){
        while(a%i==0 && b%i==0){
            a/=i;
            b/=i;
            gcd*=i;
        }
        if(a==1 | b==1) break;
    }
    return gcd;
}

//Consecutive integer checking  O(min(a,b))

int gcdC(int a, int b){
    for(int i=(a<b?a:b);i>=1;i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1; 
}

//Iterative Euclid algo    O(log(min(a,b)))

int gcdIe(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

//Recursive Euclid algo     O(log(min(a,b)))

int gcdRe(int a, int b){
    return b==0?a:gcdRe(b,a%b);
}

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);

    clock_t startM = clock();
    int resultM = gcdM(a,b);
    clock_t endM = clock();

    long long timeM = (endM - startM) * 1e9 / CLOCKS_PER_SEC;

    clock_t startC = clock();
    int resultC = gcdC(a, b);
    clock_t endC = clock();

    long long timeC = (endC - startC) * 1e9 / CLOCKS_PER_SEC;

    clock_t startIe = clock();
    int resultIe = gcdIe(a, b);
    clock_t endIe = clock();

    long long timeIe = (endIe - startIe) * 1e9 / CLOCKS_PER_SEC;

    clock_t startRe = clock();
    int resultRe = gcdRe(a, b);
    clock_t endRe = clock();

    long long timeRe = (endRe - startRe) * 1e9 / CLOCKS_PER_SEC;

    printf("GCD using Middle School Approach: %d, Time: %lld ns\n", resultM, timeM);
    printf("GCD using Consecutive Integer Checking: %d, Time: %lld ns\n", resultC, timeC);
    printf("GCD using Iterative Euclid Algorithm: %d, Time: %lld ns\n", resultIe, timeIe);
    printf("GCD using Recursive Euclid Algorithm: %d, Time: %lld ns\n", resultRe, timeRe);
}