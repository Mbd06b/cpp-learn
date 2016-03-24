//============================================================================
// Name        : 02-17Name.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Name.h"
using namespace std;

int main() {

	Name N1;
	Name N2 (WCS_String ("Slater"), WCS_String ("Bill"), WCS_String ("")); //this is how we can load c-type strings with WCS_String instead of the standard C-Type arrays.



	return 0;
}
