/*
 * BinarySFunc.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: mbd06b
 */

#include "BinarySearch.h"

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


