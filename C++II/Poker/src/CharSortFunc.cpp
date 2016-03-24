/*
 * SortFunc.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: mbd06b
 */
#include <iostream>
#include <string.h>
#include "CharSSort.h"
#include "Card.h"
using namespace std;


void Sort (Card Hand []) // x is our number of rows.
{
	bool Sorted;
	Card TempArray [5];

	do
	{
	Sorted = true;
	for (int i = 0; i < 5; i++)
		{
			if (Hand [i].Value > Hand [i + 1].Value)  //what do I do if The element above is higher than the element below?
			{
			TempArray [i] = Hand [i];   //save the existing value
			Hand [i] = Hand [i + 1]; //swop the value
			Hand [i + 1] = TempArray [i];  // assign the new value
			Sorted = false;
			}


		}


	}while (!Sorted);


}


