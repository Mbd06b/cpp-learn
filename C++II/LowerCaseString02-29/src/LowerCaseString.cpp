/*
 * LowerCaseString.cpp
 *
 *  Created on: Feb 29, 2016
 *      Author: mbd06b
 */


#include "LowerCaseString.h"

LowerCaseString::LowerCaseString(){

}

LowerCaseString::LowerCaseString (const WCS_String & Str): WCS_String (Str){ //here we are calling the parent copy constructor :WCS_String (Str)

	ToLower (); //this is method ofWCS_String
}


LowerCaseString::~LowerCaseString (){

}

LowerCaseString & LowerCaseString::Copy (const LowerCaseString & Str) {
	WCS_String::Copy (Str);
	ToLower ();
	return *this;

}
