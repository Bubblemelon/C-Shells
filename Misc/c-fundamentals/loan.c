#include<stdio.h>

/* A program that calculates the remaining balance of a loan after the 1st to
 * the 5th monthly payments.
 *
 * This a comment-block, and the only comment notation for C89.
 * "//" was introduced in C99.
 */
int main()
{
    // new-line char terminates the current output line
    printf("Hello! This is a loan calculator =)\n");

    // float arithematic may be slow than using int
    // float is OFTEN used as an APPROXIMATION of a number

    // C99 declarations do not need to come before statements
    float loan = 0;
    float interestRate = 0;
    float monthlyPayment = 0;

    // const float someFloatConst = 1234.567f
    // append "f" for float constants

    // mixing types e.g.
    // float ff = 2.3;
    // int ii = 0;
    // ii = ff; //2
    // loses precision

    // formated print and scan
    // "%f" and "%d" are placeholders
    printf("Enter loan amount: ");
    scanf("%f", &loan);

    printf("Enter yearly interest rate %%: ");
    scanf("%f", &interestRate);

    // adding a new-line char in scanf will allow user to input in the line
    // after the printf statement
    printf("Enter monthly payment amount: ");
    scanf("%f", &monthlyPayment);

    printf("\n");

    for (size_t i = 1; i < 6; i++)
    {

        loan = ((loan + (loan * ((interestRate/12.0f)/100) )) - monthlyPayment);

        // Default: Printing "%f" displays 6 digits after decimal
        // Below prints 2 digits after decimal.
        printf(
            "Balance remaining after #%d payment: %.2f\n",
            i,
            loan
            );
    }

    return 0;
}
