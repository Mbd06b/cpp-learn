

#include <iostream>
#include <string.h> //for strtok
#include <stdlib.h> //for atoi
using namespace std;

void getGrades (char [], int []);
void showGrades (int []);

int main() {

	int		i;
	char Lines [10] [25] = {"100,100,100,100,100",
							"95,100,80,75,40,",
							"35,38,44,53,75"};


	int Grades [5]; //three sets of 5 grades.

	for (i = 0; i < 2; i++){
		getGrades (Lines [i], Grades);
		cout << "Grades [" << i << "] are: " << endl;
		showGrades (Grades);

	}



	return 0;
}

void getGrades (char Line [], int Grades []){

	char * pNumber;
	int i = 0;
	pNumber = strtok (Line, ","); // strtok dilimeates a C-type String by whatever character you put in the argument, (commas ",");
	while (pNumber != NULL){
		Grades [i++] = atoi (pNumber); //atoi changes the ascii code into
		pNumber = strtok (NULL, ",");

	}
}

void showGrades (int Grades []){
	int i;

	for (i = 0; i < 5; i++){
		cout << Grades [i] << endl;
	}
}

