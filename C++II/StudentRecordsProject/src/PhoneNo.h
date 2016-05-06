
#ifndef PHONENO_H_
#define  PHONENO_H_


#include "FLdigitString.h"


class phoneNo {

public:			phoneNo ();
				phoneNo (phoneNo &);
				~phoneNo ();

		phoneNo & 		Copy		(const phoneNo &);
		phoneNo & 		setareaCode (const FLdigitString<3> &);
		phoneNo &		setphoneNum (const FLdigitString<7> &);

		void	Display ();
const   phoneNo & 			 getfullPhoneNum () const;
const 	FLdigitString<3> &     getareaCode   () const;
const   FLdigitString<7> & 	  getphoneNum	() const;

		phoneNo & operator = (const phoneNo &);



		phoneNo & 	setAt	();
		void    Copy    ();




private:
	FLdigitString<3> areaCode;
	FLdigitString<7> phoneNum;


};


#endif /* PHONENO_H_ */
