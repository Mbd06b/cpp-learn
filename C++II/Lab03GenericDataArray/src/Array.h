/*
 * Array.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mbd06b
 */

#ifndef ARRAY_H_
#define ARRAY_H_


template <class D, int Low , int High >
class Array
{
	public:
		enum Exceptions {IndexOutOfBounds = 1};

//Constructors
						Array       (); //default, a pointer array with no rows or columns.
					 	Array       (const Array <D, Low, High> &); //copy constructor
						~Array      ();//destructor

					D & getAt       (int) throw();
					D   getAt       (int) const throw();
					D & setAt       (int, D) throw();
					D   setAt       (int, D) const throw ();

 Array <D, Low, High> & Copy 	    (const Array<D, Low, High> &);
Array <D, Low, High>  & operator = 	(const Array<D, Low, High> &);
					D & operator [] (int) throw (); //int is the index location.
					D   operator [] (int) const throw ();




			//void bool GetAt(itn i, D & d){
				//d = D [i];
				//	}



	private:
		D gArray [High - Low + 1]; //array of int || string || double || or whatever
								  //this does not need to be a pointer array because we are passing the size in the template arguments
								  //if we didn't know the size, we would use a pointer and allocate memory with new & Delete in the constructors.

};


//Default
template <class D, int Low, int High >
Array <D, Low, High>::Array(){
}

//Destructor
template <class D, int Low, int High >
Array <D, Low, High>::~Array(){
}

//Copy Constructor
template <class D, int Low, int High >
Array <D, Low, High>::Array(const Array<D, Low, High> & toCopy){

	for(int i = 0; i < (High - Low + 1);i++){
		gArray [i] = toCopy.gArray[i];
	}
}

//Copy Method
template <class D, int Low, int High >
Array <D, Low, High> & Array<D,Low,High>::Copy(const Array<D, Low, High> & toCopy){
	for (int i = 0; i < (High - Low + 1); i++){
			gArray[i] = toCopy.gArray[i];
		}
		return *this;
}


//assignment operator
template <class D, int Low, int High >
Array<D,Low,High> & Array <D, Low, High>:: operator = (const Array<D,Low,High> & toCopy){

	for (int i = 0; i < (High - Low + 1); i++){
		gArray[i] = toCopy.gArray[i];
	}
	return *this;

}


// operator overload [] (by & Reference)
template <class D, int Low, int High >
D& Array<D,Low,High>::operator [] (int indexNum) throw (){
		if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
		}
	else
		return gArray[indexNum - Low];

}

// operator overload [] (by value)
template <class D, int Low, int High>
D Array<D,Low,High>::operator [] (int indexNum) const throw (){
	if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
	}
	else
		return gArray[indexNum - Low];
}

//getAt Method (by reference)
template <class D, int Low, int High>
D & Array<D,Low,High>:: getAt (int indexNum) throw (){
	if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
	}
	else
	return gArray[indexNum - Low];

}

//getAt Method (by Value)
template <class D, int Low, int High>
D Array<D,Low,High>::getAt(int indexNum)const throw(){
	if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
	}
	else
	return gArray [indexNum - Low];
}

//setAt Method (by reference)
template <class D, int Low, int High>
D & Array<D,Low,High>::setAt (int indexNum, D data) throw (){
	if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
	}
	else
	return gArray [indexNum - Low] = data;       //returning  (indexnNum- Low) here, corrects for any value changes the boundaries of the array.
												//example: if low were -25, high were 25, then if you requested index value 15, to reach the correct
}												//location in our index, you would take 15, subtract -25, which would land you in index location -10,
												// -10 being index location 15 away from starting.
//setAt Method (by value)
template <class D, int Low, int High>
D  Array<D,Low,High>::setAt (int indexNum, D data)const throw (){
	if((indexNum > High) || (indexNum < Low)){
		throw IndexOutOfBounds;
	}
	else
	return gArray [indexNum - Low] = data;
}

#endif /* ARRAY_H_ */


