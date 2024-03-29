//============================================================================
// DESCRIPTION : Lab Five  C++II ToUpper Inheritance Class, with myStringClass.
// CLASS       : COSC 1437.S02 – Lab 4
// AUTHOR      : Matthew Dowell
// DATE        : 04/06/2015
//============================================================================

#include <iostream>
#include "UCString.h"
#include "DigitString.h"

using namespace std;

int main() {


	UCString A2 ("charlie");

	UCString A3;

	String A4 ("Johnny");

	cout << A2 << endl;

	cout << "Assign = " << endl;
	A3 = A2;

	cout << A3 << endl;

	A3 = A4;

	cout << "I'm assigning something" << endl;
	cout << A3 << endl;

	cout << "Changing a char to x lowercase: " << endl;
	A3.setAt('x',4);
	cout << A3 << endl;

	cout << endl;
	cout << "Concat test" << endl;
	A2 &= A4;
	cout << A2 << endl;


	cout << endl;
	cout << "Exception test, loading digitString with invalid characters" << endl;
	try{
	  //  digitString DStest ("12afc25");
	    digitString DStest4 ("12345");

	    DStest4 &= A2;

	    cout << DStest4;
	}
	catch(invalid_argument& e){
	    cout << "testdigitString class can only accept digits" << endl;
	}

	cout << endl;
	cout << "Loading digitString with digits, and running through Concat, and Assignment tests." << endl;

	try{
		digitString DStest2 ("987654321");
		digitString DStest3;


		DStest3 = DStest2;

		DStest3 = "123456789";

		DStest3 &= DStest2;

		DStest3 = "abcdefg";

		cout << "Valid digitString Tests worked without exception: " << endl;
		cout << "DSTest3 is: " << DStest3 << endl;

	}catch(invalid_argument& e){
	    cout << "testdigitString class can only accept digits" << endl;
	}


	return 0;
}
