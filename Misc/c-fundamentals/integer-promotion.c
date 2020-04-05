#include <stdio.h>
#include <stdbool.h>

/*
 * Functions that mimic ctype.h functions, i.e. isdigit(), islower(), and isupper().
 *
 * See a list of ctype.h functions in "/usr/include/ctype.h"
 * OR here,
 * https://www.programiz.com/c-programming/library-function/ctype.h/isdigit
 */

bool isDigit(char c); /*Returns true if c is a digit.*/
bool isLower(char c); /*Returns true if c is an uppercase letter.*/
bool isUpper(char c); /*Returns true if c is a lowercase letter.*/

bool isDigit(char c){

    if( c >= 48 && c <= 57 ){
        return true;
    }
    return false;
}

bool isLower(char c){

    if( c >= 97 && c <= 122 ){
        return true;
    }
    return false;
}

bool isUpper(char c){

    if( c >= 65 && c <= 90 ){
        return true;
    }
    return false;
}

int main()
{
    char input;
    /* Suppose that i and j are variables of type int. What is the type of the expression i / j + 'a'? */

    // 'a' which has the type char will be automatically promoted to an int.
    // This is called Integer Promotion.

    // let i and j be the following values:
    int i = 1, j =2;
    char a = 'a';

    printf("\nEvaluate the expression: i + j + 'a':\n");
    printf("(int i=%d) + (int j=%d) + (char 'a' in ASCII Decimal is %d) = %d \n", i, j, a, i+j+a);

    // The result fo the above printf statement is:
    // (int i=1) + (int j=2) + (char 'a' in ASCII Decimal is 97) = 100

    printf("\n*** Character attributes ***\n");
    printf("\nEnter a character: ");
    scanf("%c", &input);

    if(isDigit(input)){
        printf("\n'%c' is a digit.", input);
    }else{
        printf("\n'%c' is not a digit.", input);
    }

    if(isLower(input)){
        printf("\n'%c' is a lowercase letter.", input);
    }else{
        printf("\n'%c' is not a lowercase letter.", input);
    }

    if(isUpper(input)){
        printf("\n'%c' is an uppercase letter.", input);
    }else{
        printf("\n'%c' is not an uppercase letter.", input);
    }

    printf("\n");

    return 0;
}

