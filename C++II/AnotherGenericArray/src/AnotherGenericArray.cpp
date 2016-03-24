//============================================================================
// Name        : AnotherGenericArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Array.h"

int main() {


	Array <int, -3, 6 > A1; //the bounds are now part of my template argument.
	//-3, and 6 here are HARD CODED constants.
	//I cannot do the following because the bounds must be Constant Values
/*
 * int H = 3;
 * int L = 6;
 *
 * Array <int, L, H> A2;
 *
 */

	Array <int, 0, 9 > A3; //We haven't Indexed

	//A3 = A1;  THIS WILL NOT WORK, Because the template arguments are different. (Like assigning an int to a char).
	// Array < int, 10, -5>  A4; //compiler check this when it sets the array Data compile time, cannot be negative.
	Array <double, 0, 9>  A5;

	double X;
	double Y;
	X = 18.5;
//	A5.SetAt (3, X); // put value of X into array and returns ture or false.
//	A5.GetAt (5, Y); // puts the value of Y into arrayY.
	try {
		A1 [5] = 10;
	}
	catch (Array <int, -3, 6>::Exceptions e){

		cout << "We caught excetpions " << endl;
	}
	return 0;
}
