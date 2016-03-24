/*
 * Namefunc.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: mbd06b
 */


#include "Name.h"


Name::Name (){  //default constructor

	//will automatically call the constructor for any members class from the library WCS_Name
	// the constructors are called before anything else inside the { } is done.
}


Name::Name (const Name & N): First (N.First), Last (N.Last), Middle (N.Middle){


}

Name::~Name (){ //destructor,
	//automatically calls the destructor for each member class (ie..First Middle & Last).
	//inside the { } gets done
}

Name & Name::operator = (const Name & N){

	First 	= N.First;
	Middle	= N.Middle;
	Last	= N.Last;
	return * this;
}

Name::Name (const WCS_String & L, const WCS_String & F, const WCS_String & M): First (F), Last (L), Middle (M){ //L-last, F-first, M-Middle
	// we are calling our constructors from WCS_STRING, we don't need to manually create our construtors.

}


int Name::Compare (const Name & N) const{

	int 	ReturnCode;

	ReturnCode = Last.Compare (N.Last);

	if (ReturnCode != 0){ //if the first name is not the same as the perameter, just return the result.
		return ReturnCode;

		else{
			ReturnCode = First.Compare (N.First); //if our last names match, check first names
			if (ReturnCode != 0) {
				return ReturnCode;
					else{
						return Middle.Compare (N.Middle); //if both our first and last names match return the result ?<0<? of comparing the middle name.
					}
			}
		}
	}
}


bool Name::SetFirst (const WCS_String & Str){
	First = Str;
	return true; //validation can be added later, but we are just going to make this true.
}
