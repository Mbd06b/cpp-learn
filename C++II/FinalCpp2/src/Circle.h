/*
 * Circle.h
 *
 *  Created on: May 13, 2016
 *      Author: mbd06b
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_




#include "Shape.h"
#include <iostream>
#include <cmath> //for power of;
using namespace std;

template <class P, class T>
class Circle : public Shape <P, T>{

			public:			Circle();
							Circle(const Circle &);
				virtual		~Circle();

				const double pi = 3.1415926535897;

				Circle & 	Copy  (const Circle &);
				Circle & operator = (const Circle &);

				const Circle &	getRadius () const;
				bool 			setRadius (const T &);


		virtual		void 	Draw() const;
		virtual		double  getArea()const;
		virtual 	double 	getPerimeter() const;



			private:

				P  radius;

};

template<class P, class T>
Circle<T,P>::Circle(): radius(0){
	//default circle radius of 0;)
}

template<class P, class T>
Circle<T,P>::Circle(const Circle & C): Shape(C), radius(C.radius){
}

template<class P, class T>
Circle<T,P>::~Circle(){
};

template<class P, class T>
const Circle & Circle<T,P>::getRadius() const{
	return radius;
}

template<class P, class T>
bool Circle<T,P>::setRadius (const T & rvalue){
	if(rvalue > 0){
		radius = rvalue;
			return true;
			return true;
		}else{
			throw invalid_argument("radius must be greater than zero");
		return false;
		}
}


template<class P, class T>
Circle & Circle<T,P>::Copy(const Circle & circle){
	Shape<T>::Copy(circle); //copy's the circle's shape elements.
	radius = circle.radius;
	return *this;
}

template<class P, class T>
Circle & Circle<T,P>::operator = (const Circle & circle){
	Copy(circle);
	return *this;
}

template<class P, class T>
double Circle<T,P>::getArea()const{
	double area;
	area = pi * pow(radius, 2); //pi(r)^2;
	return area;
}

template<class P, class T>
double Circle<T,P>::getPerimeter()const{
	double perimeter;
	perimeter = 2*pi*radius;
	return perimeter;
}

#endif /* CIRCLE_H_ */
