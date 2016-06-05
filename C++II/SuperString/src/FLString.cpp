/*
 * FLString.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: mbd06b
 */

#include "FLString.h"


//Default Constructor  - "one with no parameters to initialize the class to empty;"
//Default Constructor  - "one with no parameters to initialize the class to empty;"

template <size_t L>
FLString<L>::FLString (){
};


//C-TYPE Constructor one with a pointer to a “C” type string as a parameter to initialize the class to contain a copy of that string;
template <size_t L>
FLString<L>::FLString (const char str [] ){
	if(strlen(str) == (L - 1)){
	numChars = L - 1;
	numSlots = L;
	pData = new char [L];
	strcpy (pData, str);
	}
	else{throw invalid_argument("invalid string length");};
};

//Other Constructor
template <size_t L>
FLString<L>::FLString(const FLString <L> & str): String (str){
	numChars = str.numChars;
	numSlots = numChars;
	pData = new char [numChars + 1];
	strcpy (pData, str.pData);

};

//Copy Constructor- "and one with a parameter that is of class String to initialize to a copy of that value."
String::String (const String & str){
		numChars = str.numChars;
		numSlots = numChars;
		pData = new char [numChars + 1];
		strcpy (pData, str.pData);

}





template <size_t L>
istream & FLString<L>::Read (istream & In){
	char			c;
	char *			pTemp;
	bool end = true;

/*NOTES ON eof
 * bool eof() const;
Check whether eofbit is set
Returns true if the eofbit error state flag is set for the stream.
This flag is set by all standard input operations when the End-of-File is reached in the sequence associated with the stream.
Note that the value returned by this function depends on the last operation performed on the stream (and not on the next).
Operations that attempt to read at the End-of-File fail, and thus both the eofbit and the failbit end up set. This function can be used to check whether the failure is due to reaching the End-of-File or to some other reason.
 */
	numChars = 0;
	while (((c = ReadChar (In)) != '\n') && !In.eof () && (end)){
		pData [numChars++] = c;
		if (numChars >= L){
				cout << "You input too many characters, must enter [" << (L - 1) << "], try again" << endl;
				numChars = 0;
				end = false;
		}
			else;
		if ((c == '\n') && (numChars < (L - 1))){
			cout << "You input too few characters, must enter [" << (L - 1) << "], try again" << endl;
			numChars = 0;
			end = false;
		}
	}
	pData [numChars] = '\0';
	return In;
}

template <size_t L>
char FLString<L>::ReadChar (istream & in){
	return static_cast <char> (in.get ());
}

template <size_t L>
FLString<L>::FLString(const char str []): String (str){
};

template <size_t L>
FLString<L>::~FLString<L>(){
};



template <size_t L>
inline FLString<L> & FLString<L>::Copy (const FLString & str){
	return *this;
}



template <size_t L>
inline FLString<L> & FLString<L>::operator = (const String & str){

	String::Copy(str);
	return *this;
}

template <size_t L>
inline FLString<L> & FLString<L>::operator = (const char str []){
	String::Copy(str);
	return *this;
}

template <size_t L>
inline FLString<L> & FLString<L>::setAt (char c, int i){
	String::setAt(c, i);
	return *this;
}

*/


