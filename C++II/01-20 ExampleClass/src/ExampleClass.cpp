/*
 * ExampleClass.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: mbd06b
 */


#include "ExampleClass.h"

//  ::  is telling the compiler that SetB is the 'class' called "Example"
// :: is the 'Membership Operator', Set B belongs to the class called Example.


bool Example::SetB (int i)
{
	if (i & 1){  //if i is an odd number we cannot use it   NOTE: single & is a (Bitwise &)  Works faster than remainder operator
		return false;
	}

	else {
		B = i;
		return true;
	}

}


//Notes single & is a bitwise operator
// 		Say an number is there
//		 110011101  <-- the last digit is a 1
// 		 000000001  <-- the & operator compares the bits for true false.
//result 000000001 <-- result is 1 the bit number value is odd.

