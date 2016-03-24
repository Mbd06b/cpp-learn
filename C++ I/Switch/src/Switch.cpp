//============================================================================
// Name        : Switch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
	{
	long	L1;

	cout << "Enter a whole number: " << endl; //
	cin >> L1;

	switch (L1)		//the value inside the ( ) must a be a whole number value
		{		// a switch must have {},  cases can be put in any order, order does not matter
	case -1:								//do what follows when the value is 1
				cout << "Minus one" << endl;
				break;			// break means we are done with this case, without the break it continues to the next case
	case 0:			// a case has to have a constant as a value, cannot be a variable
				cout << "Zero" << endl;
				break;
	case 1:
				cout << "One" << endl;
								// we didn't put a break here because we are done
		}

	cout << "Done with switch" << endl;

	char	C;
	cout << "Enter a character: ";
	cin >> C;

	switch (C)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
					cout << "Got a vowel " << endl;
		default:		// do this if none of te cases match your values
					cout << "Not a vowel" << endl;

	}
		cout <<"Done with second switch" << endl;

	switch (L1 > 5)
		{
	case true:
			cout << "True" << endl;
			break;

			cout << "False" << endl;
			break;


		}

	return 0;
	}
