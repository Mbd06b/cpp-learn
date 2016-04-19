//============================================================================
// Name        : StudentRecords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}


/*
 * Recommendation for building the class
 *
 * template <int Size>
 * class FLString : public string   // create a fixed length string
 * 		{
 *
 * 		}
 *
 *
 * 		So when you call the variable, you can set the limit on the digits when called...
 *
 * 		typedef FLString <3> Area Code;
 * 		typedef FLString <9> ID;
 *
 *
 * 	The program will need to sort by Name or ID number.
 * 	 We will need two different SORT methods in the student name class.
 *
 *
 *
 * 	When we write to a disk, Bill says that the easiest way to do that is one string at a time.
 * 	Example:
 *
 * Name-
	 * 	First
	 * 	Middle
	 * 	Last
  Address-
	 * 	Street
	 * 	City
	 * 	State
	 * 	Zip
  Phone-
	 * 	Area Code
	 * 	Phone NUmber
	 * 	ID
 */
