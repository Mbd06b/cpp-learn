
#ifndef FLDIGITSTRING_H_
#define FLDIGITSTRING_H_


#include "digitString.h"
#include "myStringclass.h"


template <size_t L> //Length of FLString starts at 0, EOS mark
class FLdigitString : public digitString{

public:
			FLdigitString ();
			FLdigitString (const char []);
			FLdigitString (const String &);
			FLdigitString (const FLdigitString<L> &);
			~FLdigitString ();

			FLdigitString<L> &  Copy	 (const FLdigitString<L> &);
			FLdigitString<L> &  setFLDstring (const FLdigitString<L> &);
	  const FLdigitString<L> &  getFLDstring () const;
			FLdigitString<L> & operator = (const String &);
			FLdigitString<L> & operator = (const char []);
			FLdigitString<L> & makeFLDString ();
			istream & readFLSDigits (istream &); //pairs with readFLDigits

			ostream & operator  << 	 (const FLdigitString<L> &);
			ostream & operator << 	(const char []);
			istream &       Read       (istream &);//method used to facilitate the read in '>>' operator.
			istream & operator  >> 	 (const FLdigitString<L> &);
			istream & operator >>	(const char []);




private:


			istream & readDigits 	 (istream &);
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

template <size_t L>
FLdigitString<L>::FLdigitString(const char str []) : digitString (str, L){

};



template <size_t L>
FLdigitString<L>::FLdigitString(const FLdigitString<L> & str){

};
//destructor
template <size_t L>
FLdigitString<L>::~FLdigitString(){
};

//------------------------ ------------------------------------------
//Display function (Display) to display the characters in the String object.


template<size_t L>
inline ostream & operator << (ostream & out, const FLdigitString<L> & str){

//  out << str.pData2;  //cannot do unless this is a friend since pData2 is private
	out << (const char *) str;
	return out;
}

template<size_t L>
inline istream & operator >> (istream & in, FLdigitString<L> & str){   //this is a stand-alone operator, because we are using

	str.Read (in);
	return in;
}

template <size_t L>
const FLdigitString<L> &  FLdigitString<L>::getFLDstring () const{
	 return *this;
}

template <size_t L>
FLdigitString<L> &  FLdigitString<L>::setFLDstring (const FLdigitString<L> & str){
	 	 Copy(str);
		return *this;
};

template <size_t L>
FLdigitString<L> & FLdigitString<L>::Copy(const FLdigitString<L> & str){
	size_t i = 0;
	for (i = 0; i == L; i++){
		setAt(str[i], i);
	};
		return *this;
};


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



template <size_t L>
istream & operator >> (istream & in, FLdigitString<L> str){
	return str.Read(in);
}




/*


*/
#endif /* SRC_ADDRESS_H_ */
