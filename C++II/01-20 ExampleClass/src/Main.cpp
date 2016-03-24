//============================================================================
// Name        : 01-20.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ExampleClass.h"

using namespace std;

int main() {

	Example E;

	cout << E.A << " This is the invalid value of E" << endl;  //if we haven't set A,  this would give us a invalid value.

	E.A = 5;  //Assigning the value by pointing to the A object(Variable) in Example class E.

// "B" is a private member that can't be accessed here
	//E.B = -5;
//
	E.SetB (-6); //passing -5 to SetB.

//		cout << E.B << endl; wont let you do this because B is still private.

	cout << E.GetB () << endl;


	return 0;
}
