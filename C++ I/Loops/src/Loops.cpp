//============================================================================
// Name        : Loops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//
//============================================================================

#include <iostream>
using namespace std;

int main()
	{
	short	S1;

	S1 = 0;
	do {	// curly braces { } are required when writing a Do-While loop
		S1++;

	cout << '\t' << S1 << endl;   // \t  is tab over
	S1++; //add one

		} while (S1 > 0);   // check each time after doing the loop and if true, do it again
	cout << "Completed Do-While loop" << endl;





	unsigned short	US1;

	US1 = 0;
	cout << "n\n\t Do-While ASCII codes" << endl;

	do {
		cout << "ASCII code " << US1 << "represents the character "<< (char) US1 << endl;
		US1++;
	}  while (US1 <= 255);  // since test is at the bottom, the loop is always




	US1 = 0;
	while (US1 <= 255) // the test is at the top, if false to start, don't do this
		{			// like an if statement, only need { } curly braces if we have more than one statement
		cout <<"ASCII code" << US1 << " represents the character " << (char) US1 << endl;
		US1++;
		}





// for (init part ; test part ; increment part)
// 			init part is done once before the loop starts
//			test is like a while loop and is done at the top of each loop, if false to start, don't do the loop at all
//			increment statement is the last thing done each time through the loop
//			Like an if statement, only need { } if we have more than one statement inside the loop


		cout << "\n\n\t For loop with ASCII codes" << endl;
		for (US1 = 0; US1 <= 255; US1++)
			{
				cout << "ASCII code " << US1 << "represents the character" << (char) US1 << endl;

// while loops and do-while loops MUST have a test
// a for loop can leave off the test and it will always be considered true
			}


		// THIS IS BAD PROGRAMMING PRACTICE THAT YOU MIGHT RUN ACCROSS
		// goto
		// goto  is bad practice because it will "goto" whatever is described, but it can go ANYWHERE in your code
		// you  lose your place if your goto is buried in a million lines of code.

		US1 = 0;
		Label1:
			cout << "ASCII code " << US1 << "represents the character " << (char) US1 << endl;
			US1++;
			if (US1 <= 255)
					goto Label1;
				else;
		cout << "Done with goto" << endl;


	return 0;
}
