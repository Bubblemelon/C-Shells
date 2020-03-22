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

void printStarRecurse(int n, int start){

    //base case
    if( start == n ){
        return;
    }

    int count = 0;
    while( count < start + 1 ){
        printf("*");
        count++;
    }
    printf("\n");

    return printStarRecurse( n, start + 1 );
}


void printStarRecurseD(int n){

    //base case
    if( n == 0 ){
        return;
    }

    int count = 0;
    while( count < n ){
        printf("*");
        count++;
    }
    printf("\n");

    return printStarRecurseD( n - 1 );
}