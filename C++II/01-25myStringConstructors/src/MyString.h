/*
 * MyString.h
 *
 *  Created on: Jan 25, 2016
 *      Author: mbd06b
 */

//#pragmaonce //microsoft special header

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include "string.h"
#include <iostream>
using namespace std;

class MyString{

// the "friend" here defeats the abilities of the class. BAD IDEA
//		friend	ostream &	operator >> (ostream &, const MyString & str); //"friend" giving something specified the ability to access private information in my class.  It would be better to just include the information in the class.


//------------------METHODS --------------------------------------------
	public:
		//-----------------Constructors---------------------------------
							MyString 	  			 ();//DEFAULT known as a constructor Called a default constructor, which initializes the initial values)
		explicit			MyString 	 			 (const MyString &);//COPY known as a copy constructor, passes in a reference to the MyString function //MyString (MyString); //passing in by value here creates infinite recursion INFINITY LOOP
		explicit			MyString 	  			 (const char []); //OTHER the Name of the method HAS TO BE THE NAME OF THE CLASS
							//THE DESTRUCTOR
							~MyString 	  (); // ~ bitwise NOT, reverses all the bits in the constructor, Whenever the object goes away.


				int 		Compare 	 			 (const MyString &) const;//int -1 string comes before, 0 (the same), 1 (after) using string cmp
				int 		Compare 	 			 (const char []) const;
				MyString & Concat		 			 (const MyString &); //
				MyString & Concat		 			 (const char []);
				MyString &	Copy 		 			 (const MyString &); //STRING COPY
				MyString & 	Copy 		 			 (const char []); //CTYPE STRING COPY
				unsigned long 	Len 	 			 () const; //Make Length an inline method. const here means that the method is not changing anything in the class.
				void		Read					 (istream &);

//-----------__OPERATOR OVERLOADS ---------------------------------------
				MyString & operator = 				 (const MyString &);  //THIS IS AN OPERATOR OVERLOAD of the Equals sign =  What this does is call the COPY method.

				bool	   operator < 				 (const MyString &) const;
				bool	   operator < 				 (const char []) const;
				MyString  operator &				 (const MyString &) const; //Contcatenation Operator &  //NOTE Both the Standard C++ and Microsoft VS string class uses the '+' operator for concatenation.
				MyString  operator &				 (const char []);
			//			   operator &=				 (); //Concat with assignment.
						   operator const char *	 () const;//const here because they are not changing anything in the class.

	private:
		unsigned long	numChars; //size_t aka unsigned long (positive only)
		size_t numSlots;
		char * pData;

	//temporary variables for concatenation
		size_t numTempChars;
		size_t numTempSlots;
		char * pTempData;


};//--------------__END OF CLASS ----------------------------------



//---------------INLINE FUNCTIONS --------------------------------


inline ostream & operator << (ostream & out, const MyString & str){//ostream (our console output will change)

//  out << str.pData;  //cannot do unless this is a friend since pData is private
	out << (const char *) str;
	return out;
}

inline istream & operator >> (istream & in, MyString & str){

	str.Read (in);
	return in;


}

inline MyString::operator const char * () const{

	return pData;
}

inline int MyString::Compare(const MyString & str) const {
	return strcmp (pData, str.pData);

}

inline int MyString::Compare(const char str []) const{
	return strcmp (pData, str);

}


inline unsigned long MyString::Len() const{

	return numChars;

}

inline MyString & MyString::operator = (const MyString & str){

	return Copy (str);
}


// ----------------------Handles the string case -----------------------
inline bool MyString::operator < (const MyString & str) const{

	return Compare (str) < 0; //if compare is 0 or 1, return false, if -1 True. The first one is before the second.
}

//--------------------------Hanles the c-type string case------------
inline bool MyString::operator < (const char str [] ) const{

	return Compare (str) < 0; //if compare is 0 or 1, return false, if -1 True. The first one is before the second.
}

inline bool operator < (const char pChar [], const MyString & str) {

	return str.Compare (pChar) > 0; //if compare is 0 or 1, return false, if -1 True. The first one is before the second.
}

#endif /* MYSTRING_H_ */

