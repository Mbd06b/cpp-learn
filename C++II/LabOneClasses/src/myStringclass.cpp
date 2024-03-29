/*
 * class.cpp
 *  Created on: Feb 3, 2016
 *      Author: mbd06b
 */

#include <iostream>
#include <string.h>
#include <memory.h>

#include "myStringclass.h"
using namespace std;

//Default Constructor  - "one with no parameters to initialize the class to empty;"
String::String (){

	cout << "Default Constructor" << endl;
	numChars = 0;
	numSlots = numChars;
	numTempSlots = 0;
	numTempChars = 0;
	pTempData = 0;
	pData = new char [numChars +1];
	pData [0] = '\0';

};

//C-TYPE Constructor one with a pointer to a “C” type string as a parameter to initialize the class to contain a copy of that string;
String::String (const char str [] ){

	numChars = strlen (str);
	numSlots = numChars;
	numTempSlots = 0;
	numTempChars = 0;
	pTempData = 0;
	pData = new char [numSlots + 1];
	strcpy (pData, str);


};

//Copy Constructor- "and one with a parameter that is of class String to initialize to a copy of that value."
String::String (const String & str){
		numChars = str.numChars;
		numSlots = numChars;
		numTempSlots = str.numTempSlots;
		numTempChars = str.numTempChars;
		pTempData = str.pTempData;
		pData = new char [numChars + 1];
		strcpy (pData, str.pData);

}


//The Destructor
// 		automatically called when an object "goes away" or goes out of scope
String::~String (){

	delete [] pData;

};

//Copy function (Copy) to copy another String object into this one or copy a “C” type string into this object.
String & String::Copy(const String & str){

	if (this != &str){ //chcek to see if we are trying to copy over ourselves.

		if (numSlots < str.numChars){
			delete [] pData;
			numChars = str.numChars;
			numSlots = numChars;
			pData = new char [numSlots + 1];
		}
		else{
			numChars = str.numChars;

		}
	strcpy (pData, str.pData);

	}else;
	return *this; //*this returning the string (object/method) I belong to.
};

String & String::Copy(const char str[]){

	bool different = false;

	int strLen = strlen(str);

	for(int i = 0; i < strLen; i++){ //loops through string, if different marks it true.
		if (str[i] != pData[i]){
			different = true;
		}
	 }

			if(different){  			//if true, check size
				if(numSlots < strLen){  //if size is too small, make it bigger.
					delete [] pData;
					numChars = strLen;
					numSlots = numChars;
					pData = new char [numSlots + 1];
				 }
			else{						 //otherwise, assign the size and data.
				numChars = strLen;
				numSlots = numChars;
				  pTempData = new char [(numSlots += strLen) + 1];
				  memcpy (pTempData, pData, numChars); //copy from pData to pTemp, numchar number of times.
				  delete [] pData;
				  pData = pTempData;
			   }
			}else;

	return *this;
};


//Concatenation function (Concat) to allow concatenation of the String object to another and to allow concatenation of the String object to a “C” type string.
String & String::Concat (const String & str){

		pTempData = new char [numSlots + 1];
		strcpy(pTempData,pData);

				delete [] pData;
				numChars = numSlots + str.numSlots;
				numSlots = numChars;
				pData = new char [numSlots + 1];


	//strcpy (pData, pTempData);
	strcat (pTempData, str.pData);
	strcpy (pData, pTempData);

	delete [] pTempData;

	return *this;

};

String & String::Concat (const char str[]){

		pTempData = new char [numSlots]; //should already have enough slots including EOS mark /0 from constructor
		int strLength = strlen(str);

		for(int i = 0; i < (numSlots + 1);i++){ //copies c-type string into temp.
			pTempData[i] = pData[i];
		};

			delete [] pData; //pData has been moved to temp. So we delete it.
			numChars = numSlots + strLength; //adding the length of our string to concatenate to original string..
			numSlots = numChars;
			pData = new char [numSlots + 1]; //new bucket for string created.

			strcat(pTempData, str);
			strcpy(pData, pTempData);

			delete [] pTempData;

	return *this;

};




/*
Modify Program One to add the following:
Assignment operator (“=”).
Comparison operators (“<”, “<=”, “==”, “!=”, “>=”, “>”)
Concatenation operator (“&”).
Concatenation and assignment operator (“&=”)
Input operator (“>>”).
Output operator (“<<”).

Above items 1 through 4 should have versions that work with a String object and a “C” type string on the right of the operator.

Items 5 and 6 require a String object to the right of the operator.

Items 1 and 4 will require a String object on the left of the operator.

Items 2 and 3 should have versions that allow both a String object and a “C” type string on the left of the operator.

Item 3 does not modify the object to the left of the operator.

 */
