
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Name.h"
#include "Array.h"
//#include "FLString.h"
#include "PhoneNo.h"
#include "Address.h"
#include <fstream>





class Student {

	public:
						Student 			();
						Student				(const Student &);
						Student 			(const Name &, const Array <int, 0, 4> &);
						~Student 			();

				void	 read				();

				bool 	 importObject 		(fstream &);
				int		 sCompare 			(const Student &, const Student &);

				void	 displayStudent 	();
		const	Name & 	 getSName			()const;
				void	 getGrades  		(char []);




	private:
		Name studentName;
		FLdigitString <7>  studentID;
	//  Address studentAddress;
	//  PhoneNo studentPhone;   NEEDS THE FLSTRING
		Array <int, 0, 4> grades; //five integer slots
		int averageGrade;

};


#endif /* STUDENT_H_*/
