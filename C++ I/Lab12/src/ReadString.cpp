/*
 * ReadString.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: mbd06b
 */

#include <iostream>
#include "ReadString.h"
#include <string.h> //for memcpy
using namespace std;


char * ReadString ()
{
	const int		FirstGuess (50);
	char 	c;
	int		CurrNumChars;
	int		CurrSize;
	char *	pString;
	char *	pTempString;

	CurrNumChars = 0;
	CurrSize 	= FirstGuess;
	pString 		= new char [CurrSize +1]; // +1 to capture the "End of String" mark returned if we don't input any names.

	while ((c = cin.get()) != '\n') //cin.get gets the characters as you type them  \n is the ENTER or RETURN character on the keyboard.
			{
			pString [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
				if (CurrNumChars >= CurrSize)  // is the array full?
					{			// Yes, I need a bigger array
						CurrSize += FirstGuess;
						pTempString = new char [CurrSize + 1];
						//stingcopy won't work, because we haven't used an end of string mark to judge the size
						memcpy (pTempString, pString, CurrNumChars); //copies string Chars to TempString
						delete [] pString;  //data is not needed now so we are giving it back to the system.
											// String still contains a memory address, we dont "own" that location anymore.
											//IF YOU DONT DELETE THE ALLOCATED MEMORY YOU WILL HAVE a memory leak RESOURCE FAILURE.
						pString = pTempString; //not moving any characters
					}else;
			}//end of while
	pString [CurrNumChars] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.
	return pString;
}



