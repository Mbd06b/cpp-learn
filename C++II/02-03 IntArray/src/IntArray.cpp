/*
 * IntArray.cpp
 *
 *  Created on: Feb 3, 2016
 *      Author: mbd06b
 */


#include <iostream>
#include <assert.h> //assert is great for debugging. If you set the program to "release mode" the assert disappears.
#include <memory.h>
#include "IntArray.h"
using namespace std;


IntArray::IntArray(int L, int H){ //default


	assert (H >= L);  //if the parameter is true, continue on if false terminate the program saying where the error occurred
	Low = L;
	High = H;
	pData = new int [High - Low +1];


};


IntArray::IntArray (const IntArray & IA){

	Low = IA.Low;
	High = IA.High;
	pData = new int [High - Low +1];
	memcpy (pData, IA.pData, (High - Low + 1) * sizeof (int));

};


IntArray::~IntArray(){
	delete [] pData;

}


IntArray & IntArray::operator = (const IntArray & IA){

	if ((High - Low + 1) < (IA.High - IA.Low + 1)){
			delete [] pData;
			pData = new int [IA.High - IA.Low +1];
	}
	else;

	Low = IA.Low;
	High = IA.High;

	memcpy (pData, IA.pData, (High - Low + 1) * sizeof (int));
	return *this;

}


int & IntArray::operator [] (int i){

	assert((i >= Low) && (i <= High));
	return pData [i - Low]; // our array to the compiler looks like 0123456789 10, slots,  the user sees -5, -4, -3, -2 .... 9, 10.

}

int IntArray::operator [] (int i) const{

	assert((i >= Low) && (i <= High));
	return pData [i - Low]; // our array to the compiler looks like 0123456789 10, slots,  the user sees -5, -4, -3, -2 .... 9, 10.

}
