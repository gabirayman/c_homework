#include "NumClass.h"

int isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    int remainder;
    
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder; 
        n /= 10; 
    }

    return original == reversed;
}

int static power(int base, int exp) {
    int sum = 1;
    for (int i = 0; i<exp; i++) {
        sum *= base;
    }
    return sum;
}

int isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int numDigits = 0;
    while (n>0) {
        n = n/10;
        numDigits++;
    }
    n = original;

    while (n>0) {
        int digit = n % 10;
        sum += power(digit,numDigits);
        n = n/10;
    }
    return (original == sum);
}