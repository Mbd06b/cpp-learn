#include "digitString.h"



//Default Constructor  - "one with no parameters to initialize the class to empty;"
digitString::digitString (){

};

//Other Constructor
digitString::digitString(const String & str): String (str){
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accept digits(DS constructor & str)");
	}
}

digitString::digitString (const char str []): String (str){
	if(!digitCheck()){
			throw invalid_argument("digitString class can only accept digits (DS constructor str[])");
		}
};

digitString::digitString (const digitString & str){
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accopt digits (DS constructor DS & str");
	}
}

digitString::~digitString(){
};


//Copy function (Copy) to copy another String object into this one or copy a “C” type string into this object.
digitString & digitString::Copy(const digitString & str){
	if (this != &str){ //chcek to see if we are trying to copy over ourselves.
		String::Copy(str);
	}else;
	return *this; //*this returning the string (object/method) I belong to.
};

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

digitString & digitString::Concat(const char str []){
String temp = str;
	if(!temp.digitCheck()){
		throw invalid_argument("digitString class can only accept digits(DS::Concat str []");
	}else
String::Concat(str);
return *this;
}

digitString & digitString::setAt(char c, int i){
	if(!isdigit(c)){ //if not a digit
			throw invalid_argument("digitString class can only accept digits(DS::setAt)");
		}else
	setAt(c,i);
	return *this;
}

inline digitString & digitString::operator = (const String & str){
	String temp = str;
		if(!temp.digitCheck()){
			throw invalid_argument("digitString class can only accept digits(DS::op = &str)");
		}else
	String::Copy(str);
		return *this;
}

inline digitString & digitString::operator = (const char str []){
	String temp = str;
	if(!temp.digitCheck()){
				throw invalid_argument("digitString class can only accept digits(DS::op = []str)");
			}else
	 String::Copy(str);
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
	String temp (str);
	if(!temp.digitCheck()){
	 throw invalid_argument("digitString class can only accept digits(DS::op & &str)");
	}else
return Concat (str);
}

inline digitString operator & (const digitString & str, const char pChar []){
	String temp = str;
		if(!temp.digitCheck()){
		 throw invalid_argument("digitString class can only accept digits(DS::op & &str, pchar[])");
		}else
temp.Concat (str);
return temp;
};


