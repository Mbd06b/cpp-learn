
#include <iostream>
#include <string.h>
#include <memory.h>

#define STRING_SIZE 50

#pragma warning (disable:4996)

#include "myStringclass.h"
using namespace std;

//Default Constructor  - "one with no parameters to initialize the class to empty;"
String::String (){

	numChars = 0;
	numSlots = numChars;
	pData = new char [numChars +1];
	pData [0] = '\0';

};

//C-TYPE Constructor one with a pointer to a “C” type string as a parameter to initialize the class to contain a copy of that string;
String::String (const char str [] ){
	numChars = strlen (str);
	numSlots = numChars;
	pData = new char [numSlots + 1];
	strcpy (pData, str);

};

//Copy Constructor- "and one with a parameter that is of class String to initialize to a copy of that value."
String::String (const String & str){
		numChars = str.numChars;
		numSlots = numChars;
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

	size_t strLen = strlen(str);

	for(size_t i = 0; i < strLen; i++){ //loops through string, if different marks it true.
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
				  pData = new char [(numSlots += strLen) + 1];

			   }
			}else;

	return *this;
};


//Concatenation function (Concat) to allow concatenation of the String object to another and to allow concatenation of the String object to a “C” type string.
String & String::Concat (const String & str){

	size_t numTempChars;
	char * pTempData;

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

	size_t numTempChars;
	char * pTempData;

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



istream & String::Read (istream & In)
	{
	char			c;
	char *			pTemp;


/*NOTES ON eof
 * bool eof() const;
Check whether eofbit is set
Returns true if the eofbit error state flag is set for the stream.
This flag is set by all standard input operations when the End-of-File is reached in the sequence associated with the stream.
Note that the value returned by this function depends on the last operation performed on the stream (and not on the next).
Operations that attempt to read at the End-of-File fail, and thus both the eofbit and the failbit end up set. This function can be used to check whether the failure is due to reaching the End-of-File or to some other reason.
 */
	numChars = 0;
	while (((c = ReadChar (In)) != '\n') && !In.eof ()){
		pData [numChars++] = c;
		if (numChars >= numSlots){
				pTemp = new char [(numSlots += STRING_SIZE) + 1];
				memcpy (pTemp, pData, numChars);
				delete [] pData;
				pData = pTemp;
		}
			else;
	}
	pData [numChars] = '\0';
	return In;
}


char String::ReadChar (istream & in){
	return static_cast <char> (in.get ());
}


String & String::localConcat (const char * p){
	numChars += strlen (p);
	if (numSlots < numChars){
			char * pTemp = new char [numChars + 1];
			strcpy (pTemp, pData);
			strcat (pTemp, p);
			delete [] pData;
			pData	= pTemp;
			numSlots	= numChars;
	}else{
		strncat (pData, p, strlen (p));
		pData [numChars] = '\0';
		}
return *this;
}

void String::localCheckAndCopy (const char * p){
	numChars = strlen (p);
	if (numChars > numSlots){
			delete [] pData;
			numSlots = numChars;
			pData = new char [numChars + 1];
 	}else;
	strcpy (pData, p);
}

void String::localCopy (const char * p){
	numChars	= strlen (p);
	numSlots		= numChars;
	pData		= new char [numChars + 1];
	strcpy (pData, p);
}

String & String::toLower (){
	for (int i = 0; pData [i]; i++)
		pData [i] = static_cast <char> (tolower (pData [i]));
	return *this;
}

String & String::toUpper (){
	for (int i = 0; pData [i]; i++)
		pData [i] = static_cast <char> (toupper (pData [i]));
	return *this;
}

