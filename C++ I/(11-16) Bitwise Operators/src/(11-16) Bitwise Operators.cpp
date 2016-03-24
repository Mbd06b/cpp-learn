//============================================================================
// Name        : (11-16).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef unsigned char Byte; //typedef sets up a replacement in the compiler
	//everytime I write Byte,  it will be calling in an unsigned char
typedef unsigned int UInt; //

int main() {

	Byte	B1;
	Byte	Mask; //Mask - common term for a pattern of half bytes.
	Byte 	Result;
	int		I1;


	B1 = 0xE9;  // 0x means the number we are writing is in hexadecimal (base 16)
	cout << hex; // prints the following numbers in hexidecimals.

	// we are manipulating the bits, because hardware often needs a 0 or 1 for on and off, this is the smallest
	//most efficent way of communicating with a small LED light indicator, or simple hardware setup/ ie.  a garage door opener reciever code 0100101001?

	//   &    -- This is a bitwise and.

	cout << "Pattern is " << (UInt) B1 << endl;
				  // bytloc  8421|8421
	Mask = 0x08;  // this is 0000|1000  in byte location 8.


	//Check i a flag is on or off
	Result = B1 & Mask;
	if (Result) // since this a string of zeros and ones/ Result shows either 1-true, or 0 false.
	{
		cout << "Flag was on" << endl;

	}
	else
	{
		cout << "Flag was off" << endl;
	}

	// to change a single bit in a byte, we need to flip all the bits in the byte, and use AND comparison, to turn off the single
	//targeted bit off.


	// turn a flag off
	Result = B1 & ~Mask; // ~ is bitwise NOT and flips all bits over
	cout << "REsult with bit off is " << (UInt) Result << endl;

	 // bytloc  8421|8421
	 // this is 1110|1001  in byte location 8.
	 // inputis 1111|0111  comparing with && operation (like multip by 1)
	 // outis   1110|0001  Everything Change but our targeted bit in
	 //output    (E)  (9)

	// turn a flag on
	Result = B1 | Mask;  //  | is bitwise OR and or's corresponding bits
	cout << "Result with bit back on is " << (UInt) Result << endl;

	 // bytloc  8421|8421
	 // this is 1110|0001  in byte location 8.
	 // inputis 1111|0111  comparing with OR (|)  operation (like multip by 1)
	 // outis   1110|1001  Everything Change but our targeted bit in 8
	 //outputs   (E)  (9)


	Mask = 0xC6;
	Result = Result ^ Mask; // ^ is bitwise EXCLUSIVE OR, result is true if the two bits are different
	cout << "Result is " << (UInt) Result << endl;
	 // bytloc  8421|8421
	 // this is 1110|1001  in byte location 8.
	 // inputis 1100|0110  comparing with OR (|)  operation (like multip by 1)
	 // outis   0010|1111 Everything Change but our targeted bit in 8
	 //	outputs	(2)   (F)

	I1 = 0142; //starting a number with 0 does not mean decimal. It means OCTAL (the old 6bit Byte System)
			   //  421|421|421
			   //  001|100|010
			//outs (1) (4) (2)
	cout << dec; //dec  STart printing my numbes as decimal
	cout << "I1 is " << I1 << endl;

	//outputs 98 in hex, 142 in dec

	//shifting bits left and right
	cout << hex; //tell count we want numbers printed using hexidecimal
	B1 = 0x34;
	Mask = B1 << 1;  //shift all bits in B1 one position to the left
	cout << B1 << " Shifted left is " << (UInt) Mask << endl;
		 // bytloc  8421|8421
		 // before   (3)  (2)
		 // this is 0011|0100
		 // inputis 0110|1000  comparing with OR (|)  operation (like multip by 1)
		 // outis   0110|1000 Everything Change but our targeted bit in 8
		 //	outputs	(6)   (8)

	Mask = B1 << 2;  //shift all bits in B1 2 position to the left this has the same effect of B1 * 4 (shift compiles faster)
		cout << B1 << " Shifted left is " << (UInt) Mask << endl;
			 // bytloc  8421|8421
			 // before   (3)  (2)
			 // this is 0011|0100
			 // inputis 1101|0000  comparing with OR (|)  operation (like multip by 1)
			 // outis   1101|0000 Everything Change but our targeted bit in 8
			 //	outputs	(D)   (0)

	return 0;
}
// bytloc  8421|8421
	  // this is 1110|1001  in byte location 8.
	  // inputis 1111|0111  comparing with && operation (like multip by 1)
	  // outis   1110|0001  Everything Change but our targeted bit in
