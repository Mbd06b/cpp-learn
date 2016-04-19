//============================================================================
// Name        : 03-28qsort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Temp{
	public:
						Temp(); //constructor
			 static int Compare (const void *, const void *);  //compare method has to be static
			 void 		Display ();
			 char * 	getWords () {return (char *) Words;}; //returns a character pointer

	private:
			 char Words [5] [81]; //array of 5 words, upto 80 chars long.

};

int main() {

	Temp T1;

	cout << "Names before sorting:" << endl;
	T1.Display();

	qsort (T1.getWords (), 5, 81, Temp::Compare); //words, 5 words, 81 chars in a word

	cout << "Names after sorting: " << endl;
	T1.Display();

	return 0;
}

Temp::Temp (){

		strcpy (Words [0], "George");
		strcpy (Words [1], "Bobby");
		strcpy (Words [2], "Susan");
		strcpy (Words [3], "Darla");
		strcpy (Words [4], "Abercrombie");
		strcpy (Words [5], "Fitch");
}

void Temp::Display(){
	int i;

	for (i = 0; i < 5; i++) {
		cout << "\t" << Words [i] << endl;
	}
}

int Temp::Compare (const void * pOne, const void * pTwo){
		const char * pWord1 ((char *) pOne);
		const char * pWord2 ((char *) pTwo);
		return strcmp (pWord1, pWord2);  //bill used _strcmpi  for case insensitive comparisons.

}
