/*
 * ExampleClass.h
 *
 *  Created on: Jan 20, 2016
 *      Author: mbd06b
 */
//#pragma once  - Visual Studio 2015

#ifndef EXAMPLECLASS_H_  //this name has to be unique for the project, if there is another defined exampleclass.h header it will skip over the code.
#define EXAMPLECLASS_H_

// a class can be divided into sections with given names, (ex: public & private)
// there are other names, but we are not going into those here.

// in a class, if you do not have sections, the default section name is private.


class Example{
	public:		//items in this section can be referenced by any method in the project folder4
		int GetB ();   // {return B;} // <-- you can also write the method inside the class, this is like JAVA.

		bool SetB (int); //created a Method (aka 'prototype') in my public class. This is a safety feature, or gateway to access int B.
		int A;


	private:	//things that are in private can only be accessed by methods(functions) that are members of this class
		int B;  // say B must only be an even value.
				//we can use the SetB method/function in the public section to set the rules for using int B.

};

inline int Example::GetB (){  //inline says "this is not a "real" function. Works great for really small functions.
							//inline's methods HAVE TO BE IN THE HEADER FILE rather than the cpp.
	return B;

}


#endif /* EXAMPLECLASS_H_ */
