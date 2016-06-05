
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Name.h"
#include "Array.h"
#include "FLdigitString.h"
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
				bool	 inputData			();
				bool 	 exportObject		(fstream &);
				int		 sCompare 			(const Student &, const Student &);

		Student & 	 setstudentID 		(const FLdigitString<9> &);
		Student & 	 setAreaCode 		(const FLdigitString<3> &);
		Student & 	 setPhoneNum 		(const FLdigitString<7> &);

				void	 			displayStudent 	();
		const	Name & 				getSName		()const;
		const 	String & 			getAStreet		()const;
		const	String & 			getACity		()const;
		const 	String & 			getAState		()const;
		const 	FLdigitString<5> & 	getAZip			()const;
		const   FLdigitString<9> &  getSID 			()const;
		const   Address & 			getSAddress 	()const;
		const   FLdigitString<3> &  getAreaCode		()const;
		const	FLdigitString<7> &	getSPhone		()const;


				//void	 getGrades  		(char []);




	private:
		Name studentName;
		FLdigitString <9>  studentID;
		Address studentAddress;
		FLdigitString<3> studentareaCode;
		FLdigitString<7> studentphoneNum;
	/*
		Array <int, 0, 4> grades; //five integer slots
		int averageGrade;
	*/
};


#endif /* STUDENT_H_*/
