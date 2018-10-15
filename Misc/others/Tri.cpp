// Find a logical expression from the given numbers.
// Using addition, subtraction, multiplication and division

// Given Iput
// The first line of input contains three integers less than 100,
// separated by spaces.
// The input data will guarantee that a solution, although not necessarily
// unique, will always exist.

// Output
// On a single line, output a valid equation containing the three integers
// (in the same order), an equals sign and one of the four operations.
// If there are multiple solutions, output any of them.

// sample 1 file contents
// 5 3 8
//
// returns 5+3=8

// sample 2 file contents
// 5 15 3
//
// returns 5=15/3

// compile:
// g++ Tri.cpp -o tri
// test:
// ./tri < sometestfile.in

// source
// https://open.kattis.com/problems/tri

#include <iostream>
using namespace std;

int main(void) {

  // first 3 integers from sample file
  int a, b, c;
  cin >> a >> b >> c;

  // addition

  if(a+b == c){
    cout << a << "+" << b << "=" << c << endl;
  }
  else if(b+c == a){
    cout << a << "=" << b << "+" << c << endl;
  }

  // subtraction

  else if(a-b == c){
    cout << a << "-" << b << "=" << c << endl;
  }
  else if(b-c == a){
    cout << a << "=" << b << "-" << c << endl;
  }

  // multiplication

  else if(a*b == c){
    cout << a << "*" << b << "=" << c << endl;
  }
  else if(b*c == a){
    cout << a << "=" << b << "*" << c << endl;
  }

  // division

  else if(a/b == c){
    cout << a << "/" << b << "=" << c << endl;
  }
  else if(b/c == a){
    cout << a << "=" << b << "/" << c << endl;
  }



    return 0;
}
