/*
 * GenericArray.h
 *
 *  Created on: Feb 8, 2016
 *      Author: mbd06b
 */

#ifndef GENERICARRAY_H_
#define GENERICARRAY_H_

#include <assert.h>



template <class DATA = int> //Style thing here is putting template arguments in all-caps.
					  //TEMPLATE METHODS have to be written in a header file.
					  //TEMPLATE only applies to the class definition DATA
	class Array{

		public:
			//	Array		 (); //default constructor
								Array		(int = 0, int = 0); //default constructor with default parameter given
								Array		 (const Array <DATA> &); //copy constructor
								~Array		 (); //destructor


				Array <DATA> & Copy 	      (const Array<DATA> &);
				void 		   Resize		  (int , int);
				DATA & 		   At   	      (int);
				DATA  		   At  	 	  	  (int)const;

				Array <DATA> & operator = 	  (const Array <DATA> &); //operator assignment to help us direct our pointers without blowing up our program.
				DATA &	   	   operator []	  (int);
				DATA  	       operator [] 	  (int) const;
			//	void			Func 		  ();


		private:
			DATA * pData;  //because we don't know what data type DATA really is,  we cannot guarentee that it will be initialized correctly.
			int   Low; //lowest point on our index.
			int	  High; //highest point on our index.
			//total number of slots = High-Low + 1.


	};


template <class DATA>
Array <DATA>::Array (int L, int H){ //default


	assert (H >= L);  //if the parameter is true, continue on if false terminate the program saying where the error occurred
	Low = L;
	High = H;
	pData = new DATA [High - Low +1];
	for (int i = 0; i < (High - Low + 1); i++){
		pData [i] = 0;
	}


};

template <class DATA>  //copy constructor we cannot use the easy memcpy with DATA, which could screw up string pointers. Because we would be copying addresses instead of content.
Array <DATA>::Array (const Array <DATA> & IA){

	Low = IA.Low;
	High = IA.High;
	pData = new DATA [High - Low +1];
	for (int i = 0; i < (High - Low + 1); i++){
		pData [i] = IA.pData[i];

	}
	//memcpy (pData, IA.pData, (High - Low + 1) * sizeof (int));

};

template <class DATA>
Array <DATA>::~Array(){
	delete [] pData;

}

template <class DATA> //still can't use memcpy here due to DATA, use for loop instead.
Array <DATA> & Array <DATA>::operator = (const Array <DATA> & IA){

	if ((High - Low + 1) < (IA.High - IA.Low + 1)){
			delete [] pData;
			pData = new DATA [IA.High - IA.Low +1];
	}
	else;

	Low = IA.Low;
	High = IA.High;

	for (int i = 0; i < (High - Low + 1); i++){
			pData [i] = IA.pData[i];

		}
//	memcpy (pData, IA.pData, (High - Low + 1) * sizeof (int));
	return *this;

}

template <class DATA>
DATA & Array<DATA>::operator [] (int i){

	assert((i >= Low) && (i <= High));
	return pData [i - Low]; // our array to the compiler looks like 0123456789 10, slots,  the user sees -5, -4, -3, -2 .... 9, 10.

}

template <class DATA>
DATA Array<DATA>::operator [] (int i) const{

	assert((i >= Low) && (i <= High));
	return pData [i - Low]; // our array to the compiler looks like 0123456789 10, slots,  the user sees -5, -4, -3, -2 .... 9, 10.

}

template <class DATA>
	void Array <DATA> ::Resize(int L, int H){

		assert (H >= L);

		int i;
		int NumElements;
		DATA * pTemp;

		pTemp = new DATA [H - L + 1];
		NumElements = ((H - L + 1) < (High - Low + 1)) ? (H - L + 1) : (High - Low + 1); //if (If True "Newer Smaller than Older") ? (Do This)(If Not Do this):

		for (i = 0; i < NumElements; i++){
			pTemp [i] = pData [i];
			High 	  = H;
			Low 	  = L;
			delete [] pData;
			pData = pTemp;
		}

};


template <class DATA>
	inline Array <DATA> & Array<DATA>::Copy (const Array <DATA> & IA){
		return operator = (IA);
		//return *this = IA;  <-- This works just preference.
	}


//INVALID METHOD THAT WON'T COMPILE on VISUAL STUDIO UNTIL CALLED.
/*
template <class DATA>
	void Array <DATA>::Func (){
  chang chang change, changg of fools. Doobe dobbe dobe;
  return 999; ;

}
*/



#endif /* GENERICARRAY_H_ */
