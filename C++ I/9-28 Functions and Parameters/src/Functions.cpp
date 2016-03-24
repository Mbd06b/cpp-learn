/*
 * Functions.cpp
 *
 *  Created on: Sep 28, 2015
 *      Author: mbd06b
 */
#include "Functions.h"

int Add (int x, int y)
	{
	return  x + y;

	}

long Add (long x, long y)
	{
	return x + y;
	}

double Add (double x, double y)
	{
	return x + y;
	}

int Func1 (int x) // x is a COPY of the value sent in from main
	{		// making the parameter a copy is known as a "call by value"
	x++;  // changing x changes the copy, not the original
	return x;
	}

int Func2 (int & x) // using the & means x now refers back to the ORIGINAL value in main
	{  				// making the parameter refer back to the original is known as "call by reference"
	x++;			// changing x changes the original value back in main
	return x;
	}

int Divide (int x, int y, int & z)
	{
	z = x % y;
	return x / y;


	}
