
#ifndef PHONENO_H_
#define  PHONENO_H_


#include "DigitString.h"


class phoneNo {

public:			phoneNo ();
				phoneNo (phoneNo &);
				~phoneNo ();



private:
	FLdigitString<4> areaCode;
	FLdigitString<8> directPhone;


};


#endif /* PHONENO_H_ */
