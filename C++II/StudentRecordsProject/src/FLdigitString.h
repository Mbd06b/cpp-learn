
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
explicit	FLdigitString (const char []);
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

			char * pData;
			digitString &    Concat	 (const String &);
			digitString &    Concat	 (const char []);
			digitString   operator & (const String &);
			digitString   operator & (const char []);
			digitString & operator &= (const String &);
			digitString & operator &= (const char []);


};

template <size_t L>
FLdigitString<L>::FLdigitString(){

	pData = new char [L];
	for (int i = 0; i < L; i++){
		pData [i] = 0;
	};
}


template <size_t L>
FLdigitString<L>::FLdigitString(const digitString & dstr): digitString (dstr){
	pData = new char [L];
		for (int i = 0; i < L; i++){
			pData [i] = dstr[i];
		};


}

template <size_t L>
FLdigitString<L>::FLdigitString(const String & str):String(str){
	if(str.digitCheck()){
		throw invalid_argument("FLdigitString constructor received a String & str with a character that is not a digit");
	}else
	pData = new char [L];
		for (int i = 0; i < L; i++){
			pData [i] = str[i];
		};

}

template <size_t L>
FLdigitString<L>::FLdigitString (const char str []): String(str){
	String temp = str;
for(size_t i = 0; i < (L); i++){
			cout << str [i];
			if(!isdigit(str[i])){
				throw invalid_argument("FLdigitString constructor received a char str [] with a character that is not a digit");
			}else;
	};
			for (int i = 0; i < L; i++){
				pData [i] = str[i];
		};

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
		Copy (str);
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
