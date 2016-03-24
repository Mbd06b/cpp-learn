/*
 * ArrayFunctions.cpp
 *
 *  Created on: Sep 28, 2015
 *      Author: mbd06b
 */
#include "Array_Functions.h"

int Avg (int Values [], int NumValues)
	{
	int	i;			//these variables can only be used inside this function
	int	Sum (0);	// these are known as local variables

	for (i = 0; i < NumValues; i++)
		Sum += Values [i];
	return Sum / NumValues;
	}

int CountVowels (char Str [])
	{
	int	i;
	int	NumVowels (0);

	for (i = 0; Str [i] != '\0' ; i++)
		switch (Str [i])
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'O':
		case 'o':
		case 'U':
					NumVowels++;  //IF TRUE, ++ go to the next character to check for vowel
					break;
		default: ;
		}
	return NumVowels;

	}



