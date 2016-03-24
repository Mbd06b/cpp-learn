//============================================================================
// Name        : 03-21Static.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Functions.h"
#include "MyClass.h"
using namespace std;

int Func2();

extern int Global; // extern means that this variable is declared in another .cpp file.



int main() {


	cout << "Func1 gives back " << Func1() << endl;
	cout << "Func1 gives back " << Func1() << endl;
	cout << "Func1 gives back " << Func1() << endl;

	cout << "FUnc2 Gives back " << Func2() << endl;

	cout << "Global has the value of " << Global << endl; //cannot access Global unless extern int Global: is declared.


	//cout << "Test1.B has the value " << Test1.GetB() << endl;  //cannot call function without substatiating the object first.
	cout << "Test1.B has the value " << Test1::GetB2() << endl; //can call static variable
	Test1 T1;
	cout << "MyClass.B has the value of " << T1.GetB() << endl;
	Test1 T2; //uses the same B that T1 uses.




	return 0;
}

int Func2 (){
	return -1;
}
