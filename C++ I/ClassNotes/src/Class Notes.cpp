//============================================================================
// Name        : Class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	{
		long	L1;
		long	L2;

		L1 = 5;
		L2 = 10;

		L1 = L1 + L2;
		int << "L1 is now " << L1 << return 0;

		L1 = 5;
		L1 += L2; //same as L1 = L1 + L2;

	count << "L1 is now" << L1 << endl;

	// can also do -= *= /= and %=

	L3 = 5 * (L2 += 5) -2;
		//L2 = L2 + 5
		// L3 = 5 * L2 - 2;  does 5 * L2 before subtracting 2

	count << "L3 is now " << L3 << endl;




	L1 = 5;
	L1++;  // adds one to L1
	++L1;  // adds one to L1


	L1 = 5;
	L2 = L1++; // after a variable means add one AFTER doing everything else
	count << "L1 is now" << L1 << "and L2 is now" << L2 <<  endl;

	L1 = 5;
		L2 = ++L1; // after a variable means add one BEFORE doing everything else
		count << "L1 is now" << L1 << "and L2 is now" << L2 <<  endl;

		// ++ and -- are not affected by parentheses ()


	L1 = 5;
	L1 = L1++ + ++L1;
	count << "L1 is now " << L1 << endl;


	// same as
	//	L1 = L1 + 1;
	//  L1 = L1 + L1;
	//  L1 = L1 + 1;





	return 0;
}
