/*
 * Address.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#include "Address.h"



Address::Address(){

}
Address::Address(Address &){

}
Address::~Address(){

}

const Address & Address::getAddress()const{
	return *this;
}

const String & Address::getStreet()const {
	return street;
}

const String &  Address::getCity()const{
	return city;
}

//Address &  Address::getState() const {};
//Address &  Address::getZip() const){};
//Address &  Address::setAddress(const String &, const String &, const FLUCString &, const FLdigitString &){};


Address & Address::setStreet(const String & str){
	street = str;
	return *this;
}
Address & Address::setCity(const String & str){
	city = str;
	return *this;
}
//Address &   Address::setState(const String &){};
//int	Address::Compare(const Address &) const{};



inline istream & operator >> (istream & in, Address & myAddress){

	myAddress.Read (in);
	return in;
}

inline void Address::Display (){
	cout << street << " " << city << " ";   // << state << " " << zip; ;
}

inline ostream & Address::Display (ostream & out) const{
	return out;
}

inline ostream & operator << (ostream & out, Address & myAddress){

  return out << myAddress.getStreet() << " " << myAddress.getCity(); // << " " << myAddress.getState() << " " << myAddress.getZip();
}
