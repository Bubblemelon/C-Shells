#include <iostream>
using namespace std;
// given two integers, find the number of remaining pieces of chicken or
// number of required chicken needed by one person

// for example
// 1st int == number of people at the buffet
// 2nd int == number of pieces of chicken provided.

// The first line contain integers 0≤N≤1000, 0≤M≤1000, N≠M ,
// the number of people at the buffet
// and the number of pieces of chicken Dr. Chaz is providing.

// sample 1 file contents
// 20 100
//
// returns 80 pieces of chicken remaining or 80 left over
// i.e. Dr. Chaz will have 80 pieces of chicken left over!

// sample 2 file contents:
// 2 3
//
// returns 1 piece of chicken left over
// i.e. Dr. Chaz will have 1 piece of chicken left over!

// sample 3 file contents:
// 10 1
//
// returns 9 more pieces of chickens needed
// i.e. Dr. Chaz needs 9 more pieces of chicken!

// compile:
// g++ OneChickenPerPerson.cpp -o chicken
// test:
// ./chicken < sometestfile.in

// source
// https://open.kattis.com/problems/onechicken
int main(){

  // n == eat ; m == supply
  int n, m;

  cin >> n >> m;

  // if supplied > eat amount
  if(n < m)
  {
    if((m-n) == 1){
      cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
      return 0;
    } else {
      cout << "Dr. Chaz will have " << (m-n) << " pieces of chicken left over!\n";
    }

  // if eat amout > supplied
  } else{

    if((n-m) == 1){
      cout << "Dr. Chaz needs 1 more piece of chicken!\n";
      return 0;
    } else {
      cout << "Dr. Chaz needs " << (n-m) << " more pieces of chicken!\n";
      return 0;
    }

  }
}
