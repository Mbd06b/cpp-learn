//============================================================================
// Name        : 02-15Exceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Exception{

	int Number;
	int LineNumber;
};

void Func1 (int) throw (...);
void Func2 (int) throw (...);// if there is a potential to have a throw in the function.  throw (...) just lets people know that Func2 might throw an exception.


int main() {

	try{
		Func1 (5);
		cout << "Normal Finish to Try Block" << endl;

	}
	catch (int e){ //you can catch one parameter, if you want to do more, you need to pass a class.

		if (e < 0)
			cout << "You used a negative number " << e << endl;
		else
			cout << "You put in the odd number " << e << endl;
	}
	catch (Exception e){
		cout << "Odd number " << e.Number << " on line " << e.LineNumber << endl;
	}

	cout << "Finished Program";

	return 0;
}



void Func1 (int i){

	char * pChar;

	try {
		pChar = new char [128];
		//do stuff
		Func2 (i);
		delete [] pChar;
		cout << "Normal Finish to Func1" << endl;
		}

	//THIS ALLOWS US TO DELETE DYNAMIC MEMORY if the Trigger, and you are tossed out of the function before dynamic memory is deleted.
	catch (...) { // this catches anything that may be thrown

		delete [] pChar;
		cout << "Catch is Finishing Func1" << endl;
		throw; //by itself, throw inside a catch, throws whatever was caught
	}

}

void Func2 (int i){

	if ((i % 2) == 0){
		cout << "Positive and Even" << endl;
	}
	else
	{
		Exception E;
		E.LineNumber = __LINE__;
		E.Number	 = i;
		throw E;

	}
	cout << "Normal Finish to Func2" << endl;
}
