
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
			FLdigitString<L> &  readDigits ();
			FLdigitString<L> &  setFLDstring (const FLdigitString<L> &);
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
FLdigitString<L> & FLdigitString<L>::readDigits(){
	char	c;
	bool	IsNegative;
	FLdigitString<L>	Num;
	int		NumCharsEntered; //we need to keep track of the number of characters typed

	IsNegative = false;
	Num = 0;
	NumCharsEntered = 0;

	while ((c = cin.get()) != '\n'){ // \r is the enter key, we will read until you hit "ENTER"
							//_getch gets a character AS SOON AS YOU TYPE IT,
							// and it does show it on the screen (good for typing in passwords)
		switch (c){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
						NumCharsEntered++;
						Num = (Num * 10) + (c - '0');  //'0' ASCII code for the character 48
						break;
			case '\b':
						if (NumCharsEntered > 0){
							Num = Num / 10; // taking 1234 divided by 10 is a whole number 123 because we are not dealing with fractional numbers
							NumCharsEntered--;
							if (NumCharsEntered == 0)
								IsNegative = false;
						}
						break;
					default:
						break;
			}
		}
	return Num;	// send the number back to where we came from
}
/*


*/
#endif /* SRC_ADDRESS_H_ */
