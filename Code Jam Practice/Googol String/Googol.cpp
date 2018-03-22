#include <iostream> // to do cout and cin
#include <fstream> // manipulate files
#include <sstream> // to convert string to ints/doubles/floats
#include <string> // allow for string type
#include <algorithm> // allows for string reversal: https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/

// this method generates the sequence:
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

  // starting string
  std::string sn = "";

  if( n == 1 )
  {
    std::cout << "N is less is equal to 1: " << n;
    // if Kth == 1
    return '0';
  }

  // since N is more than 1
  sn += "0";

  // recursion
  if( n > 1 )
  {
    std::cout << "N more than 1: " << n;

    sn = "0"; //function call
  }

  return 'e'; // needs to be changed

} // googol()

// this method does the reversing and then switching part of the sequence
std::string reverseNSwitch( std::string sn_1 )
{
    std::cout << "Before reversal sn_1: " << sn_1 << std::endl;

    // using built in reverse function - stored into sn_1
    //
    // e.g. reverse 0 becomes 0
    // e.g. reverse 001 becomes 100
    std::reverse( sn_1.begin(), sn_1.end() );

    std::cout << "sn_1 is now reversed: " << sn_1 << std::endl;

    // coverting to Char array - C string
    // https://www.geeksforgeeks.org/convert-string-char-array-cpp/

    // length of reversed sn_1 "+ 1" to include the terminating null-character ('\0') at the end
    //
    int char_array_size = sn_1.length() + 1;
    char char_array[ char_array_size ];

    // copying the contents of sn_1
    // to char_array
    std::strcpy( char_array, sn_1.c_str() );

    // Switching 1s to 0s and 0s to 1s
    //
    // - 1 : to not access \0 null character
    for(int i = 0; (char_array_size - 1) > i; ++i)
    {
      if( char_array[i] == '0' )
      {
        char_array[i] = '1';
      }
      else // char_array[i] == 1
      {
        char_array[i] = '0';
      }
    }

    // Just for printing the result for having done switching
    // -1 to not print \0
    for(int j = 0; (char_array_size - 1) > j; ++j)
    {
      if( j == 0 )
        std::cout << "Printing Switched sequence:" << std::endl;

      std::cout << char_array[j];

      if( j == char_array_size - 2 )
        std::cout << std::endl;
    }


    return ""; // needs to be changed

}// reverseNSwitch()

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

    reverseNSwitch(input);

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
