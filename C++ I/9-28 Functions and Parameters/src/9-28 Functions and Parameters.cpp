//============================================================================
// Name        : 9-28.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Functions.h"
#include "Array_Functions.h"

int main() {

		int	A;
		int	B;
		int C;
		int D;
		double Q;
		double R;
		double S;
		long	W;
		long	X;
		long	Y;

		A = 5;
		B = 8;
		C = Add (A,B); //ADD function should go to the Funtions.h header file, and Add (int, int) b
		cout << "A is " << A << "B is " << B << "C is " << C << endl;

		Q = 1.5;
		R = 1.8;
		S = Add (Q, R);
		cout << "Q is " << Q << "R is " << R <<  "S is " << S << endl;

		W = 1.5;
		X = 1.8;
		Y = Add (W, X);
		cout << "W is " << W << "X is "<< X << "Y is " << Y << endl;

		Y = Add (5, 10);
		cout << "Y is " << Y << endl;

	/*	cout << "Func1" << endl;
		C = Func1 (A, C);              //error here
		cout << "A is " << A << "C is " << C << endl;

		cout << "Func2 " << endl;
     */

		A = 10;
		B = 3;
		C = Divide (A, B, D);
		cout << A << "A is " << "B is" << B << ", Remainder is " << D << endl;



		int	Array1 [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int Array2 [20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

		A = Avg (Array1, 10);
		cout << "Average 1 is: " << A << endl;
		A = Avg (Array2, 20);
		cout << "Average 2 is: " << A << endl;
		A = Avg (Array2, 6);
		cout << "Average 3 is: " << A << endl;


		char String [] = "abcdefghijklmnopqrstuvwxyz";
		cout << "Number of vowels is " << CountVowels (String) << endl; // Should output 5


	return 0;
}
