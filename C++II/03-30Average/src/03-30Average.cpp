//============================================================================
// Name        : 03-30Average.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stdlib.h>

	//arguments passed {155, 200, 35, 15,75 }
int main(int argc, char * argv  []) { //command line arguments, in Main, this tells the program.
									 //argc - is the typical name for the numerical argument
									 //argv - is an array of pointers, pointing to the beginning of the string.
									 //example: In Linux, you have ls -t as a command "list" is index 0, -t is.

						//These Command arguments need to be set in configuration properties.


		//IN VISUAL STUDIO
		//select project folder >> Configuration >> Debugging >> Command Arguments.

		//IN ECLIPSE
		//selet project folder >> Properties >> Run?Debug Settings >> (Select file) *Edit* >>
		// ON Arguments TAB Type your application's argument there, and click "OK".
		// When you will execute your application thanks to the "play" button of eclipse, your program will be called with arguments.
	int i;
	int Sum;

	Sum = 0;
	for(i = 1; i < argc; i++){
		Sum += atoi (argv [i]); //atoi changes the string into an integer.
	}

	cout << "\tAverage is " << (Sum / (argc -1)) << endl;
	return 0;
}
