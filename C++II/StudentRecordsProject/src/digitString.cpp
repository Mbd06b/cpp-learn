#include "digitString.h"



//Default Constructor  - "one with no parameters to initialize the class to empty;"
digitString::digitString (){

};

digitString::digitString (const size_t & L): String (L){

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



