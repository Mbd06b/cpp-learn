//============================================================================
// Name        : Cryptology.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
  //make an array of all the letters in the alphabet.
		int letters [2] [26]={'a','b','c','d','e','f','g','h','i','j','k','l',
	                                 'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		int number = 1;

		cout << "Begin Program" << endl;
		cout << number << endl;
	   //loop through the array of letters and get the corresponding number.

		for (int r = 0; r < 3 ; r++)	//for loop prints array one cell at a time.
			{
				for (int c = 0; c < 26; c++)
				{
					if (r == 1)
						{
						letters [r] [c] = number++;
						}
			     	cout << letters [r] [c];
				}
			}
		cout << "End Program" << endl;
	return 0;
}

