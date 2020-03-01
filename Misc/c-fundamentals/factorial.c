/* A program that takes an int and returns the factorial of the given number. */

// 1, 1, 2, 6, 24, 120, 720, 5040
// n! = n * (n -1) * (n - 2) ( n - 3) * ... * 3 * 2 * 1

// Note:
// 0! = 1
#include<stdio.h>

/* Returns the factorial of n */
unsigned int factorial(unsigned int n);

unsigned int factorial(unsigned int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
