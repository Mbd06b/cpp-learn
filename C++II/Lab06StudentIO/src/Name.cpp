
 /* Name.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: mbd06b
 */

#include "Name.h"


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

Name &  Name::getName(){
	return *this;
};


String &  Name::get1Name(const whichName num){

	if(num == first){
	return sFirst;
	}

	else if(num == middle){
	return sMiddle;
	}
	else
	return sLast;

}


 int Name::Compare(const Name & thisName) const {

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




