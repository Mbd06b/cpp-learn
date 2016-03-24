//============================================================================
// DESCRIPTION : Program 10, Sort Lab
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/21/2015
//============================================================================

/* -------------_NOTES: When You Pass In An Array to Compare Your Names IN A FUNCTION ----------------------------------
Sort (char Names [][16], int NumNames)  //16 here is that you need to give the # of columns to the function on a 2d Array.
{
	char Temp [16], //
		if (strcmp( Names [i] , Names [i++]) ...
}
*/

#include <iostream>
#include "SSort.h"
using namespace std;

int main() {

		int ArraySize;
		int Array [ArraySize];
		bool Test;
		int Validation = 0;


	while (Test == false)
	{
		cout << "Enter how many whole numbers you want to enter (max 20): " << endl;
		cin >> ArraySize;


		if (ArraySize > 20 )
		{
			cout << "You can't enter more than 20.  Try again." << endl;
			Test = false;
		}
		else if (ArraySize <= 0)
		{
			cout << "Enter a valid number" << endl;
			Test = false;
		}
		else
		{
		Test = true;
		}
	}// end while loop


		cout << "Enter " << ArraySize << " Numbers: " << endl;



			for (int i = 0; i < ArraySize; i++)
			{
			 cin >> Array [i];
			 Validation++;
			 cout << " ("<< Validation << " of " << ArraySize << ")";
			 cout << endl;
			}

cout << endl;

			cout << "Unsorted array is " << endl;
			for (int i = 0; i < ArraySize; i++)
			{
			cout << Array [i] << ", ";
			}

cout << endl;

		Sort (ArraySize, Array);


//	Sort (Array);
		cout << "Sorted array is  " << endl;
		for (int i = 0; i < ArraySize; i++)
					{
					cout << Array [i] << ", ";
					}


return 0;
}
