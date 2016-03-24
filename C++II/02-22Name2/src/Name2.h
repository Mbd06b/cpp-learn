/*
 * Name2.h
 *
 *  Created on: Feb 17, 2016
 *      Author: mbd06b
 */

#ifndef Name2_H_
#define Name2_H_

#include <iostream>
using Name2space std;

#include <WCS_String.h>  //Bill will provide this class later.

class Name2{

	public:

							Name2			  ();//Default
							Name2			  (const Name2 &);		//Copy
							Name2			  (const WCS_String &, const WCS_String &, const WCS_String &); //Build a Name2

				/*THIS C-TYPE OF CONSTRUCTOR DOES NOT HANDLE INTERNATIONAL CHARACTERS WELL, style writers warn against using this because it be a hassle to change later.
				Name2			  (const char [], const char [], const char []); //Build a Name2 with a C-Type string aka, character arrays.
				*/

							~Name2			  (); //Deconstructor

			int				Compare		 	 (const Name2 &) const;
			Name2 & 			Copy  			 (const Name2 &);
			const WCS_String & GetFirst 	 () const;
			bool  			SetFirst 		 (const WCS_String &); // the bool is to have a reason to validate someone's Name2, so it's not something wierd like the artist formerly known as prince.
			Name2 & 			operator =	 	 (const Name2 &); // returns a reference to a Name2



	private:

	WCS_String First;
	WCS_String Middle;
	WCS_String Last;


};

ostream & operator << (ostream & out, const Name2 & N){

	out << N.GetFirst () << ' ' << N.GetMiddle () << ' ' << N.GetLast ();
	return out;

}


inline Name2 & Name2::Copy (const Name2 & N){

	return operator = (N);
}

inline const WCS_String & Name2::GetFirst () const{

	return First;
}



#endif /* Name2_H_ */
