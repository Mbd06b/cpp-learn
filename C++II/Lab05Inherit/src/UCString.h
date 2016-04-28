/*
 * toUpperclass.h
 *
 *  Created on: Apr 11, 2016
 *      Author: mbd06b
 */

#ifndef UCSTRING_H_
#define UCSTRING_H_

#include "myStringclass.h"


class UCString : public String{

public:
					UCString		();
					UCString		(const String &);
					UCString		(const char []);
					~UCString		();

					UCString &    Concat	 (const String &);
					UCString &    Concat	 (const char []);
					UCString & 	  Copy 		 (const String &);
					UCString &	  Copy		 (const char []);
					UCString &	  setAt  	(char, int);

					UCString   operator & (const String &);
					UCString   operator & (const char []);
					UCString & operator &= (const String &);
					UCString & operator &= (const char []);
					UCString & operator = (const String &);
					UCString & operator = (const char []);

private:
					String & 	toLower 		  ();

};



//Default Constructor  - "one with no parameters to initialize the class to empty;"
UCString::UCString (){
};

//Other Constructor
UCString::UCString(const String & str): String (str){
	toUpper();
};

UCString::UCString (const char str []): String (str){
	toUpper();
};

UCString::~UCString(){
};

UCString & UCString::Concat(const String & str){
	String::Concat(str);
	toUpper();
	return *this;
}

UCString & UCString::Concat(const char str []){
	String::Concat(str);
	toUpper();
	return *this;
}

inline UCString & UCString::Copy (const String & str){
	String::Copy(str);
	toUpper();
	return *this;
}

inline UCString & UCString::Copy (const char str []){
	String::Copy(str);
	toUpper();
	return *this;
}

inline UCString & UCString::operator = (const String & str){
	String::Copy(str);
	toUpper();
	return *this;
}

inline UCString & UCString::operator = (const char str []){
	String::Copy(str);
	toUpper();
	return *this;
}

inline UCString & UCString::setAt (char c, int i){
	String::setAt(c, i);
	toUpper();
	return *this;
}


inline UCString & UCString::operator &= (const char str []){
	return Concat (str);
}

inline UCString & UCString::operator &= (const String & str){
	return Concat (str);
}



inline UCString UCString::operator & (const char str []){
	UCString temp (*this);
	return temp.Concat (str);
}


inline UCString UCString::operator & (const String & str){
		String temp (*this);
		temp.Concat (str);
		return temp;
}

inline UCString operator & (const UCString & str, const char pChar []){
	String temp (str);
	temp.Concat (str);
	return temp;
};


#endif /* UCSTRING_H_ */
