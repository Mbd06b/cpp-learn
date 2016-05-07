
#ifndef FLDIGITSTRING_H_
#define FLDIGITSTRING_H_


#include "digitString.h"
#include "myStringclass.h"


template <size_t L> //Length of FLString + 1 including EOS mark
class FLdigitString : public digitString{

public:
			FLdigitString ();
virtual		~FLdigitString ();


			FLdigitString<L> &	Copy 	 (const digitString &);
			FLdigitString<L> &  Copy 	 (const String &);
			FLdigitString<L> &  Copy	 (const char []);
			FLdigitString<L> &	setAt	 (char, int);
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

template <size_t L>
FLdigitString<L>::FLdigitString(){

	size_t i = 0;
	for (i = 0; i < L; i++){
		String::setAt('0', i);
	};
	String::setAt('\0', L);
}
/*
template<size_t L>
FLdigitString<L> & FLdigitString<L>::makeString(){
	for(size_t i = 0; i < L; i++){
		setAt('0', i);
	}
 return *this;
}
*/
//destructor
template <size_t L>
FLdigitString<L>::~FLdigitString(){
};


template <size_t L>
FLdigitString<L> & FLdigitString<L>::setAt(char c, int i){
	if(i <= L){
	String::setAt(c,i);
	}else;
	return *this;
}

template <size_t L>
FLdigitString<L> &  FLdigitString<L>::setFLDstring (const String & str){
	size_t i = 0;
	for (i = 0; i < L; i++){
		String::setAt(str[i], i);
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
 *
 if(strlen(str) != L){
				throw invalid_argument("String is not the right size (FLdS = Op str[])");
			}else

	for(size_t i = 0; i < L; i++){
		setAt(str[i],i);
	}
	if(!digitCheck()){
	throw invalid_argument("digitString class can only accept digits (FLds = Op str[]");
			}else

	return * this;
}

*/
#endif /* SRC_ADDRESS_H_ */
