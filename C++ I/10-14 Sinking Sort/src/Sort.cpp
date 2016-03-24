/*
 * Sort.cpp
 *
 *  Created on: Oct 14, 2015
 *      Author: mbd06b
 */


#include "SinkingSort.h"
#include <string.h>

void Sort (char X [])
	{

	 size_t i;
	 size_t	NumElements; //size_t is a shortway of calling this an unsigned int, because the value will never be negative.
	 bool	Sorted;
	 char	Temp; // a temporary place to store our information as we sort.

	 NumElements = strlen (X); //returns length of array, ONLY because Array ends with the \n end of string mark due to " " quotation marks.
	 do{
		Sorted = true;
		NumElements-- ; //NumElements -- we are subtracting 1 from our array, because we don't want the last elment in our array to analyze an unkwn value beyond our array
		for (i = 0; i < NumElements; i++)
		{
			if (X [i] > X [i + 1])  //what do I do if The element above is higher than the element below?
			{
			Temp = X [i];   //save the exsiting value
			X [i] = X [i +1]; //swop the value
			X [i +1] = Temp;  // assign the new value
			Sorted = false;
			}
		 else
		 	 {
		 	 }
		}
	  }while (!Sorted);//END DO LOOP  ! Is NOT, so !Sorted is Not-Sorted.
	}
