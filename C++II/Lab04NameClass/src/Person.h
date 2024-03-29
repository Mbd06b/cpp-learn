/*
 * Person.h
 *
 *  Created on: Apr 4, 2016
 *      Author: mbd06b
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "Name.h"
#include "Address.h"

class Person{
	public:
								Person ();
								Person (const Person &);
								Person (const Name &, const Address &);
								~Person ();


								Name    	 getName		();
								Address   	 getAddress		();

								String     getFName ()const;
								String	   getMName ()const;
								String	   getLName()const;
								String	   getStreet()const;
								String	   getCity () const;
								String	   getState() const;
								String     getZip () const;



								Person &    setPerson    (const Name &, const Address &);
								Person &	setNameData  (const Name &);
								Person &	setAddressData (const Address &);

								Person &    setFName  (const String &);
								Person &    setMName  (const String &);
								Person &    setLName  (const String &);
								Person &    setStreet (const String &);
								Person &    setCity   (const String &);
								Person &    setState  (const String &);
								Person &    setZip    (const String &);





								void	 	Display 	();
								ostream &  	 Display 	(ostream &)const;


								//operators
								void		    Read	 (istream &);//method used to facilitate the read in '>>' operator.
						        Person & 	    operator = 	 (const Person &);


	private:
		Name nameData;
		Address addressData;

};

Person::Person(){
}

Person::Person(const Person & toCopy){
	nameData = toCopy.nameData;
	addressData = toCopy.addressData;
}

Person::Person(const Name & aName, const Address & aAddress ){
	nameData = aName;
	addressData = aAddress;
};

Person::~Person(){
}


Name      Person::getName() {
	 return nameData;
}

Address   Person::getAddress ()  {
	return addressData;
}

String Person::getFName()const{
	return nameData.getName(first);
}

String	Person::getMName ()const{
	return nameData.getName(middle);
}
String	Person::getLName()const{
   return nameData.getName(last);
}
String	Person::getStreet()const{
	return addressData.getStreet();
}
String	Person::getCity () const{
	return addressData.getCity();
}
String	Person::getState() const {
	return addressData.getState();
}
String  Person::getZip () const {
	return addressData.getZip();
}

Person & Person::setPerson (const Name & aName, const Address & aAddress){
	nameData = aName;
	addressData = aAddress;
	return *this;
}


Person & Person::setNameData(const Name & aName){
	nameData = aName;
	return *this;
}

Person & Person::setAddressData(const Address & aAddress){
	addressData = aAddress;
	return *this;
}


Person &  Person::setFName  (const String & str){
	nameData.setName(str, first);
	return *this;
}
Person &  Person::setMName  (const String & str){
	nameData.setName(str,middle);
	return *this;
}

Person &  Person:: setLName  (const String & str){
	nameData.setName(str,last);
	return *this;
}
Person &  Person::setStreet (const String & str){
	addressData.setStreet(str);
	return *this;
}
Person &  Person::setCity   (const String & str){
	addressData.setCity(str);
	return *this;
}

Person &  Person::setState  (const String & str){
	addressData.setState(str);
	return *this;
}
Person &  Person::setZip    (const String & str){
	addressData.setZip(str);
	return *this;
}


inline void	 	Person::Display (){
	nameData.Display();
	addressData.Display();
}


inline ostream &  Person::Display (ostream & out)const{
	return Display(out);
}


//operators
inline istream & operator >> (istream & in, Person & myPerson) {
	myPerson.Read (in);
		return in;

}

inline ostream & operator << (ostream & out, Person & A){

  out << A.getFName() << " " << A.getMName() << " " << A.getLName() << '\n'
      << A.getStreet() << " " << A.getCity() << " " << A.getState() << " " << A.getZip();

  return out;
}

Person &   Person::operator =  (const Person & toCopy){
		if (this != &toCopy){
		nameData = toCopy.nameData;
		addressData = toCopy.addressData;
		}else;
		return *this;
}




#endif /* PERSON_H_ */
