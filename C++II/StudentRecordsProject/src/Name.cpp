
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

const Name &  Name::getName() const{
	return *this;
};


const String &  Name::get1Name(const whichName num) const{

	if(num == first){
	return sFirst;
	}

	else if(num == middle){
	return sMiddle;
	}
	else
	return sLast;

}


 int Name::Compare(const Name & thisName, CompareOption option) const {

	 int check;
//compare for Last
	if(option == CompareLast){
		check = strcasecmp(sLast, thisName.sLast);
			if(check == 0){ 								//if last names are the same, check
				check = strcasecmp(sFirst, thisName.sFirst);	    //check first names
				  if (check == 0){							//if first names are the same,
						check = strcasecmp(sMiddle, thisName.sMiddle); 	//check middle
						  if (check == 0){					//if all names are the same
									  return check;					//return check, which == 0 ;
						  }else return check; 				//middle is > or < 0;
				 }else return check; 						//first is > or < 0;
			}else return check; 							//last is > or < 0;
	}else
//compare for First
	if (option == CompareFirst){
		check = strcasecmp(sFirst, thisName.sFirst);
			if(check == 0){ 								//if first names are the same, check
				check = strcasecmp(sLast, thisName.sLast);	    //check last names
				  if (check == 0){							//if last names are the same,
						check = strcasecmp(sMiddle, thisName.sMiddle); 	//check middle
						  if (check == 0){					//if all names are the same
							  	  	  return check;					//return check, which == 0 ;
						  }else return check; 				//middle is > or < 0;
				 }else return check; 						//first is > or < 0;
			}else return check; 							//last is > or < 0;
	}else

//compare for Middle
	if(option == CompareMiddle){
			check = strcasecmp(sMiddle, thisName.sMiddle);
				if(check == 0){ 								//if last names are the same, check
					check = strcasecmp(sLast, thisName.sLast);	    //check first names
					  if (check == 0){							//if first names are the same,
							check = strcasecmp(sFirst, thisName.sFirst); 	//check middle
							  if (check == 0){					//if all names are the same
								  	  	  return check;					//return check, which == 0 ;
							  }else return check; 				//middle is > or < 0;
					 }else return check; 						//first is > or < 0;
				}else return check; 							//last is > or < 0;
	}else
		cout << "Name Compare Failed" << endl;
		return false;
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




