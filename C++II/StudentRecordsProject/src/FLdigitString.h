
#ifndef FLDIGITSTRING_H_
#define FLDIGITSTRING_H_


#include "digitString.h"
#include "myStringclass.h"


template <size_t L> //Length of FLString starts at 0, EOS mark
class FLdigitString : public digitString{

public:
			FLdigitString ();
virtual		~FLdigitString ();


			FLdigitString<L> &	Copy 	 (const digitString &);
			FLdigitString<L> &  Copy 	 (const String &);
			FLdigitString<L> &  Copy	 (const char []);
			FLdigitString<L> &  setFLDstring (const String &);
			FLdigitString<L> & operator = (const String &);
			FLdigitString<L> & operator = (const char []);
			FLdigitString<L> & makeString ();


private:


			digitString &    Concat	 (const String &);
			digitString &    Concat	 (const char []);
			digitString   operator & (const String &);
			digitString   operator & (const char []);
			digitString & operator &= (const String &);
			digitString & operator &= (const char []);


};

//constructor initializes my FLdS from scratch when the variable is called
template <size_t L>
FLdigitString<L>::FLdigitString() : digitString (L){

}

//destructor
template <size_t L>
FLdigitString<L>::~FLdigitString(){
};


template <size_t L>
FLdigitString<L> &  FLdigitString<L>::setFLDstring (const String & str){
	size_t i = 0;
	for (i = 0; i == L; i++){
		setAt(str[i], i);
	};
		return *this;
};

template <size_t L>
FLdigitString<L> & FLdigitString<L>::Copy(const String & str){
		Copy(str);
		return *this;
}

template <size_t L>
 FLdigitString<L> & FLdigitString<L>::operator = (const String & str){
		Copy(str);
		return *this;
}

template <size_t L>
 FLdigitString<L> & FLdigitString<L>::operator = (const char str []){
		Copy(str);
		return *this;
}
/*


*/
#endif /* SRC_ADDRESS_H_ */
