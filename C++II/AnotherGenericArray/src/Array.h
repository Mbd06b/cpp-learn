/*
 * Array.h
 *
 *  Created on: Feb 10, 2016
 *      Author: mbd06b
 */

#ifndef ARRAY_H_
#define ARRAY_H_


template <class DATA, int Low , int High >
class Array
{
	public:
		enum Exceptions {IndexOutOfBounds = 1};

		DATA & operator [] (int) throw ();
			//void bool GetAt(itn i, DATA & d){
				//d = Data [i];
				//	}

	private:
		DATA D [High - Low + 1];

};

template <class DATA, int Low, int High >
DATA & Array <DATA, Low, High>:: operator [] (int i) throw (){

	throw IndexOutOfBounds;
//	throw 5;

}
#endif /* ARRAY_H_ */
