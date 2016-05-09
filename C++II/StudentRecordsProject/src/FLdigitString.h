
#ifndef FLDIGITSTRING_H_
#define FLDIGITSTRING_H_


#include "digitString.h"
#include "myStringclass.h"
#include "fileCommands.h"
#include <ctype.h> // for isdigit;
#include <stdexcept>


template <size_t L> //Length of FLString starts at 0, EOS mark
class FLdigitString{

public:
			FLdigitString ();
			FLdigitString (const char []);
			FLdigitString (const String &);
			FLdigitString (const FLdigitString<L> &);
			~FLdigitString ();

			FLdigitString<L> &  Copy	 (const FLdigitString<L> &);
			int		   	    Compare  (const char []) const;//"Comparison function (Compare) to allow the comparison of the String object to another String object or to a “C” type string."
			int				Compare  	(const FLdigitString<L> &) const;
			FLdigitString<L> &  readDigits ();
			FLdigitString<L> &  setFLDstring (const FLdigitString<L> &);
			FLdigitString<L> & operator = (const String &);
			FLdigitString<L> & operator = (const char []);
			char *   makeFLDString (size_t);
			void 			   Display ()const;

			ostream & operator  << 	 (const FLdigitString<L> &);
			ostream & operator << 	(const char []);
			istream &       Read       (istream &);//method used to facilitate the read in '>>' operator.
			istream & operator  >> 	 (const FLdigitString<L> &);
			istream & operator >>	(const char []);
			 operator const char *	 () const;//const here for the ostream Display method because they are not changing anything in the class.


				//------------------Comparison operators #2 (“<”, “<=”, “==”, “!=”, “>=”, “>”)-----------
				    //Items 2 and 3 should have versions that allow both a String object and a “C” type string on the left of the operator


						bool	 operator <  (const FLdigitString<L> &) const;
						bool	 operator <  (const char []) const;
						bool	 operator <= (const FLdigitString<L> &) const;
						bool	 operator <= (const char []) const;
						bool	 operator == (const FLdigitString<L> &) const;
						bool	 operator == (const char []) const;
						bool	 operator != (const FLdigitString<L> &) const;
						bool	 operator != (const char []) const;
						bool     operator >= (const FLdigitString<L> &) const;
						bool     operator >= (const char []) const;
						bool     operator > (const FLdigitString<L> &)const;
						bool     operator > (const char [])const;
private:
			char *pData2;



};
template <size_t L>
FLdigitString<L>::FLdigitString(){
		pData2 = new char [L + 1];
		for (int i = 0; i < L; i++){
				pData2 [i] = '0';
			};
			pData2[L + 1] = '\0'; //sets the EOS mark,
}

//constructor initializes my FLdS from scratch when the variable is called

template <size_t L>
FLdigitString<L>::FLdigitString(const char str []){
	pData2 = new char [L + 1];
	for (int i = 0; i < L; i++){
		 if((!isdigit(str[i])) || (str[i] == '\0')){
			 throw invalid_argument("Flds cnstr str [], cannot take digits for an argument");
		 }else{
			pData2 [i] = str[i];
		 };
	};
		pData2[L + 1] = '\0'; //sets the EOS mark,


};

template<size_t L>
FLdigitString<L>::FLdigitString(const String & str){
	pData2 = new char [L + 1];
	for (int i = 0; i < L; i++){
		 if((!isdigit(str[i])) || (str[i] == '\0')){
			 throw invalid_argument("Flds cnstr str [], cannot take digits for an argument");
		 }else{
			pData2 [i] = str[i];
		 };
	};
		pData2[L + 1] = '\0'; //sets the EOS mark,
}

template <size_t L>
FLdigitString<L>::FLdigitString(const FLdigitString<L> & str){
     pData2 = str.pData2;
};
//destructor
template <size_t L>
FLdigitString<L>::~FLdigitString(){
	delete [] pData2;
};

template <size_t L>
inline void  FLdigitString<L>::Display() const{
			cout << pData2 << endl;
		};

