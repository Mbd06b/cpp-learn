//============================================================================
// Name        : (01-25).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MyString.h"

using namespace std;

void func (const MyString &);
void func1 (const MyString &);



int main() {

	MyString * pStrings;
	MyString str1; //Default Constructor

	MyString str2 ("abcdefg"); //Other Constructor

	MyString str3 (str2); //Copy Constructor; Str 3 is a copy of Str2
	MyString str4;

	//after the code above compiles, it goes away, this is known as "out of scope"

	cout << "\n 	Dynamic Strings \n" << endl;
	pStrings = new MyString [3]; //dynamically creates 3 MyStrings
	//but SINCE WE created the new MyString, rather than the constructors.
	//We need to delete them.

	delete [] pStrings;
	cout << "\n 	Ending Dynamic Strings\n" << endl;

	cout << "Calling func" << endl;
	func (MyString ("abcdefghi"));
	cout << "Back from func\n" << endl;

	//func1 (str2);

	str2.Compare (str1);
	str2.Compare ("abcdefg");

	str1.Copy (str3);

	str1.Copy (str1);

	str1.Len();

	//str1.Copy ("abcdefg"); //trynig to copy a C-type String. cannot do

	str1 = str3;  //THS IS USING THE OVERLOADED OPERATOR
	str1.operator = (str3); //THIS IS THE SAME THING AS THE LINE BEFORE


	cout << "String contains" << str1 << endl;

	cout << "MyStrings go out of scope" << endl;
	return 0;
}

void func(const MyString & Str){

	cout << "In Func" << endl;

};

void func1(const MyString & Str) {

	cout << "In func1" << endl;
}
