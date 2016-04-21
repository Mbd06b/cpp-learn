
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Name.h"
#include "Array.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>



class Student {

	public:
						Student ();
						Student (const Student &);
						Student (const Name &, const Array<int, 0, 4> &);
						~Student ();

				void	 read ();

				bool 	 importObject (fstream &);

				void	 displayStudent ();
				void	 getGrades  	(char []);




	private:
		Name studentName;
		Array <int, 0, 4> grades; //five integer slots

};





/*
inline bool  Student::Read (fstream & in){

	char Line [81];

	in.getline(Line,81); //getline refrences the entire line, upto 81 chars.
	lastName = Line;
	cout << "Line: " << i <<;

	if(strcmp(Line, "EOF") != 0){
		//Get grades
		return true;
	}else{
		return false;
	}
}
*/






#endif /* STUDENT_H_*/
