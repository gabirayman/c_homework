#include "NumClass.h"

int isPrime(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2){
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for(int i = 3; i < n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int isStrong(int n) {
    // factorials holds the factorials of 0-9 so not needed to calculate every time
    int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sum = 0;
    int solution = n;
    while (n>0) {
        int digit = n % 10;
        sum += factorials[digit];
        n = n/10;
    }
    return (sum == solution);
}