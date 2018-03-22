#include <iostream> // to do cout and cin
#include <fstream> // manipulate files
#include <sstream> // to convert string to ints/doubles/floats
#include <string> // allow for string type
#include <algorithm> // allows for string reversal: https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/

// this alogrithm generates the sequence:
char googol( std::string kth )
{
  // requires C++ 11
  //
  // stores S_N's (may need to add 1)
  int n = stoi( kth );

  // IMPORTANT:
  //
  // Kth starts from 1, being the 1st character of S_googol which is '0'
  //
  // When N = 0 S_N = ""
  // When N = 1 S_N = '0`
  if( n == 1 )
  {
    // if Kth == 1
    return '0';
  }

  // starting string
  std::string sn = "";

  // recursion
  if( n > 1 )
  {
    
  }

  // using built in reverse function

}


int main(int argc, char const *argv[])
{


  // stores the iteration inputs
  std::string input;


  // stores the case numbers
  std::string case_num_string;
  int case_num = 0;


  // creates ifstream object to read integers from the input file
  std::ifstream input_file( argv[1] );


  // get first line from the file and saves as the case number as a string
  std::getline(input_file, case_num_string);

  // stringstream object and putting case_num_string into it
  std::stringstream string_2int(case_num_string);

  // convert string to int
  string_2int >> case_num;


  for(int i = 1; case_num >= i; ++i)
  {
    // get the lines after the case number line
    std::getline(input_file, input);

    std::cout << "Case #"<< i << ":";

    // put input into function call



    // exit while loop when end of file is reached
    //
    // may be uncessary
    // if( input_file.eof() )
    // {
    //   break;
    // }

  } // for i




  return 0;
} // main
