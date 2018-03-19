// this includes cin to read from stdin and cout to write to stdout
// https://stackoverflow.com/questions/22645097/what-does-include-iostream-do
#include <iostream>
//
// Avoid pre-standard C++:
// https://stackoverflow.com/questions/10950083/why-stdcout-instead-of-simply-cout
// e.g. #include <iostream.h>
//
// Should be better to use std::cout and std::cin
// To not include all functions from std
// https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice
//
using namespace std;
// using std::cout;
// using std::cin;
// using std::endl;

int main() {

  int t, n, m;

  cin >> t; // reads the number of lines (from an input file)

  // usage of ++i: https://stackoverflow.com/questions/24853/what-is-the-difference-between-i-and-i
  // ++i and i++ in this for loop will operate the same:
  for(int i = 1; t >= i; ++i)
  {
    cin >> n >> m; // read n and then m on the same line
    cout << "Case #" << i << ": Sum of " << n << "+" << m << " " << (n+m) << " " << "Product of " << n << "*" << m << " " << (n*m) << endl; // Inserts a new-line character and flushes the stream.
  }


  return 0;
}
