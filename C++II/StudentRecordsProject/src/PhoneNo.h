
#ifndef PHONENO_H_
#define  PHONENO_H_


#include "DigitString.h"


class phoneNo {

public:			phoneNo ();
				phoneNo (phoneNo &);
				~phoneNo ();



private:
	digitString areaCode; //FL 3
	digitString directPhone; //FL 7


};


#endif /* PHONENO_H_ */
