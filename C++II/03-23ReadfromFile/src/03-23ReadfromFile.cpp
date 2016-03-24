

#include <fstream>
#include <iostream>
using namespace std;

int main() {

	fstream inFile;
	char	Line [181];

	inFile.open ("03-23ReadfromFile/03-23ReadfromFile.cpp", ios_base::in);

	if (inFile.good()){
		do{
			inFile.getline(Line,181); //get line,
			cout << Line << endl;  //display that line on the screen

		}while(!inFile.eof()); //when it's not the end of file, keep going.
		inFile.clear(); //clears the eof flag from the while loop.
		inFile.close();
	}
	else
		cout << "Error, file did not open" << endl;



	return 0;
}
