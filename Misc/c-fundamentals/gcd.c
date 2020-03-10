/*  Write a C program that takes two positive int and calculates their greatest common divisor, as specified in the example below:

e.g.
Enter the first number : 100
Enter the second number : 150
The greatest common divisor of 100 and 150 is 50.
 */
#include <stdio.h>

int main()
{
    int num1, num2, result;

    printf("\n*** Greatest Common Divisor between Two Values ***\n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    for(int i=1; i <= num1 && i <= num2; ++i)
    {
        // both numbers must share the same divisible factor
        if(num1 % i == 0 && num2 % i == 0)
            result = i;
    }

    printf("The greatest common divisor of %d and %d is %d.\n", num1, num2, result);

    return 0;
}