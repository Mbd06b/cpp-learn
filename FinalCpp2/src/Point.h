
#ifndef POINP_H_
#define POINP_H_

template <class P>
class Point{  // a point to store the origin of a cirle or the starting point of a shape.

	public:
				Point ();
				Point (Point &); //Point Copy constructor
				Point (const P &, const P &); //set (X, Y) constructor
				~Point();

			Point & Copy (const Point &);
			Point & operator = (const Point &);
			P		getX ()const;
			P		getY ()const;
			bool 	setX (const P &);
			bool 	setY (const P &);



	private: //(X,Y( coordinate);
		P  X;
		P  Y;



};

template <class P>
Point<P>::Point (): X(0), Y(0){ //setting our default values  to (0,0)
}

template <class P>
Point<P>::Point (Point & point){
	X = point.X;
	Y = point.Y;
}

template<class P>
Point<P>::~Point (){
}

template<class P>
Point<P> & Point<P>::Copy(const Point & point){
	X = point.X;
	Y = point.Y;
	return *this;
}

template<class P>
Point<P> &  Point<P>::operator = (const Point & point){
	Copy(point);
	return *this;
}

template<class P>
P Point<P>::getX()const {
	return X;
}

template<class P>
P Point<P>::getY()const {
	return Y;
}

template<class P> // I guess with the bool, you could set some "limits" to a cartesian representation, to return false.
bool Point<P>::setY(const P & point){
	Y = point.Y;
	return true;
}

template<class P>
bool Point<P>::setX(const P & point){
	X = point.X;
	return true;
}
#endif POINP_H_ /*_POINP_H_*/
