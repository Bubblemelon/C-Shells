#include <iostream> // to do cout and cin
#include <string> // allow for string type


int main(int argc, char const *argv[]) {

  int case_num;

  int num_flights;

  // take the number of cases from 1st line
  std::cin >> case_num;

  // for each case, starting with 1 up to case_num
  for(int i = 1; case_num >= i; ++i)
  {
    std::cout << "Case #" << i << ": ";
  }

  return 0;
}
