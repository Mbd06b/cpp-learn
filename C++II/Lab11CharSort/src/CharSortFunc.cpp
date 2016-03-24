/*
 * SortFunc.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: mbd06b
 */
#include <iostream>
#include <string.h>
#include "CharSSort.h"
using namespace std;


void Sort (char Array [][16], int x) // x is our number of rows.
{

	bool Sorted;
	char TempArray [x][16];

	do
	{
	Sorted = true;
	for (int i = 0; i < x; i++)
		{

				if (strcmp(Array[i], Array [i + 1]) > 0)  //what do I do if The element above is higher than the element below?
				{
				strcpy(TempArray [i], Array [i]);   //save the existing value
				strcpy(Array [i], Array [i + 1]); //swop the value
				strcpy(Array [i + 1], TempArray [i]);  // assign the new value
				Sorted = false;
				}
			}
	}while (!Sorted);


	cout << "Sorted names are " << endl;
			for (int i = 0; i < x; i++)
			{
			cout << Array [i] << ", ";
			}
}



