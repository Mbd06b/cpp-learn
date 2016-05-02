/*
 * FLString.h
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#ifndef FLSTRING_H_
#define FLSTRING_H_



/*
 * Recommendation for building the class
 *
 * template <int Size>
 * class FLString : public string   // create a fixed L string
 * 		{
 *
 * 		}
 *
 *
 * 		So when you call the variable, you can set the limit on the digits when called...
 *
 * 		typedef FLString <3> Area Code;
 * 		typedef FLString <9> ID;
 *
 *
 */


#include "myStringclass.h"
#include <string.h>


template <int L> //L - length
class FLString : public String{

public:
					FLString		();
					FLString		(const FLString <L> &);
					FLString		(const char []);
					~FLString		();



private:
					String & operator  = (const String &);
					String & operator = (const char []);


					String   operator & (const String &);
					String   operator & (const char []);
					String & operator &= (const String &);
					String & operator &= (const char []);


};



#endif /* FLSTRING_H_ */
