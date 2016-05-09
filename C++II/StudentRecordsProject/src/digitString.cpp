#include "digitString.h"
#define STRING_SIZE 50


//Default Constructor  - "one with no parameters to initialize the class to empty;"
digitString::digitString (){

};

//default constructor for building empty 000 FLdigitStrings
digitString::digitString (const size_t & L): String (L){

};




//building constructor for setting custom FldigitStrings from strings read-in
digitString::digitString (const char str [], const size_t & L): String (str, L){

};
//Other Constructor
digitString::digitString(const String & str): String (str){
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accept digits(DS constructor & str)");
	}
}

digitString::digitString (const char str []): String (str){
	String::Copy(str);
	if(!digitCheck()){
			throw invalid_argument("digitString class can only accept digits (DS constructor str[])");
		}

};


digitString::~digitString(){
};

digitString & digitString::makeDString(){

	const int		FirstGuess (50);
		char 	c;
		int		CurrNumChars;
		int		CurrSize;
		char *	pTempData;

		CurrNumChars = 0;
		CurrSize 	= FirstGuess;
		pData 		= new char [CurrSize +1]; // +1 to capture the "End of String" mark returned if we don't input any names.

		while ((c = cin.get()) != '\n') //cin.get gets the characters as you type them  \n is the ENTER or RETURN character on the keyboard.
				{
				pData [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
					if (CurrNumChars >= CurrSize)  // is the array full?
						{			// Yes, I need a bigger array
							CurrSize += FirstGuess;
							pTempData = new char [CurrSize + 1];
							//stingcopy won't work, because we haven't used an end of string mark to judge the size
							memcpy (pTempData, pData, CurrNumChars); //copies string Chars to TempData
							delete [] pData;  //data is not needed now so we are giving it back to the system.
												// String still contains a memory address, we dont "own" that location anymore.
												//IF YOU DONT DELETE THE ALLOCATED MEMORY YOU WILL HAVE a memory leak RESOURCE FAILURE.
							pData = pTempData; //not moving any characters
						}else;
				}//end of while
			pData [CurrNumChars] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.
			return pData;
}

istream & digitString::Read (istream & In){

	return In;
}



digitString & digitString::Copy(const String & str){
	if (this != &str){ //chcek to see if we are trying to copy over ourselves.
		if(!str.digitCheck()){
			throw invalid_argument("tried to dS::Copy a string w/char to digitString");
		}else
		String::Copy(str);
		return *this;
	}
	return *this; //*this returning the string (object/method) I belong to.
}

digitString & digitString::Copy(const char str []){
	String temp = str;
		if(!temp.digitCheck()){
			throw invalid_argument("digitString class can only accept digits (DS::Copy str[])");
		}else
			String::Copy(str);
	return *this;
};


digitString & digitString::Concat(const String & str){
	if(!str.digitCheck()){
		throw invalid_argument("digitString class can only accept digits (DS::Concat & str)");
	}else
		String::Concat(str);

return *this;
}



digitString & digitString::setAt(char c, int i){
	if(!isdigit((unsigned char)c)){ //if not a digit
			throw invalid_argument("digitString class can only accept digits(DS::setAt)");
		}else
	String::setAt(c,i);
	return *this;
}

inline digitString & digitString::operator = (const String & str){
		Copy(str);
		return *this;
}

inline digitString & digitString::operator = (const char str []){
	String temp = str;
	if(!temp.digitCheck()){
				throw invalid_argument("digitString class can only accept digits(DS::op = []str)");
			}else
	 Copy(str);
	return * this;
}


inline digitString & digitString::operator &= (const char str []){
	String temp = str;
	if(!temp.digitCheck()){
		throw invalid_argument("digitString class can only accept digits(DS::op &= str[])");
	}else
return Concat (str);
}

inline digitString & digitString::operator &= (const String & str){
	String temp = str;
		if(!temp.digitCheck()){
		 throw invalid_argument("digitString class can only accept digits(DS::op &= &str)");
		}else
return Concat (str);
}



inline digitString digitString::operator & (const char str []){
	String temp = str;
			if(!temp.digitCheck()){
			 throw invalid_argument("digitString class can only accept digits(DS::op & str[])");
			}else
return Concat (str);
}


inline digitString digitString::operator & (const String & str){
	if(!str.digitCheck()){
	 throw invalid_argument("digitString class can only accept digits(DS::op & &str)");
	}else
return Concat (str);
}



