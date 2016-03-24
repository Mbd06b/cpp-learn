//============================================================================
// DESCRIPTION : Program Eight, Function Calculator
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/16/2015
//============================================================================



#include <iostream>
#include "Mathproto.h"

using namespace std;

#include <stdlib.h>		// needed if you want to use exit (0) in the code below


int main()
{
	char	Op;
	bool	Check;
	bool	ValidOperator = true;
	double     num1   = 0;
	int     result = 0;
	int     swap   = 0;
	char	ValidOperators [] = "+-*/XxCc";

	cout << " put in a  number" << endl;
	cin >> num1;

for(;;)
{
	do	{
		cout <<"Please put in an operator (+,-,*,/,X,x,C,c)"<<endl;
		cin >> Op;

		Check = GetOperator (ValidOperators, Op);
		if (Check != true)	{cout << " Not an Operator" << endl;}

		switch (Op)
			{
			case '+': result = Add (num1); break;

			case '-': result = Subtract (num1); break;

			case '*': result = Multiply (num1); break;

			case '/': result = Divide (num1); break;

			case 'x':
			case 'X':  exit (0);	 break;

			case 'c':
			case 'C':
						num1   = 0;
	                    result = 0;
                        swap   = 0;
						ValidOperator = true;
						break;
			default:
						ValidOperator = false;

			}
		} while (!ValidOperator);


	for(;;)
	{
	swap = result;
	num1 = swap;


		cout <<"Please put in an operator (+,-,*,/,X,x,C,c)"<<endl;
			cin >> Op;


			Check = GetOperator (ValidOperators, Op);
			if (Check != true)	{cout << " Not an Operator" << endl;}

			switch (Op)
				{
				case '+': result = Add (num1); break;

				case '-': result = Subtract (num1); break;

				case '*': result = Multiply (num1); break;

				case '/': result = Divide (num1); break;

				case 'x':
				case 'X':  exit (0);	 break;

				case 'c':
				case 'C':
							num1   = 0;
		                    result = 0;
	                        swap   = 0;
							ValidOperator = true;
							break;
				default:
							ValidOperator = false;

				}
			} while (!ValidOperator);

}

return 0;
	}
