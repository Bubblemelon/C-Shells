#include <iostream> // to do cout and cin
#include <fstream> // manipulate files
#include <sstream> // to convert string to ints/doubles/floats
#include <string> // allow for string type

// a dynamic array to store all of the destinations within a case:
// persists throughout program runtime : http://www.bogotobogo.com/cplusplus/statics.php
static std::string *des_array;

// My own data type
// stores destination name as strings
// and its repetitions as ints
//
// Below uses two ways of defining the class:
// look at https://www.tutorialspoint.com/cplusplus/cpp_constructor_destructor.htm
// and https://stackoverflow.com/questions/4450918/creating-my-own-data-type
// for comparision.
class Transit
{
  private:
    std::string destination;
    int destination_repeat;

    // to track the destinations checked
    std::string *checker;
    int check_count;

  public:
    // Transit( std::string des, int rep );  // constructor declaration

    // Destrutor declaration & defintion is needed when:
    // dynamically allocated memory or pointer in class
    // ~Transit();

    // getters
    std::string getDestination() {return destination;}
    int getRepeats() {return destination_repeat;}

    // setters (return values must be void)
    //
    // Possible errors of non-void setters:
    // warning: control reaches end of non-void function
    // Illegal instruction: 4 (when the binary is runned)
    void setDestination(std::string d) {destination = d;}
    void setRepeats(int r) {destination_repeat = r;}

    // a function that finds the number of
    // repeats for a specific destination within an array (takes des_array)
    // use "this" to refer to class instance
    //
    // *& to avoid junk values (https://stackoverflow.com/questions/8056746/copying-from-one-dynamically-allocated-array-to-another-c)
    void repeatFinder( std::string *&pt_array )
    {
      check_count = 1;
      // this will be deleted and a new one created+resized for each new checked destination
      checker = new std::string[check_count];

      for(int i = 0; ( sizeof( pt_array ) / sizeof( pt_array[0] ) ) > i; ++i)
      {
        if( i == 0 && check_count == 1 )
        {
          this.setDestination = pt_array[i];
          checker[check_count - 1] = pt_array[i];
        }
        else
        {
          for(int i = 0; check_count > i; ++i)
          {
          }
        }

        //reset check_count
      }

      // delete checker when done:
      delete checker[];
    }

}; // dont forget semicolon for class


// Member functions definitions are in the class itself
//
// Constructor definition below: [TAKEN Out because of line: "Transit pairs_2d[ flight_num ][2];"]
//
// Transit::Transit( std::string des, int rep )
// {
//   std::cout << "Transit Object is created" << std::endl;
//   destination = des;
//   destination_repeat = rep;
// }

// UnScrambler function definition:
//
// Cannot make an implicit copy of ifstream !
// https://stackoverflow.com/questions/12432952/why-is-my-fstream-being-implicitly-deleted
// Error:
// implicit copy constructor for 'std::__1::basic_ifstream<char,
//      std::__1::char_traits<char> >' first required here
//    UnScrambler( input_file );
// Therefore pass by reference:
// http://www.cplusplus.com/forum/beginner/121157/
void UnScrambler( std::ifstream &file )
{
  // to contain the input as strings from ifstream
  // Needs to be reset to empty when done using
  std::string string_container = "";

  // start by getting the number of flights (also number of source-destination pairs)
  int flight_num;

  std::getline( file, string_container );

  // assumes this that this level of input can always be converted to an int
  // storing flight_num
  flight_num = stoi( string_container );

  // reset string
  string_container = "";

  // flight_num*2 == number of the destinations listed within a given case
  // need to be deleted when done using
  des_array = new std::string[flight_num*2];

  // store all destination names in the public dynamic array:
  for(int i = 0; (flight_num*2) > i; ++i)
  {
    std::getline( file, des_array[i] );
    std::cout << des_array[i] << std::endl;
  }

  // 2D Array
  // rows == number of pairs
  // column is always equal 2 as they are only pairs
  // needs to be deleted when done
  Transit pairs_2d[ flight_num ][2];

  // storing elements into 2D Array
  // for( int r = 0; flight_num > r; ++r )
  // {
  //   for(int c = 0; 2 > c; ++c)
  //   {
  //       pairs_2d[r][c] = // function call
  //   }
  // }

  // free array when function is done
  delete des_array;
} // UnScrambler




int main(int argc, char const *argv[]) {

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
    std::cout << "Case #"<< i << ": ";

    // function call
    UnScrambler( input_file );

    // std::cout << std::endl;

  } // for i



  return 0;
}
