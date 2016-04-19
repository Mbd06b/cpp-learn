/*
 * BMI.h
 *
 *  Created on: Mar 12, 2016
 *      Author: mbd06b
 */

#ifndef BMI_H_
#define BMI_H_

#include <string>
using namespace std;


template <class D>

class BMI {

public:

	BMI (); //default

	BMI (D <string>, D <int>, D <double>);


	~BMI(); //destructor


	//accessor methods.

	const D 	 getName () const;
	const D	 getHeight()const;
	const D	 getWeight() const;

	//mutator methods - changing the values in our class. no const since we are changing something.
	void setName (D);
	void setHeight (D);
	void setWeight (D);



private:
	D * pData; //a pointer bucket to hold all our values in.
	string   newName; //string
	int		 newHeight; //int
	double	 newWeight; //double

};

template <class D>
inline void BMI<D>::setName (D name){
	newName = name;
};

template <class D>
inline void BMI<D>::setHeight(D height){
	newHeight = height;
};

template <class D>
inline void BMI<D>::setWeight(D weight){
	newWeight = weight;
};



template <class D>
BMI::BMI(){

	newName = "";
	newHeight = 0;
	newWeight = 0.0;

}

template <class D>
BMI::BMI(D <string> name, int height, double weight){

	newName = name;
	newHeight = height;
	newWeight = weight;

}


BMI::~BMI(){}; //destructor.

string BMI::getName() const {
	return newName;
}

int  BMI::getHeight() const {
	return newHeight;
}

double BMI::getWeight() const {
	return newWeight;
}



#endif /* BMI_H_ */
