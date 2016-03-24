//============================================================================
// Name        : TestReview.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	int x;

	for(int i = 0; i < 100; i++)
	{
		x = rand() % 100;
		cout << x << endl;

	}


	srand(time(NULL)); // s= Seed, rand = Random, so srand (SeedRandom)


	x = rand() % 100;

	cout << x;

	return 0;
}
