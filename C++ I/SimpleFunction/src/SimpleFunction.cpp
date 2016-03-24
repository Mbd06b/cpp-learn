//============================================================================
// Name        : SimpleFunction.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


bool a;
int i;

int main ()
	{

		char	ValidOperators [] = "+-*/XxCc";
			for (int i = 0; i < 7; i++)
			{
				switch (ValidOperators [i])
				{
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
				} cout << a << endl;
			}
	cout << "End Program" << endl;
		return 0; }


