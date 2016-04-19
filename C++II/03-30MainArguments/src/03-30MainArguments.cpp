//============================================================================
// Name        : 03-30MainArguments.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;


//when you are typing in a cmd line,  you might type "prog6 xxx.txt -v -g"
//argc keeps count of how many commands you send
//argv [] is an Array of pointers that contains the values you've been typing.

int main(int argc, char * argv []) { //arguments into C.  >> See 03/30 NOTES on Average.cpp

	int i;
	fstream myFile;
	char Line [81];

	for (i = 0; i < argc; i++){
		cout << "Argv [" << i << "] is " << argv [i] << endl;
	cout << "\n\n\n" << endl;

			if (argc > 1){
				myFile.open (argv [1]);
				}else{
					//ask user for a file name
					//open that file
				};

			if (myFile.is_open()){
				cout << "ERROR" << endl;
				//do what ever you need to
			}else{
				do{
					myFile.getline(Line, 81);
					cout << Line << endl;

				}while (strcmp (Line, "EOF") != 0);
			}

	}

	//prints Argv [0] is /home/mbd06b/workspace/C++II/03-30MainArguments/Debug/03-30MainArguments
	//this is the fully qualified pathway to my program.


	return 0;
}
