/*
 * FLString.h
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#ifndef SRC_FLSTRING_H_
#define SRC_FLSTRING_H_



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

template <int L> //L - length
class FLString : public String{

public:
					FLString		();
					FLString		(const String &);
					FLString		(const char []);
		virtual		~FLString		();



private:


};



#endif /* SRC_FLSTRING_H_ */
