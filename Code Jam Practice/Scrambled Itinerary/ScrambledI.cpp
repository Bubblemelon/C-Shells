#include <iostream> // to do cout and cin
#include <string> // allow for string type

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

  public:
    Transit( std::string des, int rep );  // constructor

    // getters
    std::string getDestination() {return destination;}
    int getRepeats() {return destination_repeat;}

    //setters (needs to be void)
    void setDestination(std::string d) {destination = d;}
    void setRepeats(int r) {destination_repeat = r;}


}; // dont forget semicolon for class

// Member functions definitions are in the class itself
//
// Constructor definition below:

Transit::Transit( std::string des, int rep )
{
  std::cout << "Transit Object is created" << std::endl;
  destination = des;
  destination_repeat = rep;
}


int main(int argc, char const *argv[]) {

  // int case_num;
  //
  // int num_flights;
  //
  // // take the number of cases from 1st line
  // std::cin >> case_num;
  //
  // // for each case, starting with 1 up to case_num
  // for(int i = 1; case_num >= i; ++i)
  // {
  //   std::cout << "Case #" << i << ": ";
  // }

  Transit item( "SFO", 1 );


  std::cout << "Get Destination: " << item.getDestination() << std::endl;
  std::cout << "Get Repetition: " << item.getRepeats() << std::endl;


  item.setDestination("DFW");
  std::cout << "Get Destination: " << item.getDestination() << std::endl;



  return 0;
}
