/*
 * Functions.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: mbd06b
 */

#include "Functions.h"

extern int X; //exten tells the compiler that these are global variables and to go find the variables
extern int Y;

static int a; //another use of the term Static when used as a GLOBAL static Variable
static int b; // using static outside our functions mean that these variables can be used by any function in this .cpp file
		// but ONLY by these functions. like other static variables, unless you initialize them, the compiler will automatically
		//set them to 0 at the start


int Func1 ()
	{			//variables created inside a function can only be used inside the function.
	int		i (0); // this is known as a local variable
				  // local variables are reset every time the function is called and removed after the function finishes
	i++;
	return i;

	}


int Func2 ()
	{
	static int		i (0);  //now static, this local variable can only be used in this cpp function file it was created in.
				  	  	  	// it is remembered the next time the function is called.
	i++;					// if you do not initialize a static variable, it will automatically start with zero 0
	return i;
	}

int Func3 (int A, int B)
	{
	return A + B;  //now static, this local variable can only be used in this cpp function file it was created in.
				  	  	  	// it is remembered the next time the function is called.;
	}

int Func4 ()  // since we did not define the X or Y here, the extern int X&Y descriptor in the header pulls it here.
	{
	return X + Y;
	}


