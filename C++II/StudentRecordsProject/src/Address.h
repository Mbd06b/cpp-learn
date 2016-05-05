/*
 * Address.h
 *
 *  Created on: Apr 27, 2016
 *      Author: mbd06b
 */

#ifndef SRC_ADDRESS_H_
#define SRC_ADDRESS_H_

#include "myStringclass.h"
#include "FLdigitString.h"
#include <iostream>


class Address{

public:
				Address ();
				Address (Address &);
				~Address ();

		const	Address &  			getAddress  () const;
		const 	String  &			getStreet	() const;
		const 	String  &			getCity		() const;
		const	String    & 		getState    () const;
		const 	FLdigitString<6> &   getZip 	() const;

				Address & 			setAddress	(const String &, const String &, const String &, const FLdigitString<6> &);
				Address &   		setStreet   (const String &);
				Address &  			setCity     (const String &);
				Address &   		setState	(const String &);
				Address & 			setZip		(const FLdigitString <6> &);
	//			Address &   setState    (const String &);


				int			Compare     (const Address &) const;
				ostream & 	Display 	(ostream & = cout)const;
				void 		Display		();

				//operators
				void		    Read	 (istream &);//method used to facilitate the read in '>>' operator.
				Address & 	    operator = 	 (const Address &);


				//comparisons



private:
	String street;
	String city;
	String	state;
	FLdigitString<6> zip;
};





#endif /* ADDRESS_H_ */
