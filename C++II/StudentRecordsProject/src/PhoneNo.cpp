/*
 * PhoneNo.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#include "PhoneNo.h"



phoneNo::phoneNo(){
};

phoneNo::phoneNo(phoneNo & str){
	areaCode = str.areaCode;
	phoneNum = str.phoneNum;
}

phoneNo::~phoneNo(){

}
phoneNo & phoneNo::Copy (const phoneNo & str){
	areaCode = str.areaCode;
	phoneNum = str.phoneNum;
	return *this;
}

phoneNo & phoneNo::operator = (const phoneNo & str){
		Copy(str);
		return *this;
}

phoneNo & phoneNo::setareaCode (const FLdigitString<3> & str){
	for(int i = 0; i < 3; i++){
		areaCode[i] = str[i];
	}
	return *this;
};

phoneNo & phoneNo::setphoneNum (const FLdigitString<7> & str){
	for(int i = 0; i < 7; i++){
		areaCode[i] = str[i];
	}
	return *this;

};

void phoneNo::Display(){
	cout << "(" << areaCode << ")" << " " << phoneNum << " ";
}

const phoneNo & phoneNo::getfullPhoneNum () const{
	return *this;
}

const FLdigitString<3> & phoneNo::getareaCode () const{

	return areaCode;
}

const FLdigitString<7> & phoneNo::getphoneNum() const {
	return phoneNum;
}
