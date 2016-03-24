//============================================================================
// Name        : 10-5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// You have the entire class period
// Bring paper to write on. (no fringe on notebook paper)
// Bring pen or dark pencil (readability)
// Write on only one side of the paper
// Make sure your name is on your paper

// Test will cover what we have used in labs so far, will not include functions
// Test will consist of three types of questions
		//1. A C++ statement. You need to say whether the statement is valid or not.
		//					If valid, what does it do (what values are placed into variables)
		//					If not valid, what is wrong.
		//			For these questions, you will have  set of variables with initial values to be used in the statements.
		//			EX.  You have three int variables x,y, and z, and say x = 5. y=10, z=12.
		//			These values will be set before each statement.

		//			x *= 5;  	 valid, x is now 25.
		//			x = Y++; 	valid, x becomes 10, y becomes 11, (add one after the statement).
		//			x = ++Y;	 valid, y becomes 11, x becomes 11, (we added one before the statement).
		//			x = y++ + ++y; Valid, x becomes 22, y becomes 12
		//			++X = Y++;   INvalid, cannot do arithmatic on the left site of the = sign.
		//			X + 1 = 5;  INvalid, still cannot do math on the left side of the = sign.
		//			if (x = y); z = -1; else z = 1;  Valid, x becomes 10 (which because it's NOT a Zero), is TRUE,  so z is assigned -1.
		//			char A [] = "abcdefg" ; // valid, A is an 8 slots in ASCII code,  because we used "" there is automatically an end of string mark \0
											// listed 7 characters followed by \0 (end of string) mark.

		//2. Groups of vaild statements.  You must show what the statements print on the screen.
		//
		//
for (int i = 0; i < 10; i += 2)
	cout << i++ << endl;

	// 0   (after run through i + 1)
	// 3	i is 1 which then adds 2, prints 3, one is added again.
	// 6	i is 4 which then add 2, prints 6, one is added again.
	// 9   Stops here because the next iteration  is higher than 10.

int a;
int b;
int c;

a = 7;
b = 3;
c = (a + 4.0) / (b - 1) + 0.4;
cout << "the result is: " << c << endl:

		// the result is 5.

			//3.  Third type of question will be a description of what something is to do,
			// 	and you write the code.

							//  write a loop to dispaly ll integers that are mltiples of 7 between 100 and 200.

					int i;
					for (i = 100; i <= 200; i++)
						if ((i % 7) == 0)
							cout << i << endl;

			// Bill will not ask for a particular type of loop for these questions. But He may ask us to use a switch.

							//write a loo that will
							//	 read a character from the keyboard
							// say if it is uppercase
							// if it is 'x', stop the loop.

				char A;

				do {
					cin >> A;

					if ((A >= 'A') && (A <= 'Z'))
						cout << A << "is upper case" << endl;
					else
						cout << A << "is lowercase" << endl;

					} while (A != 'x')

					//for both upper & lower } while ((A != 'x') && (A != 'X'));



#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
