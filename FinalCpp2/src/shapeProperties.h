/*
 * shapeProperties.h
 *
 *  Created on: May 13, 2016
 *      Author: mbd06b
 */

#ifndef SHAPEPROPERTIES_H_
#define SHAPEPROPERTIES_H_

template <class T>
class ShapeProperties{


	public:
				ShapeProperties ();
				ShapeProperties (const ShapeProperties &); //ShapeProperties Copy constructor
				ShapeProperties (const T &, const T &); //set (area, perimeter) constructor
				~ShapeProperties();

			ShapeProperties & Copy (const ShapeProperties &);
			ShapeProperties & operator = (const ShapeProperties &);
					T		getArea 	 ()const;
					T		getPerimeter ()const;
					bool 	setArea	     (const T &);
					bool 	setPerimeter (const T &);


	private:
		T  area;
		T  perimeter;
};

template <class T>
ShapeProperties<T>::ShapeProperties(): area (0), perimeter (0){
}

template <class T>
ShapeProperties<T>::ShapeProperties(const ShapeProperties & properties){
	area = properties.area;
	perimeter = properties.perimeter;
}

template<class T>
ShapeProperties<T> &  ShapeProperties<T>::operator = (const ShapeProperties & properties){
	Copy(properties);
	return *this;
}

template<class T>
T ShapeProperties<T>::getArea()const {
	return area;
}

template<class T>
T ShapeProperties<T>::getPerimeter()const {
	return perimeter;
}

template<class T> // I guess with the bool, you could set some "limits" to a cartesian representation, to return false.
bool ShapeProperties<T>::setPerimeter(const T & point){
	perimeter = point.perimeter;
	return true;
}

template<class T>
bool ShapeProperties<T>::setArea(const T & point){
	area = point.area;
	return true;
}

#endif /* SHAPEPROPERTIES_H_ */
