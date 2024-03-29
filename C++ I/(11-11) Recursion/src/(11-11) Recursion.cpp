//============================================================================
// Name        : (11-11).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int Factoral (int); //prototype 5! = 5 X 4 X 3 X 2 X 1
int Fibonacci (int); // 1, 1, 2, 3, 5, 8, 13, 21, 34


int main() {

	cout << "Factoral of 8 is " << Factoral (8) << endl;
	cout << "Fibonacci position 9 is " << Fibonacci (9) << endl;

	return 0;
}



int Factoral (int n)  //function
{
	if (n == 0)
		{
			return 1; //anything by factorial 0! is 1. THIS PREVENTS AN INFINATE LOOP
		}
	else
	   {
		return n * Factoral (n - 1);
	   }
}


int Fibonacci (int n) // function
{
	if (n < 2)
		{
			return 2; // the 1, 1, in the.. . 1, 1, 2, 3, 5, 8 ... sequence. THIS PREVENTS AN INFINATE LOOP
		}
	else
		{
		return Fibonacci (n - 1) + Fibonacci (n - 2);
		}

}
