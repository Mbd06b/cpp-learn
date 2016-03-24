//============================================================================
// DESCRIPTION : Programming Excercise Five, build a simple Calculator Lab5Calculator.cpp
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 09/16/2015
//============================================================================


#include <iostream>
using namespace std;
#include <stdlib.h>;

int main()
{
	char	Op;
	bool	ValidOperator = true;
	int		Num1 = 0;
	int		Num2 = 0;
	int		result = 0;
	int		swap = 0;



	cout << "Welcome to calculator." << endl;
cout << "Enter Your first number: " << endl;
		cout << "> "; //puts a little prompt to type something
			cin >> Num1;    //Get first number

for (;;)
	{

		do
		{
		cout << "Enter your operator (+,-,*,/, C or X) : " << endl;
		cout << "> ";
			cin >> Op;		//Get Operator

		switch (Op)
			{

			case '+': // addition operator
			cout << "enter a number: " << endl;
				cout << "> ";
				cin >> Num2;    //Get second number
				result = Num1 + Num2;
				cout << Num1 << " + " << Num2 << " = " << result << endl;
				break;

			case '-': //subtraction operator
				cout << "enter a number: " << endl;
				cin >> Num2;
				result = Num1 - Num2;
				cout << Num1 << " - " << Num2 << " = " << result << endl;
				break;

			case '*': //multiplication operator
				cout << "enter a number: " << endl;
				cin >> Num2;
				result = Num1 * Num2;
				cout << Num1 << " * " << Num2 << " = " << result << endl;
				break;

			case '/': //division operator
				cout << "enter a number (not zero): " << endl;
				cin >> Num2;
				result = Num1 / Num2;
				cout << Num1 << " / " << Num2 << " = " << result << endl;
				break;

			case 'x': //exit
			case 'X': //exit to capture the uppercase
				exit (0);
				break;

			case 'c': //clear
			case 'C': //clear to capture the uppercase
				Num1 	= 0;
				Num2	= 0;
				result	= 0;
				swap	= 0;
				ValidOperator = true;
				break;

		default:
				ValidOperator = false; //if the operator is not vaild
				cout << "Invalid Operator" << endl;
			}
		}while (!ValidOperator); //Loop back to get another operator "!" is saying "NOT valid operator"

	}

for(;;)
	{

	swap = result;  //defines swap as result
	Num1 = swap;    //defines Num1 as swap (which is the result)

			cout << "Enter your operator (+,-,*,/, C or X) : " << endl;
			cout << "> ";
			cin >> Op;		//Get Operator

			switch (Op)
				{

				case '+': // addition operator
				cout << "enter a number: " << endl;
					cout << "> ";
					cin >> Num2;    //Get second number
					result = Num1 + Num2;
					cout << Num1 << " + " << Num2 << " = " << result << endl;
					break;

				case '-': //subtraction operator
					cout << "enter a number: " << endl;
					cin >> Num2;
					result = Num1 - Num2;
					cout << Num1 << " - " << Num2 << " = " << result << endl;
					break;

				case '*': //multiplication operator
					cout << "enter a number: " << endl;
					cin >> Num2;
					result = Num1 * Num2;
					cout << Num1 << " * " << Num2 << " = " << result << endl;
					break;

				case '/': //division operator
					cout << "enter a number (not zero): " << endl;
					cin >> Num2;
					result = Num1 / Num2;
					cout << Num1 << " / " << Num2 << " = " << result << endl;
					break;

				case 'x': //exit
				case 'X': //exit to capture the uppercase
					exit (0);
					break;

				case 'c': //clear
				case 'C': //clear to capture the uppercase
					Num1 	= 0;
					Num2	= 0;
					result	= 0;
					swap	= 0;
					ValidOperator = true;
					break;

			default:
					ValidOperator = false; //if the operator is not vaild
					cout << "Invalid Operator" << endl;
				}
			}while (!ValidOperator); //Loop back to get another operator "!" is saying "NOT valid operator"


return 0;
}

