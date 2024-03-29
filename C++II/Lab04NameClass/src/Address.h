/*
 * Address.h
 *
 *  Created on: Apr 4, 2016
 *      Author: mbd06b
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <iostream>
#include "myStringclass.h"


class Address{

	public:
					     Address			();
						 Address 			(Address &); //copy
				virtual ~Address			();


				String   	 getStreet		() const;
				String   	 getCity  		() const;
				String   	 getState       () const;
				String   	 getZip         () const;

				Address &    setStreet (const String &);
				Address &    setCity   (const String &);
				Address &    setState  (const String &);
				Address &    setZip    (const String &);

				bool		 Compare    (const Address &) const;
				void	 	Display 	();
				ostream &  	 Display 	(ostream & = cout)const;


				//operators
				void		    Read	 (istream &);//method used to facilitate the read in '>>' operator.
		        Address & 	    operator = 	 (const Address &);
		        bool 			operator ==  (const Address &) const;
		        bool            operator !=  (const Address &) const;

private:
	String sStreet;
	String sCity;
	String sState;
	String sZip;

};

Address::Address(){
		sStreet = "";
		sCity = "";
	    sState = "";
	    sZip = "";
	}

Address::Address(Address & toCopy){
	sStreet = toCopy.sStreet;
	sCity = toCopy.sCity;
	sState = toCopy.sState;
	sZip = toCopy.sZip;
}

Address::~Address() {
}



String Address::getStreet()const{
	return sStreet;
};

String  Address::getCity()const{
	return sCity;
};

String Address::getState()const{
	return sState;
};

String Address::getZip()const{
	return sZip;
};

Address & Address::setStreet(const String & str){
	sStreet = str;
	return *this;
}
Address & Address::setCity(const String & str){
	sCity = str;
	return *this;
}Address & Address::setState(const String & str){
	sState = str;
	return *this;
}Address & Address::setZip(const String & str){
	sZip = str;
	return *this;
}

Address & Address::operator = (const Address & toCopy){

	if(this != &toCopy){
	sStreet = toCopy.sStreet;
	sCity = toCopy.sCity;
	sState = toCopy.sState;
	sZip = toCopy.sZip;
	}else;

	return *this;

}

inline bool Address::Compare(const Address & thisAddress) const {

	if((strcmp(sStreet, thisAddress.sStreet) == 0) && (strcmp(sCity, thisAddress.sCity) == 0) && (strcmp(sState, thisAddress.sState) == 0) && (strcmp(sZip, thisAddress.sZip) == 0)){
	     return true;
	}else
		  return false;
};


inline istream & operator >> (istream & in, Address & myAddress){

	myAddress.Read (in);
	return in;
}

inline void Address::Display (){
	cout << sStreet << " " << sCity << " " << sState << " " << sZip;
}

inline ostream & Address::Display (ostream & out) const{
	return out;
	}

inline ostream & operator << (ostream & out, Address & A){

  return out << A.getStreet() << " " << A.getCity() << " " << A.getState() << " " << A.getZip();
}

//comparisons
inline bool Address::operator == (const Address & N) const{
	return Compare(N); //compare N is true they are equal
}

inline bool Address::operator != (const Address & N2) const{
	return Compare(N2); //returns false
}

#endif /* ADDRESS_H_ */
