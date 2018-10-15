// Find the age at which Alice can retire when she has more money than when
// when Bob retires.

// Given Iput
// The input is a single line consisting of 5 space separated
// integers; B, Br, Bs, A, As.

// Output
// Output the age at which Alice can retire so that she has more money than Bob
// will have at age Br.

// sample 1 file contents
// 20 25 5 20 10
//
// returns 23

// ^^^ Explains the Above ^^^
// At the age of 25 Bob has saved 5 every year for 5 years.
// This means that Bob has 25 saved up.
// At the age of 23 Alice has saved 10 every year for 3 years.
// This means that Alice has 30 saved up, which is strictly more than 25.

// sample 2 file contents
// 20 28 5 30 9
//
// returns 35

// compile:
// g++ SavingForRetirement.cpp -o sfr
// test:
// ./sfr < sometestfile.in

// source
// https://open.kattis.com/problems/savingforretirement

#include <iostream>
using namespace std;
#include <math.h>     /* round, floor, ceil, trunc */


int main(void) {

  // Bob's starting age, Bob's retirement age, Bob's yearly save amount
  // Alice's starting age, Alice's yearly save
  float b, br, bs, a, as;

  float bAmountSaved =0;
  float aYears=0;

  cin >> b >> br >> bs >> a >> as;

  // find Bob's total retirement amount
  // plus 1 is for ceiling function!!!!
  // http://www.cplusplus.com/reference/cmath/round/
  bAmountSaved = (br - b)*bs + 1;

  // find the number of years Alice needs to save to be more than Bob
  aYears= ceil(bAmountSaved/as);

  // cout << aYears << endl;


  // find the age in which Alice can retire with an amount more than Bob
  cout << int(a + aYears) << endl;
  return 0;

}
