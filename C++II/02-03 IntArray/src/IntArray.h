/*
 * IntArray.h
 *
 *  Created on: Feb 3, 2016
 *      Author: mbd06b
 */

#ifndef INTARRAY_H_
#define INTARRAY_H_


class IntArray{

	public:
		//	IntArray		 (); //default constructor
			IntArray		 (int = 0, int = 0); //default constructor with default parameter given
			IntArray		 (const IntArray &); //copy constructor
			~IntArray		 (); //destructor


			IntArray & Copy (const IntArray &);
			int & At   (int);
			int  At   (int)const;

			IntArray & operator = (const IntArray &); //operator assignment to help us direct our pointers without blowing up our program.
			int &	   operator [] (int);
			int  	   operator [] (int) const;


	private:
		int * pData;
		int   Low; //lowest point on our index.
		int	  High; //highest point on our index.
		//total number of slots = High-Low + 1.


};

inline IntArray & IntArray::Copy (const IntArray & IA){
	return operator = (IA);
	//return *this = IA;  <-- This works just preference.
}


#endif /* INTARRAY_H_ */
