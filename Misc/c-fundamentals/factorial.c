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

int main()
{
    unsigned int input;
    unsigned int result = 1;

    printf("\n*** Factorial Calculator ***\n");

    // assumes positive integers
    printf("\nEnter a number: ");
    scanf("%u", &input);

    printf("\n%u! using recursion: %d", input, factorial(input));

    for(int i = 2; i <= input; i++){

        result *= i;
    }

    printf("\n%u! using a for-loop: %d\n", input, result);

    return 0;
}