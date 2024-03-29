/*
 * class.h
 *
 *  Created on: Feb 3, 2016
 *      Author: mbd06b
 */

#ifndef MYSTRINGCLASS_H_
#define MYSTRINGCLASS_H_

#include <iostream>
#include <string.h>
using namespace std;



class String{

	public:
					String		 (); //Default constructor.- "one with no parameters to initialize the class to empty;"
					String		 (const char []);//C-TYPE Constructor one with a pointer to a “C” type string as a parameter to initialize the class to contain a copy of that string;
					String 		 (const String &);//COPY Class Constructor and one with a parameter that is of class String to initialize to a copy of that value.

					~String		 (); //Destructor



//------------Methods---------------
			int		    Compare  (const char []) const;//"Comparison function (Compare) to allow the comparison of the String object to another String object or to a “C” type string."
			int			Compare  (const String &) const;

			//Length function (Len) to return the number of characters stored in the String object.
			unsigned long 	Length      () const;
			void 			Display     () const;
			void		    Read		(istream &); //method used to facilitate the read in '>>' operator.


//"Copy function (Copy) to copy another String object into this one or copy a “C” type string into this object."
			String &	Copy 	 (const String &); //STRING COPY
			String & 	Copy 	 (const char []); //CTYPE STRING COPY
			String &    Concat	 (const String &);
			String &    Concat	 (const char []);
			char		Concat   (const String &) const;
			char 		Concat	 (const char []) const;





//------------------------------------- OPERATORS ------------------

		//------------------copyoperator #1 ("=")---------------
		//Items 1 and 4 will require a String object on the left of the operator.
			String & operator  = (const String &);
			String & operator = (const char []);

		//------------------Comparison operators #2 (“<”, “<=”, “==”, “!=”, “>=”, “>”)-----------
	    //Items 2 and 3 should have versions that allow both a String object and a “C” type string on the left of the operator

			bool	 operator <  (const String &) const;
			bool	 operator <  (const char []) const;
			bool	 operator <= (const String &) const;
			bool	 operator <= (const char []) const;
			bool	 operator == (const String &) const;
			bool	 operator == (const char []) const;
			bool	 operator != (const String &) const;
			bool	 operator != (const char []) const;
			bool     operator >= (const String &) const;
			bool     operator >= (const char []) const;
			bool     operator > (const String &)const;
			bool     operator > (const char [])const;

	    //------------Concatenation operator #3 (“&”) and  #4 Concatenation and assignment operator (“&=”)
        //Items 2 and 3 should have versions that allow both a String object and a “C” type string on the left of the operator
		//Item 3 does not modify the object to the left of the operator.
		//Items 1 and 4 will require a String object on the left of the operator.
			String   operator & (const String &);
			String   operator & (const char []);
			String & operator &= (const String &);
			String & operator &= (const char []);




		//-------------Input operator #5 (“>>”). and # 6 Output operator (“<<”).
		//Items 5 and 6 require a String object to the right of the operator.
			istream & operator  >> 	 (const String &);
			istream & operator >>	(const char []);
			ostream & operator  << 	 (const String &);
			ostream & operator << 	(const char []);


		//other operators
			 operator const char *	 () const;//const here for the ostream Display method because they are not changing anything in the class.


	private:
		size_t	numChars; //size_t aka unsigned long (positive only)
		size_t numSlots;
		char * pData;

		//variables for concatenation
		size_t numTempChars;
		size_t numTempSlots;
		char * pTempData;

};

//Comparison function (Compare) to allow the comparison of the String object to another String object or to a “C” type string.
inline int String::Compare (const char str []) const{

	return strcmp(pData, str); //will return negative number,0, or greater than zero;
};

inline int String::Compare(const String & str) const{

	return strcmp(pData,str);
}

inline String::operator const char * () const{
	return pData;
}

inline unsigned long String::Length() const{

	return numChars;

}

//DISPLAY FUNCTION

inline void  String::Display() const{

	cout << pData << endl;

};


//----------------------------------------------------------------- INLINE OPERATORS -------------------------------------------
//1 Copy
inline String & String::operator = (const String & str){

	return Copy (str);
}

