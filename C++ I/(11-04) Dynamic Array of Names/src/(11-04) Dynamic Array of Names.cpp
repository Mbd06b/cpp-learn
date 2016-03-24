//============================================================================
// Name        : (11-04).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;

void Func1 (char * [], int);
int Search (char * [], char *, int);


int main() {

	int		NumNames;
	int 	CurrentNumNames;
	char 	*pNames1 [20]; //array of 20 addresses to sets of characters.
							//
	char 	** pNames2;  // we want the array to grow. can use a dynamic array of addresses to set
	char 	** Temp;
	char 	* SearchName;


	Func1 (pNames1, 20);
	Search (pNames1, SearchName, CurrentNumNames);

	NumNames = 20;
	CurrentNumNames = 0;
	pNames2 = new char * [NumNames]; // sets the size to 20 addresses of names This is NEW IS THE DYNAMIC MEMORY ALLOCATION
	//(while Loop)	>>> SEE READSTRING.CPP  (10-21)
			//read in names (ad one te CurrentNumNames each time) until you fill up the array
		//pNames2 [CurrentNumNames++] = ReadString ();
		//(if Statement)
			//when you fill up the array, add 20 to Num Names
			//and create a new array of addresses of this size, create a new array of addresses and put this into temp.
			//copy pNames to Temp -- memcpy (Temp, pNames, NumNames * sizeof (char *));
			//delete pNames
			//set pNames equal to Temp   pNames = Temp;
			//continue reading names.

	Func1 (pNames2, NumNames);

	return 0;
}

void Func1 (char * [], int HowMany)  //
{
	char * Temp;
	strcmp (pNames [0], pNames [1]);
	Temp = pNames [0];  //to swap the pointers
}


int Search (char * pNames [], char * Name,  int HowManyNames)
{
	strcmp (pNames [0], Name);
}
