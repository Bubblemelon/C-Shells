/*
This program prints half a christmas tree.

*
**
***
****
*****
******
*******
********
*********

*/

#include <stdio.h>

// prints stars using two-level nested for-loops
void printStar(int n);
// print stars using recursion
void printStarRecurse(int n, int start);
// print stars using recursion (upside down)
void printStarRecurseD(int n);

void printStar(int n){

    int count = 0;

    for(int i=0; i <= n; i += 1 )
    {
        count = i;
        while(count > 0){
            printf("*");
            count--;
        }
        printf("\n");
    }
}
