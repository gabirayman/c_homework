#include "NumClass.h"

int isPalindromeHelper(int n, int backwards) {
    if (n == 0) {
        return backwards;
    }
    backwards = (10 * backwards) + (n % 10);
    return isPalindromeHelper(n/10,backwards);
}

int isPalindrome(int n) {
    return n == isPalindromeHelper(n,0);
}

int static countDigits(int n, int count) {
    if (n==0) {
        return count;
    }
    count++;
    return countDigits(n/10,count);    
}

int static power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * power(base, exp-1);
}

int static isArmstrongHelper(int n, int exp) {
    if (n == 0) {
        return 0;
    }
    return power(n % 10, exp) + isArmstrongHelper(n/10,exp);
}

int isArmstrong(int n) {
    int exp = countDigits(n,0);
    return n == isArmstrongHelper(n, exp);
}