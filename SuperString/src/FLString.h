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


template <size_t L> //L - length, include +1 for EOS mark
class FLString : public String{

public:
					FLString		();
					FLString		(const FLString <L> &);
					FLString		(const char []);
					~FLString		();

					unsigned long 	Length      () const;
					bool			GetAt		(char &, int)const;
					bool 			setAt 		(char c, int i);
					istream &       Read        (istream &);//method used to facilitate the read in '>>' operator.
					static	char	ReadChar	(istream & = cin);

					bool 	setAt 		(char c, int i);


					String & operator  = (const String &);
					String & operator = (const char []);


private:



					//we cannot change the length so we might as well suppress the concat operators.
					String &     Concat	 	(const String &);
					String &     Concat		 (const char []);
					String &     localConcat (const char * p); //this * is the same as [];
					String  	 operator & (const String &);
					String  	 operator & (const char []);
					String & 	 operator &= (const String &);
					String &	 operator &= (const char []);


};




#endif /* FLSTRING_H_ */
