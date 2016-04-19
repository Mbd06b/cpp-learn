/*
 * SortFunc.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: mbd06b
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "pCharSSort.h"
using namespace std;


char * Sort (char * Array [], int Counter) // x is our number of rows.
{
	char ** Temp;
	Temp = new char * [Counter];  //Allocated some memory for the temp swap.
	bool Sorted;


		do{

		Sorted = true;
		for (int i = 0; i < Counter - 1; i++) // -1 on the counter because we dont want to sort our /0 end of string mark
			{
				if (strcmp(Array[i], Array [i + 1]) > 0)  //what do I do if The element above is higher than the element below?
					{

					Temp [i] = Array [i];   //save the existing value
					Array [i] = Array [i + 1]; //swop the value
					Array [i + 1] = Temp [i]; //assign new value

					Sorted = false;
				}
			}
		}while (Sorted != true);

 		delete [] Temp; //Deallocating the memory from the swap to avoid leaks :)

return * Array;
}


