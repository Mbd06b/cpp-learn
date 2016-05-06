
#ifndef FLDIGITSTRING_H_
#define FLDIGITSTRING_H_


#include "digitString.h"
#include "myStringclass.h"


template <size_t L> //Length of FLString + 1 including EOS mark
class FLdigitString : public digitString{

public:
			FLdigitString ();
			FLdigitString (const digitString &);
			FLdigitString (const String &);
			FLdigitString (const char []);
virtual		~FLdigitString ();


			FLdigitString<L> &	Copy 	 (const digitString &);
			FLdigitString<L> &   Copy	 (const char []);
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
	makeString();
}


template <size_t L>
FLdigitString<L>::FLdigitString(const digitString & dstr): digitString (dstr){
/*	if(dstr.Length() != L){
		throw invalid_argument("String is not the right size (FLdS cpy constructor dS & dstr)");
	}else
*/
	for(size_t i = 0; i < L; i++){
		   setAt(dstr[i], i);
		}
}

template <size_t L>
FLdigitString<L>::FLdigitString(const String & str): digitString (str){
/*
	if(str.Length() != L){
			throw invalid_argument("String is not the right size (FLds cpy constructor &str)");
		}else
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accept digits (FLdS cpyconst &str)");
	}else
*/
	for(size_t i = 0; i < L; i++){
		setAt(str[i], i);
	}

}

template <size_t L>
FLdigitString<L>::FLdigitString (const char str []): digitString (str){
/*
		if(strlen(str) != L){
				throw invalid_argument("String is not the right size (FLds cpy constructor &str)");
			}else
		if(!digitCheck()){
			throw invalid_argument("digitString class can only accept digits (FLdS cpyconst &str)");
		}else
*/
	for(size_t i = 0; i < L; i++){
		setAt(str[i], i);
	}

}

template<size_t L>
FLdigitString<L> & FLdigitString<L>::makeString(){
	for(size_t i = 0; i < L; i++){
		setAt('0', i);
	}
 return *this;
}

//destructor
template <size_t L>
FLdigitString<L>::~FLdigitString(){
};

template <size_t L>
FLdigitString<L> & FLdigitString<L>::setAt(char c, int i){
	setAt(c,i);
	return *this;
}

template <size_t L>
FLdigitString<L> &  FLdigitString<L>::setFLDstring (const String & str){
/*
	if(!str.digitCheck()){ //if not a digit
			throw invalid_argument("digitString class can only accept digits (FLdS setFLDstring)");
		}else
	if(str.Length() != L){
		throw invalid_argument("Index out of Bounds(FLdS setFLDstring)");
	}else
*/
		for(size_t i = 0; i < L; i++){
			setAt(str[i],i);
		}
		return *this;
};


template <size_t L>
 FLdigitString<L> & FLdigitString<L>::operator = (const String & str){

	for(size_t i; i < L; i++){
		setAt(str[i], i);
	}

		return *this;
}

template <size_t L>
 FLdigitString<L> & FLdigitString<L>::operator = (const char str []){
/*
 *
 if(strlen(str) != L){
				throw invalid_argument("String is not the right size (FLdS = Op str[])");
			}else
*/
	for(size_t i = 0; i < L; i++){
		setAt(str[i],i);
	}
	if(!digitCheck()){
	throw invalid_argument("digitString class can only accept digits (FLds = Op str[]");
			}else

	return * this;
}


#endif /* SRC_ADDRESS_H_ */
