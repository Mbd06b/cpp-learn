
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
			~FLdigitString ();


			FLdigitString<L> &	Copy 	 (const digitString &);
			FLdigitString<L> &   Copy	 (const char []);
			FLdigitString<L> &	setAt	 (char, int);
			FLdigitString<L> & operator = (const String &);
			FLdigitString<L> & operator = (const char []);


private:
		UCString   operator & (const String &);
		UCString   operator & (const char []);
		UCString & operator &= (const String &);
		UCString & operator &= (const char []);
		UCString & operator = (const String &);
		UCString & operator = (const char []);
		UCString &    Concat	 (const String &);
		UCString &    Concat	 (const char []);

};

template <size_t L>
FLdigitString<L>::FLdigitString(){
}


template <size_t L>
FLdigitString<L>::FLdigitString(const digitString & dstr){
	if(dstr.Length() != L){
		throw invalid_argument("String is not the right size");
	}
	pData = dstr;
}

template <size_t L>
FLdigitString<L>::FLdigitString(const String & str): String (str){
	if(str.Length() != L){
			throw invalid_argument("String is not the right size");
		};
	if(!digitCheck()){
		throw invalid_argument("digitString class can only accept digits");
	}

}

template <size_t L>
FLdigitString<L>::FLdigitString (const char str []): String (str){
	if(strlen(str) != L){
		throw invalid_argument("String is not the right size");
	};
	if(!digitCheck()){
			throw invalid_argument("digitString class can only accept digits");
		}
}

template <size_t L>
FLdigitString<L> & FLdigitString<L>::setAt(char c, int i){
	if(!isdigit(c)){ //if not a digit
			throw invalid_argument("digitString class can only accept digits");
		}else
	if(i > L){
		throw invalid_argument("Index out of Bounds")
	}
	String::setAt(c,i);
	return *this;
}

template <size_t L>
inline FLdigitString<L> & FLdigitString<L>::operator = (const String & str){
	String temp (str);
		if(!temp.digitCheck()){
			throw invalid_argument("digitString class can only accept digits");
		}else
		if(temp.Length() != L){
			throw invalid_argument("String is not the right size");
		}else
	String::Copy(str);

		return *this;
}

template <size_t L>
inline FLdigitString<L> & FLdigitString<L>::operator = (const char str []){
	String temp (str);
	if(!temp.digitCheck()){
				throw invalid_argument("digitString class can only accept digits");
			}else
	if(temp.Length() != L){
				throw invalid_argument("String is not the right size");
			}else
	 String::Copy(str);

	return * this;
}


#endif /* SRC_ADDRESS_H_ */
