//============================================================================
// DESCRIPTION : Programming exercise one to print author's name
// CLASS:      : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 08/31/2015
//
//============================================================================

#include <iostream>
using namespace std;

int main() {
	long	L1; //creates the "bucket"
	long 	L2;



	cout << "Enter two whole numbers: " << endl;  // prints the request for two numbers
	cin >> L1 >> L2;


	cout <<"The numbers you entered were: "<< L1 << " and " << L2 << endl;
	cout <<"The sum of the two numbers is: " << L1 + L2 << endl;
	cout <<"The result of first number divided by the second number is: " << L1 / L2 << endl;
	cout <<"The remainder of the first number divided by the second number is: " << L1 % L2 << endl;
	cout <<"The result of the first number times the second number is: " << L1 * L2 << endl;
	cout <<"The result of the first number minus the second number is: " << L1 - L2 << endl;

	double	L3; //double is supposedly more accurate than "float" operator see stackoverflow.com search "Difference between and float and double"
	double	L4;

	cout <<"Enter two fractional numbers: "<< endl;
	cin >> L3 >> L4;

	cout <<"The numbers you entered were: " << L3 << " and " << L4 << endl;
	cout <<"The sum of the two numbers is; " << L3 + L4 << endl;
	cout <<"The result of the first number divided by the second number is: " << L3 / L4 << endl;
	cout <<"The result of the first number times the second number is: " << L3 * L4 << endl;
	cout <<"The result of the first number minus the second number is: " << L3 - L4 << endl;







	return 0;
}
