//============================================================================
// Name        : (10-26)BinarySearch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <string.h>
#include <stdlib.h>  //covers #include string.h
#include "BinarySearch.h"

// For Binary Search to work, the array we are searching through
// must already be sorted

int main()
{
	char Characters [] = "acegikmoqsuwy"; //this is in alphabetical order, (IT IS ALREADY SORTED)
	int Position;

	Position = BinarySearch (Characters, strlen(Characters),'e'); //there is no -1 position, so if we retur
	cout << "e is at position " << Position << endl;


	return 0;
}