template<size_t L>
inline FLdigitString<L>::operator const char * () const{
	return pData2;
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

template<size_t L>
char * FLdigitString<L>::makeFLDString(size_t length){
		char 	c;
		int		CurrNumChars;
		char *	pTempData2;

		CurrNumChars = 0;
		pData2 		= new char [length + 1]; // +1 to capture the "End of String" mark returned if we don't input any names.

	do{
		c = cin.get();

			if (!isdigit(c)){
				cout << "Invalid Character, string should be [" << length << "] digits. Start over.";
				CurrNumChars = 0;
			}else{
				pData2 [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
			};
		}while(CurrNumChars < length);
			pData2 [length + 1] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.
	return pData2;
}
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

//Comparison function (Compare) to allow the comparison of the String object to another String object or to a “C” type string.
template<size_t L>
inline int FLdigitString<L>::Compare (const char str []) const{

	return strcasecmp(pData2, str); //will return negative number,0, or greater than zero;
};

template<size_t L>
inline int FLdigitString<L>::Compare(const FLdigitString<L> & str) const{

	return strcasecmp(pData2,str);
}

//#2 Comparison
// ----------------------Handles the FLdigitString<L> case -----------------------
template<size_t L>
inline bool FLdigitString<L>::operator < (const FLdigitString<L> & str) const{

	return Compare (str) < 0; //if compare is less than zero, return True.
}

//--------------------------Hanles the c-type FLdigitString<L> case------------
template<size_t L>
inline bool FLdigitString<L>::operator < (const char str []) const{

	return Compare (str) < 0; //if compare is less than zero, return True
}

//---------------------------This inline bool, services both is built by using both operator overload types.
// the pChar identified in the parameter is simply specific so we can identify the difference in the inline function.
template<size_t L>
inline bool operator < (const char pChar [], const FLdigitString<L> & str) {

	return str.Compare (pChar) > 0; //if compare is 0 or 1, return false, if -1 True. The first one is before the second.
}

//------------------------------------------------------------------------------------------
template<size_t L>
inline bool FLdigitString<L>::operator <= (const FLdigitString<L> & str) const{

	return Compare (str) <= 0;
}
template<size_t L>
inline bool FLdigitString<L>::operator <= (const char str []) const{

	return Compare (str) <= 0;
}

template<size_t L>
inline bool operator <= (const FLdigitString<L> & str, const char pChar []){

	return str.Compare (pChar) <= 0;
}

template<size_t L>
inline bool operator <= (const char pChar [], const FLdigitString<L> & str){

	return str.Compare (pChar) <= 0;
}

//------------------------------------------------------------------------------------------
template<size_t L>
inline bool FLdigitString<L>::operator == (const FLdigitString<L> & str) const{

	return Compare (str) == 0;
}
template<size_t L>
inline bool FLdigitString<L>::operator == (const char str []) const{

	return Compare (str) == 0;
}

template<size_t L>
inline bool operator == (const FLdigitString<L> & str, const char pChar []){

	return str.Compare (pChar) == 0;
}

template<size_t L>
inline bool operator == (const char pChar [], const FLdigitString<L> & str){
	return str.Compare (pChar) == 0;
}


//------------------------------------------------------------------------------------------
template<size_t L>
inline bool FLdigitString<L>::operator != (const FLdigitString<L> & str) const{

	return Compare (str) != 0;
}

template<size_t L>
inline bool FLdigitString<L>::operator != (const char str []) const{

	return Compare (str) != 0;
}

template<size_t L>
inline bool operator != (const FLdigitString<L> & str, const char pChar []){

	return str.Compare (pChar) != 0;
}

template<size_t L>
inline bool operator != (const char pChar [], const FLdigitString<L> & str){

	return str.Compare (pChar) != 0;
}

//-----------------------------------------------------------------------------------------
template<size_t L>
inline bool FLdigitString<L>::operator >= (const FLdigitString<L> & str) const{

	return Compare (str) >= 0;
}

template<size_t L>
inline bool FLdigitString<L>::operator >= (const char str []) const{

	return Compare (str) >= 0;
}

template<size_t L>
inline bool operator >= (const FLdigitString<L> & str, const char pChar []){

	return str.Compare (pChar) >= 0;
}

template<size_t L>
inline bool operator >= (const char pChar [], const FLdigitString<L> & str){

	return str.Compare (pChar) >= 0;
}

//------------------------------------------------------------------------------------------

template<size_t L>
inline bool FLdigitString<L>::operator > (const FLdigitString<L> & str) const{

	return Compare (str) > 0;
}

template<size_t L>
inline bool FLdigitString<L>::operator > (const char str []) const{

	return Compare (str) > 0;
}

template<size_t L>
inline bool operator > (const char pChar [], const FLdigitString<L> & str){

	return str.Compare (pChar) > 0;
}

template<size_t L>
inline bool operator > ( const FLdigitString<L> & str, const char pChar []){

	return str.Compare (pChar) > 0;
}

#endif /* SRC_ADDRESS_H_ */
