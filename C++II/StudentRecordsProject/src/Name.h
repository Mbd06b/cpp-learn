/*
 * Name.h
 *
 *  Created on: Mar 28, 2016
 *      Author: mbd06b
 */

#ifndef NAME_H_
#define NAME_H_
#include "myStringclass.h"
#include "fileCommands.h"
#include <iostream>

using namespace std;

enum whichName {first, middle, last, enumEnd};


class Name {
	public:


								Name (); //constructor
								Name (const Name &); //copy
								~Name();

				const Name  &	getName		()const;
				const String &	get1Name	(const whichName)const;//enum whichName "first, middle, last"
					Name &      setName		(const String &, whichName); //enum whichName "first, middle, or last"

					Name &		setFirst	(const String &);
					Name &		setMiddle	(const String &);
					Name &		setLast		(const String &);


					int			Compare     (const Name &, const CompareOption) const;
					int			sortCompare     (const Name &, const CompareOption) const;
					ostream & 	Display 	(ostream & = cout)const;
					void 		Display		();

					//operators
					void		    Read	 (istream &);//method used to facilitate the read in '>>' operator.
			        Name & 	    operator = 	 (const Name &);


			        //comparisons
			        bool  operator <= (const Name &) const;
			        bool  operator == (const Name &) const;
			        bool  operator != (const Name &) const;
			        bool  operator >= (const Name &) const;
			        bool  operator >  (const Name &) const;
			        bool  operator <  (const Name &) const;


	private:
	String sFirst;
	String sMiddle;
	String sLast;



};


inline istream & operator >> (istream & in, Name & myName){

	myName.Read (in);
	return in;
}

inline void Name::Display (){
	cout << sFirst << " " << sMiddle << " " << sLast;
}

inline ostream & Name::Display (ostream & out) const
	{
	return out;
	}

inline ostream & operator << (ostream & out, Name & myName){

  return out << myName.get1Name(first) << " " << myName.get1Name(middle) << " " << myName.get1Name(last);


}


//-------------------Comparison Operators---------------------------------
inline bool Name::operator <= (const Name & N2) const{
	return ((Compare(N2, option)) <= (0));
}

inline bool Name::operator == (const Name & N2) const{
	return ((Compare(N2, option)) == (0));
}

inline bool Name::operator >= (const Name & N2) const{
	return ((Compare(N2, option)) >= (0));
}

inline bool Name::operator != (const Name & N2) const{
	return ((Compare(N2, option)) != (0));
}

inline bool Name::operator > (const Name & N2) const{
	return ((Compare(N2, option)) > (0));
}

inline bool Name::operator < (const Name & N2) const{
	return ((Compare(N2, option)) < (0));
}
/**/

#endif /* NAME_H_ */
