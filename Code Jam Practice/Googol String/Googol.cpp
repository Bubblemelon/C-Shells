#include <iostream> // to do cout and cin
#include <fstream> // manipulate files
#include <sstream> // to convert string to ints/doubles/floats
#include <string> // allow for string type
#include <algorithm> // allows for string reversal: https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
#include <cmath> // round() https://www.programiz.com/cpp-programming/library-function/cmath/round

// Global Variable:
int min_n_iterate_count = 0;

// this method does the reversing and then switching part of the sequence
std::string reverseNSwitch( std::string sn_1 )
{
    // std::cout << "Before reversal sn_1: " << sn_1 << std::endl;

    // using built in reverse function - stored into sn_1
    //
    // e.g. reverse 0 becomes 0
    // e.g. reverse 001 becomes 100
    std::reverse( sn_1.begin(), sn_1.end() );

    // std::cout << "sn_1 is now reversed: " << sn_1 << std::endl;

    // Coverting to Char array, a "C string" from a string
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
    // "-1" to not print \0
    //
    // for(int j = 0; (char_array_size - 1) > j; ++j)
    // {
    //   if( j == 0 )
    //     std::cout << "Printing Switched sequence:" << std::endl;
    //
    //   std::cout << char_array[j];
    //
    //   if( j == char_array_size - 2 )
    //     std::cout << std::endl;
    // }


    // Convert the reversed+switched char array to a string
    //
    // https://stackoverflow.com/questions/8960087/how-to-convert-a-char-array-to-a-string
    //
    std::string return_string(char_array);

    return return_string;

}// reverseNSwitch()

// Finds the minumum S_N to iterate to inorder to find Kth Element within
// that sequence.
//
// S_N = (S_N-1) * 2 + 1 <-- length of a "N" sequence
//
// Find N (as iterate_count) to get Kth element:
// e.g.
// 3th element will only need S_2, where N is 2 (S_2 length is 3)
// Not S_3 because this one has 7 elements all together (or length 7), the other 4 is unnecessary
//
// IMPORTANT:
//
// sequence_length == kth element
// (find the N that will generate up to kth element sequence or slightly more - NOT less than kth)
//
// Needs to be rounded because
//
int minSn( double sequence_length )
{

  if( sequence_length < 1 )// base case or "== 0" as long as less than 1
  {
    // std::cout << "sequence_length" << sequence_length << std::endl;

    return min_n_iterate_count; // this needs to be reset for each find
  }
  else // recursion
  {
    min_n_iterate_count += 1;

    // std::cout << "min_n_iterate_count" << min_n_iterate_count << std::endl;

    sequence_length = minSn( std::round((sequence_length - 1) / 2) ) ;

  }

  return min_n_iterate_count; // this needs to be reset for each find

} // minSn()


// this method generates the sequence:
char googol( std::string kth )
{
  // requires C++ 11
  //
  // stores S_N's (may need to add 1)
  int n = stoi( kth );

  // converty kth to an int
  int kth_int = stoi( kth );

  // IMPORTANT:
  //
  // Kth starts from 1, being the 1st character of S_googol which is '0'
  //
  // When N = 0 S_N = ""
  // When N = 1 S_N = '0`


  /* SECTION for IMPROVEMENT:
   *
  // Check if this function has been called before (if true)
  // and then see if the current "n" is smaller than g_char_array_size:
  //
  // if( googolfunc_called_b4 )
  // {
  //   if( n > 1 )
  //   {
  //     return g_char_array[n-1]; // this array needs to be dynamically allocated
  //   }
  // }
  *
  */

  // function call for how much to iterate
  n = minSn( static_cast<double>(n) );

  // std::cout << n << std::endl;

  // starting string
  std::string sn = "";

  if( n == 1 ) // this is S_0
  {
    // std::cout << "N is less is equal to 1: " << n << std::endl;
    // if Kth == 1
    return '0';
  }



  if( n > 1 )
  {
    // since N is more than 1 (this is S_1)
    sn += "0";

    // std::cout << "N more than 1: " << n << std::endl;

    for(int i = 1; n > i; ++i)
    {
      // find the reverseNSwitch portion

      // std::cout << "sn before: " << sn << std::endl;

      sn += "0" + reverseNSwitch( sn );

      // std::cout << "sn after: " << sn << std::endl;
    }


  }

  // Convert the completed sequnce of sn into a char array
  //
  // perhaps it's not necessary to include null terminator
  int g_char_array_size = sn.length() + 1;
  char g_char_array[ g_char_array_size ];

  // copying the contents of sn
  // to g_char_array
  std::strcpy( g_char_array, sn.c_str() );

  // std::cout << "The Element requested an postion " << n << " is: " << g_char_array[n-1] <<std::endl;

  // "-1" because the first element of the array is counted as 1 (not zero)
  //
  return g_char_array[kth_int - 1] ; // returns the a char type element at position n

} // googol()



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

    std::cout << "Case #"<< i << ": ";

    // put input into function call

    std::cout << googol(input) << std::endl;

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
