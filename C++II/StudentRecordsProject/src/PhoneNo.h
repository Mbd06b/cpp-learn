
#ifndef PHONENO_H_
#define  PHONENO_H_


#include "FLdigitString.h"


class phoneNo {

public:			phoneNo ();
				phoneNo (phoneNo &);
				~phoneNo ();

		phoneNo & 		Copy		(const phoneNo &);
		phoneNo & 		setareaCode (const FLdigitString<4> &);
		phoneNo &		setphoneNum (const FLdigitString<8> &);

		void	Display ();
const   phoneNo & 			 getfullPhoneNum () const;
const 	FLdigitString<4> &     getareaCode   () const;
const   FLdigitString<8> & 	  getphoneNum	() const;

		phoneNo & operator = (const phoneNo &);



		phoneNo & 	setAt	();
		void    Copy    ();




private:
	FLdigitString<4> areaCode;
	FLdigitString<8> phoneNum;


};


#endif /* PHONENO_H_ */
