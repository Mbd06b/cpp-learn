/*
 * Name.h
 *
 *  Created on: Feb 17, 2016
 *      Author: mbd06b
 */

#ifndef Name_H_
#define Name_H_

#include <iostream>
using Namespace std;

#include <WCS_String.h>  //Bill will provide this class later.

class Name{

	public:

							Name			  ();//Default
							Name			  (const Name &);		//Copy
							Name			  (const WCS_String &, const WCS_String &, const WCS_String &); //Build a Name

				/*THIS C-TYPE OF CONSTRUCTOR DOES NOT HANDLE INTERNATIONAL CHARACTERS WELL, style writers warn against using this because it be a hassle to change later.
				Name			  (const char [], const char [], const char []); //Build a Name with a C-Type string aka, character arrays.
				*/

							~Name			  (); //Deconstructor

			int				Compare		 	 (const Name &) const;
			Name & 			Copy  			 (const Name &);
			const WCS_String & GetFirst 	 () const;
			bool  			SetFirst 		 (const WCS_String &); // the bool is to have a reason to validate someone's Name, so it's not something wierd like the artist formerly known as prince.
			Name & 			operator =	 	 (const Name &); // returns a reference to a Name



	private:

	WCS_String First;
	WCS_String Middle;
	WCS_String Last;


};

ostream & operator << (ostream & out, const Name & N){

	out << N.GetFirst () << ' ' << N.GetMiddle () << ' ' << N.GetLast ();
	return out;

}


inline Name & Name::Copy (const Name & N){

	return operator = (N);
}

inline const WCS_String & Name::GetFirst () const{

	return First;
}



#endif /* Name_H_ */
