//============================================================================
// Name        : 9-30FunctionswithVariables.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Functions.h"

int		X;  //these variables are outside of all our functions.
int		Y; 	// these are known as global variables
			// if you do not initialize a global variable, the compiler will set it to zero.
			// global variables are a little bit faster than parameters

int main() {

	int		i; // this i can only be used inside main (different than the 'i' in the function)
	int		x;
	int		y;

	for	(i = 0; i < 5; i++)
		cout << "Func1 returned " << Func1 () << endl;

	for	(i = 0; i < 5; i++)
		cout << "Func2 returned " << Func2 () << endl;


		x = 5;
		y = 8;
		cout << "Func3 returned " << Func3 (x, y) << endl;


		x = -5;
		y = -8;
		cout << "Func4 returned " << Func4 () << endl;

	return 0;
}
