/*
 * pBinarySearch.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: mbd06b
 */
#include <iostream>
#include "ReadString.h"
#include <string.h>
#include "pBinarySearch.h"
using namespace std;


int  Search (char * Array [], char * Query, int HowManyNames)
	{

		int	First; //is assigned 0 below
		int Middle; // is (first + last) divided by 2
		int Last; // last is how many names

		First = 0;
		Last = HowManyNames;


/*-------------------Interim DATA CHECK-------------------------------

		cout << endl;
		cout << "Last is: " << Last;
		cout << ", Query is: "; cout << Query << " FuncCounter is: " << HowManyNames << endl;
		cout << ", Our Array is: ";
		for(int i = 0; i < HowManyNames; i++)
			{
				cout << Array [i] << ", ";
			}
		cout << endl;
		cout << endl;
----------------------------------------------------------------------*/

		while (First <= Last)   //when First is Larger than Last, the character we are searching for Does Not Exist
		{

		Middle = (First +  Last) / 2;

		if (strcmp(Array [Middle], Query) == 0)//similar to (Array [Middle] == Query[0]) Array [Middle] == Query
			{
			return Middle; //if middle == our query, it means our value exists, so we return that integer.
			}

			else
				{
				if (strcmp(Array[Middle], Query) > 0) //if Middle (c) is less than Query (ex. 'a') execute
					{
					Last = Middle - 1; //Query is BEFORE, ex (Middle c, Query a) Last becomes (b), eliminates(cde)
					}

				else
					{
					First = Middle + 1; //Query is AFTER ex: (Middle c, Query e) eliminates (abc) new first (e)
					}
				}

		}//END OF WHILE lOOP
		return -1; //Not Found

	}


/*return value	indicates
 strcmp (ptr 1, ptr 2): compares
<0	the first character that does not match has a lower value in ptr1 than in ptr2
0	the contents of both strings are equal
>0	the first character that does not match has a greater value in ptr1 than in ptr2


		return (Array [], Query [0]);
#include "BinarySearch.h"
//NOTES
int BinarySearch (const char Array [], int SizeOfArray, char c)
{
	{
		int	First;
		int Middle;
		int Last;

		First = 0;
		Last = SizeOfArray - 1;
		while (First <= Last);   //when First is Larger than Last, the character we are searching for Does Not Exist
			{
			Middle = (First +  Last) / 2;
			if (Array [Middle] == c)
				return Middle;
			else
				if (c < Array [Middle])
					Last = Middle - 1;
				else
					First = Middle + 1;

			}
		return -1;
	}
}
	 *
	 *
	 */
