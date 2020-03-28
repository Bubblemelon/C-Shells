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