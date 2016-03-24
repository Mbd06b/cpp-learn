//============================================================================
// Name        : 02-03.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IntArray.h"
using namespace std;

void Func (const IntArray & IA);

int main() {

	IntArray A1; //compiler changes this to A1 (0,0);

	IntArray A2 (-5,5); //compiler inputs (-5,5) instead of our default (0,0) value.

	A2 [-3] = 999;

	cout << "Value is" << A2 [-3] << endl;

	cout << "Value is" << A2 [-3] << endl;
	Func (A2);

	return 0;
}

void Func (const IntArray & IA){
	cout << "Vaule is " << IA [-3] << endl;
}
