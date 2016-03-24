//============================================================================
// Name        : FunctionCalculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Mathproto.h"
#include <iostream>
#include <cstring>
using namespace std;

bool GetOperator (char Ops [], char a)
{

	int length;
	bool checker = false;

	length = strlen (Ops);

	for (int i = 0; i < (length);i++)
	{
		if (Ops [i] == a)
		{
		checker = true;
		}

	}
return checker;
}



bool ValidOperatorFunc (char a) {

	switch (a){
			case '+': a = true; break;
			case '-': a = true; break;
			case '*': a = true; break;
			case '/': a = true; break;
			case 'X': a = false; cout << "program ended "; break;
			case 'x': a = false; cout << "program ended "; break;
			case 'C': a = false; cout << "Cleared, ";  break;
			case 'c': a = false; cout << "Cleared, ";  break;

			default:
			a = false;

	}
 return a;
}

double Add (double a){
	cout<<"plugin a number"<<endl;
				double b;
				double c;
				cin >> b;
				c = a + b;
				cout << a << " + " << b << " = " << c << endl;
				return c;
}

double Subtract (double a){
	cout<<"plugin a number"<<endl;
			double b;
			double c;
			cin >> b;
			c = a - b;
			cout << a << " - " << b << " = " << c << endl;
			return c;
}

double Multiply (double a){
	cout<<"plugin a number"<<endl;
				double b;
				double c;
				cin >> b;
				c = a * b;
				cout << a << " * " << b << " = " << c << endl;
				return c;
}

double Divide (double a){
	cout<<"plugin a number (not zero)"<<endl;
				double b;
				double c;
				cin >> b;
				c = a / b;
				cout << a << " / " << b << " = " << c << endl;
				return c;

}


