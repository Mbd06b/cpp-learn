/*
 * Name.h
 *
 *  Created on: Mar 28, 2016
 *      Author: mbd06b
 */

#ifndef NAME_H_
#define NAME_H_
#include "myStringclass.h"
#include <iostream>

using namespace std;

enum whichName {first, middle, last, enumEnd};

class Name {



	public:						Name (); //constructor
								Name (const Name &); //copy
								~Name();


					String  	getName		(const whichName) const; //enum whichName "first, middle, last"
					Name &      setName		(const String &, whichName); //enum whichName "first, middle, or last"

					Name &		setFirst	(const String &);
					Name &		setMiddle	(const String &);
					Name &		setLast		(const String &);


					int			Compare     (const Name &) const;
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

Name::Name(){ //values default set blank
	sFirst = ("");
	sMiddle = ("");
	sLast = ("");

}

Name::Name(const Name & toCopy){
	sFirst = toCopy.sFirst;
	sMiddle = toCopy.sMiddle;
	sLast = toCopy.sLast;
}

Name::~Name(){
};


Name & Name::setName (const String & str, whichName num){

	if(num == first){
	sFirst = str;
	}
	if(num == middle){
	sMiddle = str;
	}
	if(num == last){
	sLast = str;
	}
	return *this;
}

Name & Name::setFirst(const String & str){
   sFirst = str;
   return *this;
}


Name & Name::setMiddle(const String & str){
  sMiddle = str;
  return *this;
};

Name & Name::setLast(const String & str){
   sLast = str;
   return *this;
};


String  Name::getName(const whichName num) const{

	if(num == first){
	return sFirst;
	}

	else if(num == middle){
	return sMiddle;
	}
	else
	return sLast;

}


inline int Name::Compare(const Name & thisName) const {

	int check;
	check = strcmp(sLast, thisName.sLast);
		if(check == 0){ 								//if last names are the same, check
			check = strcmp(sFirst, thisName.sFirst);	    //check first names
			  if (check == 0){							//if first names are the same,
					check = strcmp(sMiddle, thisName.sMiddle); 	//check middle
					  if (check == 0){					//if all names are the same
						  	  	  return check;					//return check, which == 0 ;
					  }else return check; 				//middle is > or < 0;
			 }else return check; 						//first is > or < 0;
		}else return check; 							//last is > or < 0;


};


//inline void Name::Display(){
//	cout << sFirst << " " << sMiddle << " " << sLast;
//}

Name & Name::operator = (const Name & toCopy){

	if(this != &toCopy){
	sFirst = toCopy.sFirst;
	sMiddle = toCopy.sMiddle;
	sLast = toCopy.sLast;
	}else;
	return *this;

}

inline istream & operator >> (istream & in, Name & myName){

	myName.Read (in);
	return in;
}

inline void Name::Display (){
	cout << sFirst << " " << sMiddle << " " << sLast << '\n';
}

inline ostream & Name::Display (ostream & out) const
	{
	return out;
	}

inline ostream & operator << (ostream & out, Name & myName){

  return out << myName.getName(first) << " " << myName.getName(middle) << " " << myName.getName(last);


}


//-------------------Comparison Operators---------------------------------
inline bool Name::operator <= (const Name & N2) const{
	return ((Compare(N2)) <= (0));
}

inline bool Name::operator == (const Name & N2) const{
	return ((Compare(N2)) == (0));
}

inline bool Name::operator >= (const Name & N2) const{
	return ((Compare(N2)) >= (0));
}

inline bool Name::operator != (const Name & N2) const{
	return ((Compare(N2)) != (0));
}

inline bool Name::operator > (const Name & N2) const{
	return ((Compare(N2)) > (0));
}

inline bool Name::operator < (const Name & N2) const{
	return ((Compare(N2)) < (0));
}
/**/

#endif /* NAME_H_ */
