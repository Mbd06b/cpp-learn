/*
 * MyString.cpp
 *
 *  Created on: Jan 25, 2016
 *      Author: mbd06b
 */



#include "MyString.h"
#include <string.h>

#include <iostream>
#include <memory.h>
using namespace std;

//------------------------------------------DEFAULT CONSTRUCTOR ----------------------------
MyString::MyString (){   //automatically called when the class is instantiated   "::" is "Member of".

	cout << "Default Constructor" << endl;
	numChars = 0;
	numSlots = numChars;
	pData = new char [numChars +1];
	pData [0] = '\0';


};

//-----------------------------------------COPY CONSTRUCTOR-------------------
MyString::MyString (const MyString & Str){

	cout << "Copy Constructor" << endl;
	numChars = Str.numChars;
	numSlots = numChars;
	pData = new char [numChars + 1];
	strcpy (pData, Str.pData);


};

//----------------------------------------OTHER CONSTRUCTOR --------------
MyString::MyString (const char Str[]){

	cout << "Other Constructor" << endl;
	numChars = strlen (Str);
	numSlots = numChars;
	pData = new char [numSlots + 1];
	strcpy (pData, Str);

};


//------------------------THE DESTRUCTOR--------------------------
// 		automatically called when an object "goes away"
MyString::~MyString (){

	cout << "ALL HAIL THE DESTRUCTOR OF pData" << endl;
	delete [] pData;

};


MyString & MyString::Copy (const MyString & str){

	if (this == &str){ // we are trying to copy over ourselves.


		if (numSlots < str.numChars){
			delete [] pData;
			numChars = str.numChars;
			numSlots = numChars;
			pData = new char [numSlots + 1];

		}
		else{
			numChars = str.numChars;
			strcpy (pData, str.pData);
		}

	}else;
	return *this; //*this returning the string (object/method) I belong to.
};

/*--------------------------------------------------C-Type String Constructor Copy ---------------------
MyString & MyString::Copy (const MyString & str){

	-------STUDENT ASSIGNMENT, MAKE A C-TYPE STRING COPY --------------------
		if (numSlots < str.numChars){
			delete [] pData;
			numChars = str.numChars;
			numSlots = numChars;
			pData = new char [numSlots + 1];

		}
		else{
			numChars = str.numChars;
			strcpy (pData, str.pData);
		}



	return *this; //*this returning the string (object/method) I belong to.
};

*/

MyString & MyString::Concat (const MyString & str){



		numTempChars = 0;
		numSlots = numChars;
		pData = new char [numChars + 1];

		strcpy (pData, str.pData);

	pTempData =
	strcat (pTempData, str.pData);

	//Concatenate is to build 2 strings into a single string.
	//example  "ABCD\0"  and "EFGHIJKL\0"  >> Concatenates to >> "ABCDEFGHIJKL\0"
	//to Concatate without problems,
	//create a temporary pointer array location.
	/*

	pTemp = new char [....]
	strcpy (pTemp,pData)
	strncat(pTemp, str.pData,numChars)

	*/

	return *this;

};

//----------------------Dynamically Allocated Array Input ---------------------
void MyString::Read (istream & in){

	const int 	 guess (50);
		  char   c;
		  char * pTemp;

		  if (numSlots == 0){

			  delete [] pData;
			  numSlots 	 = guess;
			  pData		 = new char [numSlots +1]; // +1 is for the \0 end of string mark.
		  }
		  else;

		  numChars = 0;
		  while ((c = in.get ()) != '\n'){ //while what's being typed is not the entered key, keep going.

			  pData [numChars++] = c;
			  if (numChars >= numSlots){

				  pTemp = new char [(numSlots += guess) + 1];
				  memcpy (pTemp, pData, numChars); //copy from pData to pTemp, numchar number of times.
				  delete [] pData;
				  pData = pTemp;

		  }
			  pData [numChars] = '\0'; //adds an EOS mark to our array.

		  }
}

/*THIS IS NOT A REFERENCE -- it is ugly, but it's returning a copy of the string itself. So we will return by value.
MyString MyString::operator & (const MyString & str) const{
	MyString temp;

	//put both this class and the parameter into Temp.
	return temp;
}
*/
