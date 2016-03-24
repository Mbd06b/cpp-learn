//============================================================================
// Name        : 09-23.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream> //a file name inside < > means the file is in the system folder
using namespace std;

#include "ReadInt.h" // #include copies the contenst of the named file into this one
#include "ReadInt.h" // A file inside the " " means the file is in the current folder
					// " " or < > simply tells the it where to look
					// you could put C:\\ ...\\...\\\..\\file.h  the entire folder tree
					// these are just simpler ways to do that.

// int ReadInt (); // this is a prototype, means that ReadInt is a function,
				// it gives back an int, functions can give back one thing (Not an Array [])
				// void means that it doesn't give back anything
				// what is inside the () tells what is given to the function
				// in our case we have nothing listed since the function will read from the keyboard
				// some people put void inside the () to mean nothing is sent to the function
				// Example:   int ReadInt (void);


int main()
{
	int	Num;

	do {
		cout << "Enter a whole number: ";
		Num = ReadInt ();
		cout << "You entered: " << Num << endl;

		}while (Num != -5); //run the do loop while the solution does not equal -5
	cout << "Bye" << endl;


	return 0;
}
