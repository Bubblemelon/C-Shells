/*  A C program that takes a `long int` and calculates the sum of the digits of a number entered.

e.g.
if the user input is 1234,
then the sum is, 1234 = 1+2+3+4 = 10
 */
#include <stdio.h>

int main()
{
    long int input;
    long int result;

    printf("\n*** Sums the Digits in a Number ***\n");

    printf("\nEnter a number: ");
    scanf("%ld", &input);

    while( input > 0){
        result += (input % 10);
        input /= 10;
    }
    printf("The sum of the digits is : %lu\n", result);
    return 0;
}
