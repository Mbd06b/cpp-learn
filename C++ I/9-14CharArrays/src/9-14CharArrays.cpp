//============================================================================
// Name        : 9-14CharArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <string.h>; //needed to work the strcmp function to compare arrays

int main() {


	const	int MaxCharsInName (20); //
			char	Name1 [MaxCharsInName + 1] = {'B', 'i', 'l', 'l', '\0'};
										// \0 is a special character called the End-Of-String mark
										// used to tell cout and other things when the have reached the last character to work with
			int		Grades [5] = {49, 55, 77, 88, 65};
			char	Name2 [MaxCharsInName + 1] = "George"; //short cut to set the End-of-String mark \0'

	// char arrays that have a \0 in them are referred to as C-Type strings

	cout << "Name1 is "	<< Name1 << endl;  //'B' - prints out the ASCII key number for
	cout << "Grades are" << Grades << endl; // printing any other type of array shows the address of the array using hexadecimal number system

	Name1 [1] = 'I';
	cout << "Name1 is "	<< Name1 << endl;  // prints out the ASCII key number "I", changing i above to I.
	cout << "Name2 is "	<< Name2 << endl; // prints out "George"

	if (Name1 < Name2)  // when using arrays, comparisons will end up comparing  addresses gibberish
			cout << Name1 << " is before " << Name2 << endl;
	else
			cout << Name1 << " is NOT before " << Name2 << endl;

	// to actually compare the arrays

	if (strcmp (Name1, Name2) < 0)  //  strcmp gives a negative value if first array comes first in the ASCII code table
		cout << Name1 << " is before " << Name2 << endl;
			else
					cout << Name1 << " is NOT before " << Name2 << endl;

	strcpy (Name1, "MEGAN"); //copy the chars MEGAN into array Name1
	strcpy (Name2, "george"); // copy the chars george into array Name2
	if (strcmp (Name1, Name2) < 0)  //  strcmp gives a negative value if first array comes first in the ASCII code table
		cout << Name1 << " is before " << Name2 << endl;
			else
					cout << Name1 << " is NOT before " << Name2 << endl;
	if (_strcmpi (Name1, Name2) < 0)  //  _strcmpi says treat upper and lower case letters the same
		//gcc compiler might actually name _strcmpi,  strcomparecase??, they do the same things, but are different on xcode and gcc
			cout << Name1 << " is before " << Name2 << endl;
				else
						cout << Name1 << " is NOT before " << Name2 << endl;

	return 0;
}
