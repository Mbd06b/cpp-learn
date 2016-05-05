/*
 * PhoneNo.cpp
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#include "PhoneNo.h"



phoneNo::phoneNo(){
};

phoneNo::phoneNo(phoneNo &){

}

phoneNo::~phoneNo(){

}


phoneNo & phoneNo::setareaCode (const FLdigitString<4> & str){
	String temp;
	for(int i = 0; i < 3; i++){
		temp[i] = str[i];
	}
	areaCode = temp;
	return *this;
};
phoneNo & phoneNo::setphoneNum (const FLdigitString<8> & str){
	String temp;
	for(int i = 0; i < 7; i++){
			temp[i] = str[i];
	}
	phoneNum = temp;
	return *this;
};
