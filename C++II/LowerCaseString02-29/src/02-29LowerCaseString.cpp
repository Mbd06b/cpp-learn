//============================================================================
// Name        : 02-29LowerCaseString.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LowerCaseString.h"

using namespace std;

int main(){

	WCS_String Str1	("Able was I ere I saw Elba");

	LowerCaseString LCStr1  (Str1);
	LowerCaseString LCStr2;

	LCStr1.Copy ("abcd");
	LCStr1.Concat (LCStr1);
	LCStr1.Concat ("abcd");

}

