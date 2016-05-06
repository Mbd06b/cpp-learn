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

Address & Address::Copy (const Address & str){
	 street = str.street;
	 city = str.city;
	 state = str.state;
	 zip = str.zip;
	 return *this;

}

Address & Address::operator = (const Address & str){
	  return Copy(str);
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

const String &  Address::getState() const {
	return state;
};

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
Address &  Address::setState(const String & str){
	state = str;
	return *this;
};

Address & Address::setZip(const FLdigitString<6> & str){
	for(int i = 0; i < 5; i++){
		zip[i] = str [i];
	}
	return *this;
}


//int	Address::Compare(const Address &) const{};



inline istream & operator >> (istream & in, Address & myAddress){

	myAddress.Read (in);
	return in;
}

 void Address::Display (){
	cout << street << ", " << city << ", " << state << " " << zip;
}

 ostream & Address::Display (ostream & out) const{
	return out;
}

 ostream & operator << (ostream & out, Address & myAddress){

  return out << myAddress.getStreet() << " " << myAddress.getCity(); // << " " << myAddress.getState() << " " << myAddress.getZip();
}


