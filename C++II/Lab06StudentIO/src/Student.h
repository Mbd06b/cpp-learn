
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Name.h"
#include "Array.h"
#include <fstream>




class Student {

	public:
						Student 			();
						Student				(const Student &);
						Student 			(const Name &, const Array<int, 0, 4> &);
						~Student 			();

				void	 read				();

				bool 	 importObject 		(fstream &);

				void	 displayStudent 	();
				Name & 	 getSName		();
				void	 getGrades  		(char []);




	private:
		Name studentName;
		Array <int, 0, 4> grades; //five integer slots

};








#endif /* STUDENT_H_*/
