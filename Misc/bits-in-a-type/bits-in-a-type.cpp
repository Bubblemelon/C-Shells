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
void print_num_bits_in_type(unsigned short bits, string t);

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

template <typename T>
void print_num_bits_in_type(const unsigned short bits, string t){

	cout << t << " : " << bits*sizeof(T) << '\n';
}

int main()
{
	constexpr unsigned short bits = bits_per_byte();

	printf("\n---Find bits in a type using CHAR_BITS ---\n");
    printf("uint8_t : %d\n", bits_in_a_type<uint8_t>());
	printf("size_t : %d\n", bits_in_a_type<size_t>());
    printf("long long : %d\n", bits_in_a_type<long long>());
    printf("void* : %d\n", bits_in_a_type<void*>());
    printf("bool : %d\n", bits_in_a_type<bool>());
    printf("float : %d\n", bits_in_a_type<float>());
    printf("double : %d\n", bits_in_a_type<double>());
    printf("long double : %d\n", bits_in_a_type<long double>());

	printf("\n---Find bits in a type W/O using CHAR_BITS ---\n");
	print_num_bits_in_type<uint8_t>(bits, "uint8_t");
	print_num_bits_in_type<size_t>(bits, "size_t");
	print_num_bits_in_type<long long>(bits, "long long");
	print_num_bits_in_type<void*>(bits, "void*");
	print_num_bits_in_type<bool>(bits, "bool");
	print_num_bits_in_type<float>(bits, "float");
	print_num_bits_in_type<double>(bits, "double");
	print_num_bits_in_type<long double>(bits, "long double");

	return 0;
}

/* Example Compile command:
 *
 * g++ -O2 -g bits-in-a-type.c
 *
 */

/******* Sample Output

---Find bits in a type using CHAR_BITS ---
uint8_t : 8
size_t : 64
long long : 64
void* : 64
bool : 8
float : 32
double : 64
long double : 128

---Find bits in a type W/O using CHAR_BITS ---
uint8_t : 8
size_t : 64
long long : 64
void* : 64
bool : 8
float : 32
double : 64
long double : 128

********/