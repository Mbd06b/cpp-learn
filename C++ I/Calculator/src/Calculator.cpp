//============================================================================
// Name        : Calculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stdlib.h>   // needed so we can use exit (0) in the code below

int main() {

	int		Num1;
	int		Num2;
	char	Op;
	bool	ValidOperator;

	//  Get the starting number
	do	{					//Loop
			cout << ">  ";  //this is the waiting prompt
			cin >> Op;		//	Get the mathematical operator
			 //  YOU COULD CREATE AN TEDIOUS IF STATEMENT if ((Op == '+') || )(Op == '
			switch (Op)
			{
			case 'c':
			case 'C':
			case 'x':
			case 'X':
			case '+':
			case '-':
			case '*':
			case '/':
						ValidOperator = true;
						break;
			default:
						ValidOperator = false; // if operotor is not valid
						cout << "Invalid Operator" << endl; // issue message
			}
	}


	//	Check if the operator is valid,
	//		if not valid issue message "operator is not valid"
	//		then loop back to get another operator



	switch (Op)    // YOU COULD CREATE A SWITCH HERE INSTEAD OF MULTIPLE IF STATEMENTS
		{
	case 'x':
	case 'X': // if operator is 'x'- for end,
			//		stop the program

		}



	// if the operator is 'c' for "clear"
	// 		display a zero
	//		loop back to get another operator
	//
	//



	return 0;
}
