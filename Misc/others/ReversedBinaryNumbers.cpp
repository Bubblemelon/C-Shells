// Find the reverse binary number representation of a decimal number in decimal.
// For instance, the binary representation of 13 is 1101,
// and reversing it gives 1011, which corresponds to number 11.

// sample 1 file content:
// 13
// returns 11

// sample 2 file contents:
// 47
// returns 61

// compile:
// g++ ReversedBinaryNumbers.cpp -o RBN
// test:
// ./RBN < sometestfile.in

// source
// https://open.kattis.com/problems/reversebinary

/////////////////////// START /////////////////////////////////////////////////

// #include <iostream>
// #include <string>
// using namespace std;
//
//
// // convert decimal to binary
// int dec2bin( int dec ){
//
// string temp = "";
//
//   while(dec > 0){
//
//     if(dec%2 == 1){
//
//       ///////////////////////////
//       // IMPORTANT:
//       // temp = "1" + temp;
//       // for actually binary value
//       ///////////////////////////
//
//       // this is to reverse the binary value of dec
//       temp += "1";
//     }
//     // dec%2 == 0
//     else {
//
//       ///////////////////////////
//       // IMPORTANT:
//       // temp = "0" + temp;
//       // for actually binary value
//       ///////////////////////////
//
//       // this is to reverse the binary value of dec
//         temp += "0";
//     }
//
//     dec = dec/2; // to eventaully get to zero
//   }
//   // string to int
//   return stoi(temp);
// }
//
// // convert binary to decimal
// int bin2dec( int bin){
//
//   // least significant bit and temp. store
//   int lsb, temp = 0;
//
//   // powers of 2; starting from position lsb
//   int p = 1;
//
//   // OR while(bin){}
//   while(bin > 0){
//
//     lsb = bin % 10; // get lsb
//
//
//     bin /= 10; // to eventually get to zero
//
//     // return value temp. store
//     temp += (lsb*p);
//
//
//     p *= 2; // increment to the next power of 2
//
//   }
//
//   return temp;
// }
//
// int main(void) {
//
//   int input, intermediate;
//
//   cin >> input;
//
//   // convert decimal to binary
//   intermediate = dec2bin(input);
//
//   // cout << intermediate << endl;
//
//   // convert binary to decimal
//   // bin2dec(intermediate);
//
//   cout << bin2dec(intermediate) << endl;
//
//   return 0;
// }

/////////////////////////////////////////
// THE ABOVE RECEIVED A RUNTIME ERROR  //
/////////////////////////////////////////

// BITSETs
// https://www.geeksforgeeks.org/c-bitset-and-its-application/

#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

#define M 32

// to count the number of bits in a decimal number
// e.g 13 will have 4 bits _1 _1 _0 _1
int bitCount(int dec)
{
	int c = 0;

	for(int i = 0; i < M; ++i){

    // e.g. to see if a > (2^4 == 16) when i == 4, if not, then c = 4
    // does not work if ( dec > pow(2,i) || dec > 0 )
    if(dec > pow(2,i) -1 ){
      c++;
    }
  }

	return c;
}

int main(void) {

  // the given decimal
	int in;
	cin >> in;

  // convert input to binary using bitset
  bitset<M> input(in);

  // cout << input << endl;

  // have an ouput of 00000000000000000000000000000000
	bitset<M> output(0);

	for(int i = 0; i < bitCount(in); ++i)
	{
    // Tests whether the bit at a position "i" in "input" bitset is set to 1.
		if(input.test(i))

      // sets a bit at a specified position to 1.
      // input's index | output's index
      // i == 0;          4-0-1 = 3
      // i == 1;          4-1-1 = 2
      // i == 2;          4-2-1 = 1
      // i == 3;          4-3-1 = 0
      // this is to place the bits in reverse order!
			output.set( bitCount(in)-i-1 );
	}

  // covert to int [ Returns an unsigned long with the integer value that
  // has the same bits set as the bitset ]
  cout << (int)( output.to_ulong() ) << endl;

	return 0;


}
