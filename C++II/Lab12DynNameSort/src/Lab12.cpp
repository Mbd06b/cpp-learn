//============================================================================
// DESCRIPTION : Program 12, CharSort & BinarySearch w/Dynamic Pointer Arrays (NumNames and NameSize)
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/10/2015
//============================================================================


	#include "ReadString.h"
	#include "pBinarySearch.h"
	#include <stdlib.h>
	#include <iostream>
	#include <string.h>
	#include "pCharSSort.h"

	using namespace std;

	int main() {


			const int MaxSize = 5;   //Initial size guess for our char *pArray
			int CurrentSize;
			int NamesCounter; //tracks number of names(slots) needed for our dynamic array.
			bool Test = true;
			char **pArray; //creates a pointer array.
			char **pTempArray;
			char	*pNameQuery;

//--------------------------_Setting our initial values -----------------------------------
			CurrentSize = MaxSize;
			NamesCounter = 0;
			pArray = new char * [CurrentSize]; //Creates a dynamic memory array of a specified size.



	cout << "Enter names to sort (Press ENTER to end input): " << endl;
//-----------------------------Loop to input our names, is dynamic based on how many rows chosen---------------------------
	do{


//--------------------Adjustable Array Test Increasing Size of Our Array based on user demand -------------------------------
			if (NamesCounter >= CurrentSize)
				{
				cout << "Your array grew" << endl;
				CurrentSize = CurrentSize + MaxSize;  // increase the previous size with our constant int
				pTempArray = new char * [CurrentSize]; // create new bigger array.
						for (int i=0; i<NamesCounter; i++) //
							{
							memcpy(pTempArray, pArray, CurrentSize * sizeof (char *)); //(destination, source, size)
							//pTempArray[i] = pArray[i];       // copy values to new array.
							}
				delete [] pArray;              // free original array memory for memory transfer
				pArray = pTempArray;   //assign our array into the freshly emptied memory.
				}



		cout << ">";
		pArray [NamesCounter] = ReadString(); //Asks for a Name & Returns Either a Name "B'I'L'L'\0" or simply returns '\0' if Enter Key is pressed.


				if (pArray [NamesCounter][0] =='\0') //if the user hits ENTER \n, only \0 will return from our ReadString() function.
					{
					Test = false;
					}
				else
					{
					cout << "You Entered: " << pArray [NamesCounter];
					NamesCounter++;
					}
		cout << endl;


	}while(Test == true) ; //true the \0 mark was returned



	cout << "Unsorted names are " << endl;
		for (int i = 0; i < NamesCounter; i++)
			{
			cout << pArray [i] << ", ";
			}
			cout << endl;
	//---------------------------------------pArray is now Full confirmed and ready to Sort-------------------


		Sort (pArray, NamesCounter); //sending our pointer array and number of names.

				cout << "Sorted  names are: " << endl;
					for (int i = 0; i < NamesCounter; i++)
					{
					cout << pArray [i] << ", ";
					}
					cout << endl;
					cout << endl;

	//---------------------------------------pArray is now Sorted and ready to Search-------------------

	do{
	cout << "Enter a Name to Search for: " << endl;

	int Position;
	Test = true;

	cout << ">";
	pNameQuery = ReadString();


		if (pNameQuery[0] == '\0') //if the user hits ENTER \n, only \0 will return from our ReadString() function.
			{
			cout << "Exited Program" << endl;
			delete [] pArray;
			Test = false;
			}

		else
			{
			Position = Search (pArray, pNameQuery, NamesCounter); // (char * Array []; char * Query, int NamesCounter)
			if (Position == -1) //if position is -1  then our query was not found.
				{
				cout << "Query Not found, Try Again." ;
				}

			if (Position > -1)
				{
				cout << "Query Found at position: " << Position << endl;
				}
			}


	cout << endl;
	}while (Test == true);



	return 0;
	}

