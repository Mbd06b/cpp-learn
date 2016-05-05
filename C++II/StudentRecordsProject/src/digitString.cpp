#include "digitString.h"



//Default Constructor  - "one with no parameters to initialize the class to empty;"
digitString::digitString (){
};

//Other Constructor
digitString::digitString(const String & str): String (str){
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accept digits");
	}
}

digitString::digitString (const char str []): String (str){
	if(!digitCheck()){
			throw invalid_argument("digitString class can only accept digits");
		}
};

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
digitString temp (str);
	if(!temp.digitCheck()){
			throw invalid_argument("digitString class can only accept digits");
		}else
		String::Copy(str);
	return *this;
};


digitString & digitString::Concat(const String & str){
	if(!str.digitCheck()){
		throw invalid_argument("digitString class can only accept digits");
	}else
String::Concat(str);

return *this;
}

digitString & digitString::Concat(const char str []){
digitString temp (str);
	if(!temp.digitCheck()){
		throw invalid_argument("digitString class can only accept digits");
	}else
String::Concat(str);
return *this;
}

digitString & digitString::setAt(char c, int i){
	if(!isdigit(c)){ //if not a digit
			throw invalid_argument("digitString class can only accept digits");
		}else
	setAt(c,i);
	return *this;
}

inline digitString & digitString::operator = (const String & str){
	digitString temp (str);
		if(!temp.digitCheck()){
			throw invalid_argument("digitString class can only accept digits");
		}else
	String::Copy(str);
		return *this;
}

inline digitString & digitString::operator = (const char str []){
	digitString temp (str);
	if(!temp.digitCheck()){
				throw invalid_argument("digitString class can only accept digits");
			}else
	 String::Copy(str);
	return * this;
}


inline digitString & digitString::operator &= (const char str []){
return Concat (str);
}

inline digitString & digitString::operator &= (const String & str){
return Concat (str);
}



inline digitString digitString::operator & (const char str []){
digitString temp (*this);
return temp.Concat (str);
}


inline digitString digitString::operator & (const String & str){
digitString temp (*this);
temp.Concat (str);
return temp;
}

inline digitString operator & (const digitString & str, const char pChar []){
digitString temp (str);
temp.Concat (str);
return temp;
};


