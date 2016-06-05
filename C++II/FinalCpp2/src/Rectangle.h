/*
 * Rectangle.h
 *
 *  Created on: May 13, 2016
 *      Author: mbd06b
 */



#ifndef RECTANGLE_H_
#define RECTANGLE_H_



#include "Shape.h"

template<class P, class X, class Y>
class Rectangle : public Shape<P, P>{

	public:			Rectangle ();
					Rectangle (const Rectangle &);
					Rectangle (const X &, const Y &);
					~Rectangle();

				Rectangle & Copy (const Rectangle &);
				Rectangle & operator = (const Rectangle &);

				const X & getSideX ()const;
				const Y & getSideY ()const;
				bool    setSideX (const X &);
				bool 	setSideY (const Y &);

				bool   setArea ();
				bool   setPerimeter ();


				int  getArea (); //have to have b/c shape is pure virtual.


	private:
			X sideX; //define one side, define two sides.
			Y sideY; //


};

template<class P, class X, class Y>
Rectangle<P,X,Y>::Rectangle(): sideX (0), sideY(0){ //define an element in the class.
	 //origin at 0,0 due to base shape >> base origin 0,0;
}

template<class P, class X, class Y>
Rectangle<P,X,Y>::Rectangle(const Rectangle & rect): Shape (rect), sideX (rect), sideY (rect){
}

template<class P, class X, class Y>
Rectangle<P,X,Y>::Rectangle(const X & rectX, const Y & rectY){
	sideX = rectX;
	sideY = rectY;
}

template<class P, class X, class Y>
Rectangle<P,X,Y>::~Rectangle(){

};

template<class P, class X, class Y>
Rectangle & Rectangle<P,X,Y>::Copy(const Rectangle & rect){
	Shape<P,P>::Copy(rect); //copies the elements of the parent class.
	sideX = rect.sideX;
	sideY = rect.sideY;
	return *this;
}

template<class P, class X, class Y>
Rectangle & Rectangle<P,X,Y>::operator = (const Rectangle & rect){
	Copy(rect);
	return *this;
}

template<class P, class X, class Y>
const X & Rectangle<P,X,Y>::getSideX () const{
	return sideX;
}
template<class P, class X, class Y>
const Y & Rectangle<P,X,Y>::getSideY () const{
	return sideY;
}

template<class P, class X, class Y>
bool Rectangle<P,X,Y>::setSideX (const X & side){
	if(side < 0){
			sideX = side;
			return true;
		}else{
			throw invalid_argument("rectangle side must be greater than 0");
		return false;
		}
}

template<class P, class X, class Y>
bool Rectangle<P,X,Y>::setSideY (const Y & side){
	if(side < 0){
		sideY = side;
			return true;
			return true;
		}else{
			throw invalid_argument("rectangle side must be greater than 0");
		return false;
		}
}

template<class P, class X, class Y>
bool Rectangle<P,X,Y>::setArea(const Y & side){
}

template<class P, class X, class Y>
bool Rectangle<P,X,Y>::setPerimeter (const Y & side){


#endif /* RECTANGLE_H_ */
