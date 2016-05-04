/*
 * ReadInt.h
 *
 *  Created on: Sep 23, 2015
 *      Author: mbd06b
 */

#ifndef READ_INT_H_
#define READ_INT_H_

// NOTE you might see #pragma instead of #ifndef and #define  above when seeing code.
// this is doing the same thing but only for visual studio.  It's not as universal, so we avoid using it

// the above lines along with the #endif at the bottom will prevent problems
// if the programmer accidently includes a header file more than once
// for this to work the word in all caps above must be unique

int ReadInt (); // this is a prototype, means that ReadInt is a function,
				// it gives back an int, functions can give back one thing (Not an Array [])
				// void means that it doesn't give back anything
				// what is inside the () tells what is given to the function
				// in our case we have nothing listed since the function will read from the keyboard
				// some people put void inside the () to mean nothing is sent to the function
				// Example:   int ReadInt (void);



#endif /* READ_INT_H_ */
