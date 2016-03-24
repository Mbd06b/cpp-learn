//============================================================================
// Name        : 09-16MoreCharArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const	long	MaxCharsPerLine (80);
			char	Line [MaxCharsPerLine +1];
/*
	cout << "Enter a line of text\n>";
	cin >> Line;
	cout << "You entered: " << Line << endl;

	cout << "Do another: ";
		cin >> Line;
		cout << "You entered: " << Line << endl;

	cout << "And another: ";
		cin >> Line;
		cout << "You entered: " << Line << endl;

*/

		// Use cin.getline  will help with problems of the code above, like dropping spaces _ when inputting a string or going over the Max Characters set (80).
	cout << "Enter a line of text\n>";
	cin.getline (Line, MaxCharsPerLine + 1);  // give it the array and the number of characters
	cout << "You entered: " << Line << endl;
	cin.clear ();  //put this after .in.getline if you want to keep reading any text
					//typed when the user types too many characters



	return 0;
}
