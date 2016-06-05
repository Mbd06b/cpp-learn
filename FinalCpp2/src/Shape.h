/*
 * shape.h
 *
 *  Created on: May 13, 2016
 *      Author: mbd06b
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "Point.h"
#include "shapeProperties.h"
#include <iostream>
#include <stdexcept>
using namespace std;


template <class P, class T>
class Shape{

public:					Shape		();
						Shape		(const Shape &);
				virtual	~Shape		(); //virtual, b/c this will act as a base class

			Shape & 	Copy		(const Shape &);
			Shape & operator =		(const Shape &);

			const Point<int> getOrigin () const;
			bool			 setOrigin (const Shape &);


				const T getProperties ()const;

					//pure virtual, this will force every child shape (square,triangle, cirle) to have defined methods
			virtual bool setArea (double) const = 0;
			virtual bool setPerimeter (double)const  = 0;


private:
			Point<P>  origin; // gives us the (X,Y) origin of a shape.
			ShapeProperties<T> properties;

};


template<class P, class T>
Shape<P,T>::Shape(){
	//default origin is (0,0) as defined in Point<P>
}

template<class P, class T>
Shape<P,T>::Shape(const Shape & shape){
	origin = shape.origin;
	properties = shape.properties;
}

template<class P, class T>
Shape<P,T>::~Shape(){
}

template<class P, class T>
Shape & Shape<P,T>::Copy(const Shape & shape){
	origin = shape.origin;
	properties = shape.properties;
	return *this;

}

template<class P, class T>
Shape & Shape<P,T>::operator = (const Shape & shape){
	Copy(shape);
	return *this;
}


template<class P, class T>
const T  Shape<P,T>::getProperties () const{
	return properties;
}


#endif /* SHAPE_H_ */
