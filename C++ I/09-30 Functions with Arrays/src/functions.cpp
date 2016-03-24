/*
 * functions.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: mbd06b
 */


#include "functions.h"
#include <stdlib.h>// needed for toupper

int CountCharacters (char Str [])  //arrays as parameters are automatically call by reference
	{								// so you can change an array here and it will change it in main.cpp
	int	i;

	for (i = 0; Str [i] != '\0'; i++);
		if ((i % 2) == 0)
				Str [i] = toupper (Str [i]);
	return i;

	}

/*
t CountCharacters1 (const char Str []);  //putting ost with the arry tells the compiler not to allow..
	{										// the array to be changed.
		int	i;

		for (i = 0; Str [i] != '\0'; i++);
			if ((i % 2) == 0)
					Str [i] = toupper (Str [i]);
		return i;
	}
*/

bool GetOperator (const char Ops [], char & Result)
	{
	// read a character  characters in the arry
	// if the character we read is one of the characters in the array (confirms that the character is valid)
	// 			put the character read into Result
	//			return true
	//		else
	//			return false
	//


	}


