/*
 * MyClass.h
 *
 *  Created on: Mar 21, 2016
 *      Author: mbd06b
 */

#ifndef MYCLASS_H_
#define MYCLASS_H_

class Test1
{
	public:
					    Test1 () {A = -5;}

					int	GetB  () const {return B;} //convinent subscript style
			static  int GetB2 () {return B;} //static methods cannot use non-static members   - this cannot return int A.

	private:
				   int A;
			static int B; //one copy of this is shared among all the instances of this class.

};


class Test1child : public Test1{ //any instance of Test1a shares the same memeber B
							//that is being shared by instances of Test1;


};





#endif /* MYCLASS_H_ */
