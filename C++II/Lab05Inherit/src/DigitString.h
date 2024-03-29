/*
 * DigitString.h
 *
 *  Created on: Apr 13, 2016
 *      Author: mbd06b
 */

#ifndef DIGITSTRING_H_
#define DIGITSTRING_H_

#include "myStringclass.h"
#include <stdexcept>
using namespace std;

class digitString : public String{


public:									digitString		();
										digitString		(const String &);
										digitString		(const char []);
										~digitString		();

										digitString &    Concat	 (const String &);
										digitString &    Concat	 (const char []);
										digitString &	Copy 	 (const digitString &);
										digitString &   Copy	 (const char []);
										digitString &	setAt	 (char, int);


										digitString   operator & (const String &);
										digitString   operator & (const char []);
										digitString & operator &= (const String &);
										digitString & operator &= (const char []);
										digitString & operator = (const String &);
										digitString & operator = (const char []);

private:

};



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

#endif /* DIGITSTRING_H_ */
