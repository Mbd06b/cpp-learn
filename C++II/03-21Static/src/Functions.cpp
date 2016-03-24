/*
 * Functions.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: mbd06b
 */

#include "Functions.h"

int Global;  //if you create an variable outside of the function, all functions can use that. They are called Global variables.
			//Global variable initialize to 0, or EOS,

static int myVar; //this variable can be used by any function in this .cpp file .
				  //but only by functions in this .cpp file .


int Func1 ()
	{
	static int Count; //value sticks around after function call.
	//static automatically sets initial value to 0;
	//static string Foo; //string value initially sets as "0\" EOS mark.


	return ++Count; //static variable remember their values from one call to the next.
	}


static int Func2 (){  //static here means this function can only be called in this cpp. file.
	return -99;
}
