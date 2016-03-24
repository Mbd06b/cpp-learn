//============================================================================
// Name        : 10-14.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "SinkingSort.h"

int main()
	{
	char Array [] = "qxevrbthkalmgnzw";
	//Sort (Array);  //going to create a function called Sort

	cout << "Unsorted array is " << Array << endl;
	Sort (Array);
	cout << "Sorted array is  " << Array << endl;



	return 0;
	}
