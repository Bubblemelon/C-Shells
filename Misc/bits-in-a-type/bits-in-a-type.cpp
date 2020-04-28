#include <iostream> //to use `cout`
#include <climits>  //to use `CHAR_BITS`
#include <stddef.h> //to use `size_t`

//to use e.g. uint8_t, see http://www.cplusplus.com/reference/cstdint/ for full list
#include <stdint.h>
#include <cstdio> // to use printf
#include <string> // for strings
using namespace std;

/*
 * This program returns the number of bits in a type.
 */

// constexpr: indicates expression is constant and if possible computed at compile time. Introduced in C++11.
//
// https://docs.microsoft.com/en-us/cpp/cpp/constexpr-cpp?view=vs-2019

// returns the number of bits in a byte without using CHAR_BITS
constexpr unsigned short bits_per_byte();

// returns the number of bits in a byte "using" CHAR_BITS
template <typename T>
size_t bits_in_a_type();

// prints the number of bytes in a type, takes string t for printing
template <typename T>
void printTypeNumBits(unsigned short bits, string t);

////////////////////////////////////////////////////////////////////////////////

constexpr unsigned short bits_per_byte()
{
 int bit = 0;

 for (char c = 1; c != 0; ++bit)
 	c = c* 2;
 return bit;
}

template <typename T>
size_t bits_in_a_type()
{
    return sizeof(T) * (CHAR_BIT);
}