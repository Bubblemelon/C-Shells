// Given Iput
// Input has one test case per line. Each test case contains two integers in the range [1,231−1].
// The first number is the numerator and the second is the denominator.
// A line containing 0 0 will follow the last test case.

// Output
// For each test case, display the resulting mixed fraction
// as a whole number followed by a proper fraction,
// using whitespace to separate the output tokens.
//
// Do not reduce the fraction (i.e. don’t change 3/12 to 1/4).

// sample 1 file contents
// 27 12
//
// returns 2 3 / 12

// sample 2 file contents
// 2460000 98400
//
// returns 25 0 / 98400

// sample 3 file contents
// 3 4000
//
// returns 0 3 / 4000

// sample 4 file contents
// 0 0
//
// returns nothing (as in empty - no printing)

// An entire sample input file will look like:
// 27 12
// 2460000 98400
// 3 4000
// 0 0

// compile:
// g++ MixedFractions.cpp -o mf
// test:
// ./mf < sometestfile.in

// source
// https://open.kattis.com/problems/mixedfractions

#include <iostream>
using namespace std;

int main(void) {
    int n, d; // numerator and denominator

    while(cin >> n >> d){

      int wholeNum = 0;

      // do nothing if 0/0
    	if(n == 0 && d == 0){
        break;
      }
        // don'nothing anything if denominator is 0, e.g. 12/0
      if( d == 0 ){
        break;
      }

      // case: do nothing if numerator 0, e.g. 0/12 = 0
      // case: 4/4 i.e. d == n
      // case: 6/4 i.e n > d
    	while(n >= d)
    	{
    		n -= d; // numerator = numerator - denominator;
        wholeNum++;
    	}
    	cout << wholeNum << " " << n << " / " << d << endl;
    }
    return 0;
}
