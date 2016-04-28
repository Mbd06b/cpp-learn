/*
 * FLString.h
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#ifndef SRC_FLSTRING_H_
#define SRC_FLSTRING_H_



/*
 * Recommendation for building the class
 *
 * template <int Size>
 * class FLString : public string   // create a fixed length string
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
 * 	The program will need to sort by Name or ID number.
 * 	 We will need two different SORT methods in the student name class.
 *
 *
 *
 * 	When we write to a disk, Bill says that the easiest way to do that is one string at a time.
 * 	Example:
 *
 * Name-
	 * 	First
	 * 	Middle
	 * 	Last
  Address-
	 * 	Street
	 * 	City
	 * 	State
	 * 	Zip
  Phone-
	 * 	Area Code
	 * 	Phone NUmber
	 * 	ID
 */


#endif /* SRC_FLSTRING_H_ */
