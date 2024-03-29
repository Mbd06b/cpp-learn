/*
 * LowerCaseString.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mbd06b
 */

#ifndef LOWERCASESTRING_H_
#define LOWERCASESTRING_H_


#include <WCS_String.h>

class LowerCaseString : public WCS_String
	{
public:
			LowerCaseString				();
			LowerCaseString				(const LowerCaseString &);
			LowerCaseString				(const WCS_String &);
			~LowerCaseString			();

	LowerCaseString & Copy				(const LowerCaseString &);
	LowerCaseString & Copy				(const WCS_String &);
	LowerCaseString & operator = 		(const LowerCaseString &);
	LowerCaseString & operator = 		(const WCS_String &);

private:
	LowerCaseString & ToUpper			();
				char& operator []		(int); //has to be here because if it were public, people could put uppercase letters without the program being able to check.


	};

#endif /* LOWERCASESTRING_H_ */
