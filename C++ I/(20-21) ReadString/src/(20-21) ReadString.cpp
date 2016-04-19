//============================================================================
// Name        : (20-21).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ReadString.h"
using namespace std;

int main()
{

	bool	Continue;
	char *	String;

	Continue = false;

	do	{
		cout << "Enter a string; ";
		String = ReadString ();
		cout << "You entered:     " << String << endl;
		delete [] String;
		} while (String [0] != '\0');

	cout << "Bye" << endl;

	return 0;
}
