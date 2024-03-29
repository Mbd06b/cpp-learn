/*
 * ReadString.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: mbd06b
 */

#include <iostream>
#include "ReadString.h"
#include <stdlib.h>
#include <string.h> //for memcpy


using namespace std;


char * ReadString ()

{
	const int		FirstGuess (50);
	char	c;
	int		CurrNumChars;
	int		CurrSize;
	char *	String;
	char *	TempString;


	CurrNumChars = 0;
	CurrSize 	= FirstGuess;
	String 		= new char [CurrSize +1]; // +1 for the "End of String" mark.
	while ((c = cin.get()) != '\n') //   \n is the ENTER or RETURN character on the kepboard.
	{
	String [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
	if (CurrNumChars >= CurrSize)  // is the array full?
		{			// Yes, I need a bigger array
			CurrSize += FirstGuess;
			TempString = new char [CurrSize + 1];
			//stingcopy won't work, because we haven't used an end of string mark to judge the size
			memcpy (TempString, String, CurrNumChars); //copies string Chars to TempString
			delete [] String;  //data is not needed now so we are giving it back to the system.
								// String still contains a memory address, we dont "own" that location anymore.
								//IF YOU DONT DELETE THE ALLOCATED MEMORY YOU WILL HAVE a memory leak RESOURCE FAILURE.
			String = TempString; //not moving any characters
		}
	else;
	}//end of while

String [CurrNumChars] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.

return String;
}

