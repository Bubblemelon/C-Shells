// Three kangaroos are playing in the desert. They are playing on a number line,
// each occupying a different integer. In a single move, one of the outer kangaroos
// jumps into the space between the other two.
// At no point may two kangaroos occupy the same position.
// Help them play as long as possible.

// Given Iput
// Three integers A, B and C (0<A<B<C<100), the initial positions of the kangaroos.

// Output
// Output the largest number of moves the kangaroos can make.

// sample 1 file contents
// 2 3 5
//
// returns 1
//
// explained:
// 2 3 _ 5
// (3-1) - 2 == 0
// (5-1) - 3 == 1
// 1 > 0

// sample 2 file contents
// 3 5 9
//
// returns 3
//
// explained:
// 3 _ 5 _ _ _ 9
// (9-1) - 5 == 3
// (5-1) - 3 == 1
// 3 > 1

// compile:
// g++ Skocimis.cpp -o skoc
// test:
// ./skoc < sometestfile.in

// source
// https://open.kattis.com/problems/skocimis

#include <iostream>
using namespace std;

int main(void) {

  int a, b, c;

  cin >> a >> b >> c;

  int d1 = 0, d2 = 0;

  // find distance1 between lower boundary a and middle b
  d1 = (b-1) - a;

  // find distance1 between upper boundary c and middle b
  d2 = (c-1) - b;

  if( d1 > d2 ){
    cout << d1 << endl;
  } else {
    cout << d2 << endl;
  }

  return 0;
}
