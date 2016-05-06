
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Name.h"
#include "Array.h"
#include "FLdigitString.h"
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

		Student & 	 setstudentID 		(const String &);

				void	 			displayStudent 	();
		const	Name & 				getSName		()const;
		const   FLdigitString<9> &  getSID 			()const;
		const   Address & 			getSAddress 	()const;
		const	phoneNo &			getSPhone		()const;

				//void	 getGrades  		(char []);




	private:
		Name studentName;
		FLdigitString <9>  studentID;
		Address studentAddress;
		phoneNo studentPhone;
	/*
		Array <int, 0, 4> grades; //five integer slots
		int averageGrade;
	*/
};


#endif /* STUDENT_H_*/
