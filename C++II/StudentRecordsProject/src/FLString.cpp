/*
 * FLString.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: mbd06b
 */

#include "FLString.h"




//Default Constructor  - "one with no parameters to initialize the class to empty;"
template <int L>
FLString<L>::FLString (){
};

//Other Constructor
template <int L>
FLString<L>::FLString(const FLString <L> & str): String (str){
	if((strlen(str)) != L){
		 throw invalid_argument("digitString class can only accept digits");
	}

};

template <int L>
FLString<L>::FLString(const char str []): String (str){
};

template <int L>
FLString<L>::~FLString<L>(){
};


/*
template <int L>
inline FLString<L> & FLString<L>::Copy (const String & str){

	return *this;
}

template <int L>
inline FLString<L> & FLString<L>::Copy (const char str []){

	return *this;
}

template <int L>
inline FLString<L> & FLString<L>::operator = (const String & str){
	String::Copy(str);
	return *this;
}

template <int L>
inline FLString<L> & FLString<L>::operator = (const char str []){
	String::Copy(str);
	return *this;
}

template <int L>
inline FLString<L> & FLString<L>::setAt (char c, int i){
	String::setAt(c, i);
	return *this;
}

*/


