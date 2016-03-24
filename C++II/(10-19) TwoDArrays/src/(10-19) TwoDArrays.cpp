//============================================================================
// Name        : (10-19).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void Sort (char [] [16], int); //when passing a two dimensional array, you must give it the number of columns
					//number in the Array needs to be a constant.

int main() {
	char Names [20] [16];  //for a 15 character array of string data,  we need 16 columns to include the /n end of string mark.
	int	NumNames;
	int i = 0;

	Sort (Names, NumNames);

	strcmp(Names [i], Names[i++]);//use stringcompare strcmp to compare 2 rows.
		//example tests of String compare.
		// x < 0
		// x == 0
		//	x > 0

		//strcpy(Names [i], Names [i++] (copies one array/string of chaacters to another)
		//

	return 0;
}


void Sort (char Names [] [16], int Num)
	{
	}

