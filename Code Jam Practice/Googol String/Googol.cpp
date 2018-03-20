#include <iostream>
#include <fstream>
#include <string>

//recursion
void googol(int kth)
{

}


int main(int argc, char const *argv[])
{

  // creates ifstream object to read integers from the input file
  std::ifstream input_file( argv[1] );

  // stores the number of cases
  std::string input;

  // get first line as case number

  // for each iteration print the case number within the loop

  while( std::getline(input_file, input) )
  {

    std::cout << "Case #"<< input << ":";

    // exit the loop when end of file is reached
    if( input_file.eof() )
    {
      break;
    }

  }



} // main
