/*
 * Array.h
 *
 *  Created on: Feb 29, 2016
 *      Author: mbd06b
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <fstream>
#include "Student.h"		//to sort by Student Name
#include "FLdigitString.h" //to sort by IDNumber


template <class D, int Low , int High >
class Array
{
	public:
		enum Exceptions {IndexOutOfBounds = 1};
		enum SortOption {InvalidSort = -1,
						byLast,
						byFirst,
						byMiddle,
						numSortOptions};

//Constructors
						Array       (); //default, a pointer array with no rows or columns.
					 	Array       (const Array <D, Low, High> &); //copy constructor
						~Array      ();//destructor

					D & getAt       (int) throw();
					D   getAt       (int) const throw();
				Array & getArray	(Array <D, Low, High> &);
					D & setAt       (int, D) throw();
					D   setAt       (int, D) const throw ();

 Array <D, Low, High> & Copy 	    (const Array<D, Low, High> &);
 	 	 		   void sortStudents   ();
  	  	  	  	   void importData  (fstream &); //for importing files into Array
  	  	  	  	   void inputData 	();//for typing data into array;
  	  	  	  	   void exportData  (fstream &);


  	  	  	  	   int importCount () const; //see import counter
  	  	  	 const int & getImportCount () const;
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
		size_t importCounter;

};

//Default
template <class D, int Low, int High >
Array <D, Low, High>::Array(){
	importCounter = 0;
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
	importCounter = toCopy.importCounter;
}

template <class D, int Low, int High>
void Array<D,Low,High>::sortStudents (){ //int a is our Array size (NumElements in SortLab)

if(importCounter){ //if Zero, there are no objects to sort
	int	NumElements = importCounter; //
	 bool	Sorted;
	 D Temp; // a temporary place to store our object as we sort.
	NumElements--; //NumElements -- we are subtracting 1 from our array, because we don't want the EOF beyond our array

	if(option == 4){ //option 4 is we are sorting by IDNumber instead of names
				do{
							Sorted = true;
							for (int i = 0; i < NumElements; i++){
								if ((gArray[i].getSID()) > (gArray[i + 1].getSID())){  //what do I do if The element above is higher than the element below?

									Temp = gArray [i];   //save the existing value
									gArray [i] = gArray [i + 1]; //swop the value
									gArray [i + 1] = Temp;  // assign the new value
									Sorted = false;
								}

							}
						  }while (!Sorted);//END DO LOOP  ! Is NOT, so !Sorted is Not-Sorted.

	}else{   //Name Sort Options

				 do{
					Sorted = true;
					for (int i = 0; i < NumElements; i++){
						if ((gArray[i].getSName()) > (gArray[i + 1].getSName())){  //what do I do if The element above is higher than the element below?

							Temp = gArray [i];   //save the existing value
							gArray [i] = gArray [i + 1]; //swop the value
							gArray [i + 1] = Temp;  // assign the new value
							Sorted = false;
						}

					}
				  }while (!Sorted);//END DO LOOP  ! Is NOT, so !Sorted is Not-Sorted.
	};

}else
	{cout << "Nothing to Sort" << endl;};
}


template <class D, int Low, int High>
void Array<D, Low,High>::importData (fstream & file){
	bool result;
	int i = 0;
	do{
		result = gArray[i++].importObject(file);
	}while(result);
	importCounter = --i; //result is false (eof bit hit) subtract 1 to get internal array count.
};

template <class D, int Low, int High>
void Array<D, Low,High>::inputData (){
	bool result;
	int i = 0;
	do{
		result = gArray[i++].inputData();
	}while(result);
	importCounter = --i; //result is false (eof bit hit) subtract 1 to get internal array count.
};

template <class D, int Low, int High>
int  Array<D,Low,High>::importCount ()const{
	return importCounter; //num objects loaded by importData
}

template <class D, int Low, int High>
void Array<D, Low, High>::exportData(fstream & file){
	 for(int i = 0; i < importCounter; i++){
		 gArray[i].exportObject(file);
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


template <class D, int Low, int High>
const int & Array<D,Low,High>::getImportCount() const{
	return importCounter;
}

#endif /* ARRAY_H_ */


