//============================================================================
// Name        : 02-08GenericArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

#include "GenericArray.h"

template <class T> //If you are going to write a stand alone template outside the header file, it has to go before your statement.
	void Func (const Array <T> & A){
	cout << A [4] << endl;
}

int main() {

	Array <int> 	IA1 (-5,5);
	Array <double>  DA1;
	Array <> 		XA1; //because of the default temlate argument, this is an array of int.
	Array <Array <int> > IA2D (-5,5); //an array of Arrays.
	int j;

	j = 1;
	for (int i = -5; i <= 5; i++, j++){ //Resizes the Inside Array.
		IA2D [i].Resize (j , j * 3);
	}

	IA1 [-3] = 111;
	cout << IA1 [-3] << endl;

	//Template CLASS Method does not compile on Visual Studio until it's called.
	//IA1.Func ();  EXAMPLE OF AN INVALID

	Func (IA1);

	//IA1 = DA1; // cannot do, NOT THE SAME DATA TYPE <int to double>.
	XA1 = IA1; //works, because the default contstructor is an int.



	return 0;
}


