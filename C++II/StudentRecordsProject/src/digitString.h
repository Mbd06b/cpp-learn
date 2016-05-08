/*
 * DigitString.h
 *
 *  Created on: Apr 13, 2016
 *      Author: mbd06b
 */

#ifndef DIGITSTRING_H_
#define DIGITSTRING_H_

#include "myStringclass.h"
using namespace std;

class digitString : public String{


public:									digitString		();
										digitString		(const String &);
										digitString		(const char []);
										digitString		(const size_t &); //for default FLdigitString
										digitString		(const char [], const size_t &);//for FLdigitString read-in
						virtual			~digitString		();

										digitString &    Concat	 (const String &);
										digitString &    Concat	 (const char []);
										digitString &   Copy	 (const String &);
										digitString &   Copy	 (const char []);
										digitString &	setAt	 (char, int);

										istream &   readDigits   (istream & In);
										istream & 	operator >>  (const String &);
										istream &   operator >>  (const char []);


										digitString   operator & (const String &);
										digitString   operator & (const char []);
										digitString & operator &= (const String &);
										digitString & operator &= (const char []);
										digitString & operator = (const String &);
										digitString & operator = (const char []);
										istream &   Read		 (istream & In);

private:




};



#endif /* DIGITSTRING_H_ */
