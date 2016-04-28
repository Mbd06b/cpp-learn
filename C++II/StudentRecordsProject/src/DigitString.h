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



#endif /* DIGITSTRING_H_ */
