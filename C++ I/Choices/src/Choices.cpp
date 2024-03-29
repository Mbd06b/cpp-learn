//============================================================================
// Name        : Choices.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	long L1;
	long L2;
	long L3;
	long L4;


	cout << "Enter two whole numbers; " << endl;
	cin >> L1 >> L2;
		// < compares two values to see if first is less than the second
		// <= is the first less than or equal to the second
		// > is first greater than second
		// >= is first greater than or equal to the second
		// == is the first equal to second
		// != is the first different from the second

	if (L1 > L2) // what is inside the parenteses is checked for true false
			cout << L1 << "is less than " << L2 << endl;
	else  // test if false so do what follows
			cout << "is NOT less than " << L2 << endl;
	cout << "Done with if statement" << endl;

	if (L1 == L2)
			cout << L1 << " and " << L2 << " are equal " << endl;
	else
			cout << L1 << " and " << L2 << " are NOT equal" << endl;

	if (L1 < L2)
	{ 		// use { } if you want to do more than one statement in the
		L1 = L1 + 5;
		cout << "It was true" << endl;
	}

	else
	{
		L1 = L1 - 5;
		cout << "It was false" << endl;
	}

	if (L1 > L2)
			cout << "Greater than" << endl; // don't do anything if false
	cout << "Done with if" << endl;

	if (L1 > L2)
			cout << "Greater than" << endl;
	else; 	//optional to show that nothing is done if test is false
cout << "Done with if" << endl;

cout << "Enter two more numbers:  ";
cin  >> L3 >> L4;

if (L1 < L2)
		if (L3 == L4)
			cout << "Both tests are true" << endl;
		else;  // elses go with the closest if that is nearby
			    // putting a ; at the end of this else statement indicates that there is nothing to do if the test is false.

			cout << "First test is true, second is false" << endl;
else
	if (L3 > L4)
			cout << "First test is false, second is true" << endl;
	else
			cout << "Both tests are false" << endl;


if ((L1 == L2) && (L3 < L4))    // && means AND,  "if both of these things are true"
			cout << "Both sides are true" << endl;
		else
			cout << "At least one side is false, maybe both" << endl;


	L1 = 5;
	L2 = 10;
	if ((L1++ > 0) && (L2++ < 0))
			cout << "True and L1 is " << L1 << "and L2 is" << L2 << endl;
		else
			cout << "False and L1 is " << L1 << " and L2 is " << L2 << endl;


	L1 = -5;
	L2 = 10;
	if ((L1++ > 0) && (L2++ < 0))  // since L1++ is false, the C++ program is not even touching the L++ < 0 statement beause it doesn't need to, this is efficient programming known as Short Circuit Analysis
			cout << "True and L1 is " << L1 << "and L2 is" << L2 << endl;
		else
			cout << "False and L1 is " << L1 << " and L2 is " << L2 << endl;

	L1 = 5;
		L2 = 10;
		if ((L1++ > 0) || (L2++ < 0)) // || is OR, result is true if either side is true.
				cout << "True and L1 is " << L1 << "and L2 is" << L2 << endl;
			else
				cout << "False and L1 is " << L1 << " and L2 is " << L2 << endl;


			return 0;
}
