/*
 * Address.h
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#ifndef SRC_ADDRESS_H_
#define SRC_ADDRESS_H_

#include "myStringclass.h"


class Address{

public:
				Address ();
				Address (Address &);
				~Address ();
private:
	String street;
	String city;
	//FLString 2 - Uppercase	state;
	//FLString 5- digitstring  zipcode;
};





#endif /* SRC_ADDRESS_H_ */
