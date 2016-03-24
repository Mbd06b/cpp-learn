//============================================================================
// Name        : 10-05.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "dice.h";

int main() {  //void main() on Visual Studio

	int i;

	InitDice ();

	for (i = 0; i < 20; i++)
		cout << '\t' << ThrowDie () << endl;

	return 0;
}
