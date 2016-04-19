//============================================================================
// DESCRIPTION : Program 11, CharSort Lab
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/28/2015
//============================================================================


#include <iostream>
#include <string.h>

#include "CharSSort.h"
using namespace std;

int main() {

		int Rows;
		const int Cols = 16; //max char in name 15 + 1 for end of string mark
		bool Test = false;
		int Validation = 0;
		char *a; //a pointer to pass the values of our array.


//------------------------------TEST FOR ROWS (How many names), cannot be > 0 or < 20. MAXIMUM IS 20--------------------------------------
	do
	{
		cout << "Enter how many Names you want to enter (max 20): " << endl;
		cin >> Rows;


		if (Rows > 20 )
		{
			cout << "You can't enter more than 20.  Try again." << endl;
			Test = false;
		}
		else if (Rows <= 0)
		{
			cout << "Enter a valid number" << endl;
			Test = false;
		}
		else
		{
		Test = true;
		}
	}while (Test == false);// end while loop, we've confirmed the number of names in our array.


cout << "Enter " << Rows << " Names: " << endl;


// Create the Array, after getting my Row/Cols values to avoid memory issues.
char Array [Rows] [Cols];

//-----------------------------Loop to input our names, is dynamic based on how many rows chosen------------------------
		for (int i = 0; i < Rows; i++)
			{
			cout << ">";
			cin >> Array [i];

					if (strlen (Array [i]) > 15)
					{
					cout << "Your name is to large, needs to be 15 characters or less" << endl;
					--i;
					--Validation;
					}


					Validation++;
					cout << "(" << Validation << " of " << Rows << ")";
					cout << endl;

			}


cout << endl;

			cout << "Unsorted names are " << endl;
				for (int i = 0; i < Rows; i++)
				{
				cout << Array [i] << ", ";
				}
cout << endl;

	Sort (Array, Rows);


return 0;
}