inline String & String::operator = (const char str []){

	return Copy (str);
}


//#2 Comparison
// ----------------------Handles the string case -----------------------
inline bool String::operator < (const String & str) const{

	return Compare (str) < 0; //if compare is less than zero, return True.
}

//--------------------------Hanles the c-type string case------------
inline bool String::operator < (const char str []) const{

	return Compare (str) < 0; //if compare is less than zero, return True
}

//---------------------------This inline bool, services both is built by using both operator overload types.
// the pChar identified in the parameter is simply specific so we can identify the difference in the inline function.
inline bool operator < (const char pChar [], const String & str) {

	return str.Compare (pChar) > 0; //if compare is 0 or 1, return false, if -1 True. The first one is before the second.
}

//------------------------------------------------------------------------------------------

inline bool String::operator <= (const String & str) const{

	return Compare (str) <= 0;
}

inline bool String::operator <= (const char str []) const{

	return Compare (str) <= 0;
}

inline bool operator <= (const String & str, const char pChar []){

	return str.Compare (pChar) <= 0;
}

inline bool operator <= (const char pChar [], const String & str){

	return str.Compare (pChar) <= 0;
}

//------------------------------------------------------------------------------------------

inline bool String::operator == (const String & str) const{

	return Compare (str) == 0;
}

inline bool String::operator == (const char str []) const{

	return Compare (str) == 0;
}

inline bool operator == (const String & str, const char pChar []){

	return str.Compare (pChar) == 0;
}

inline bool operator == (const char pChar [], const String & str){
	return str.Compare (pChar) == 0;
}

//------------------------------------------------------------------------------------------

inline bool String::operator != (const String & str) const{

	return Compare (str) != 0;
}

inline bool String::operator != (const char str []) const{

	return Compare (str) != 0;
}

inline bool operator != (const String & str, const char pChar []){

	return str.Compare (pChar) != 0;
}

inline bool operator != (const char pChar [], const String & str){

	return str.Compare (pChar) != 0;
}

//-----------------------------------------------------------------------------------------
inline bool String::operator >= (const String & str) const{

	return Compare (str) >= 0;
}

inline bool String::operator >= (const char str []) const{

	return Compare (str) >= 0;
}

inline bool operator >= (const String & str, const char pChar []){

	return str.Compare (pChar) >= 0;
}

inline bool operator >= (const char pChar [], const String & str){

	return str.Compare (pChar) >= 0;
}

//------------------------------------------------------------------------------------------


inline bool String::operator > (const String & str) const{

	return Compare (str) > 0;
}

inline bool String::operator > (const char str []) const{

	return Compare (str) > 0;
}

inline bool operator > (const char pChar [], const String & str){

	return str.Compare (pChar) > 0;
}

inline bool operator > ( const String & str, const char pChar []){

	return str.Compare (pChar) > 0;
}


//--------------------------Concatenation Operators &, and &= ----------------------------
//#3 & #4

inline String & String::operator &= (const char str []){

	return Concat (str);
}

inline String & String::operator &= (const String & str){

	return Concat (str);
}



inline String String::operator & (const char str []){

	String temp (*this);
	temp.Concat (str);
	return temp;
}

inline String String::operator & (const String & str){

		String temp (*this);
		temp.Concat (str);
		return temp;
}

inline String operator & (const String & str, const char pChar []){

	String temp (str);
	temp.Concat (str);
	return temp;

}





//------------------------ ------------------------------------------
//Display function (Display) to display the characters in the String object.
inline ostream & operator << (ostream & out, const String & str){

//  out << str.pData;  //cannot do unless this is a friend since pData is private
	out << (const char *) str;
	return out;
}

inline istream & operator >> (istream & in, String & str){

	str.Read (in);
	return in;
}

/*

Modify Program One to add the following:
Assignment operator (“=”).
Comparison operators (“<”, “<=”, “==”, “!=”, “>=”, “>”)
Concatenation operator (“&”).
Concatenation and assignment operator (“&=”)


Above items 1 through 4 should have versions that work with a String object and a “C” type string on the right of the operator.
Items 1 and 4 will require a String object on the left of the operator.

 */




#endif /* MYSTRINGCLASS_H_ */
