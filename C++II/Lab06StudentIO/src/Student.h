
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

				bool	 Read	(fstream &);
				void	 displayStudent (const Student &);
				void 	 readGrades (Name &, Array <int, 0, 4> &); //from file
				void 	 showGrades (int []);




	private:
		Name lastName;
		Array <int, 0, 4> grades; //five integer slots
};

Student::Student(){
}

Student::Student (const Student & student){
	lastName = student.lastName;
	grades = student.grades;
};

Student::~Student(){
}

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

void Student::Read (fstream & file){
//void Student::getGrades (Name & name, Array <int, 0, 4> grades){

	char * pNumber;
	int i = 0;
	pNumber = strtok (Line, ","); // strtok dilimeates a C-type String by whatever character you put in the argument, (commas ",");
	while (pNumber != NULL){
		grades [i++] = atoi (pNumber); //atoi changes the ascii code into integer
		pNumber = strtok (NULL, ",");

	}
}

void Student::showGrades (int Grades []){
	int i;

	for (i = 0; i < 5; i++){
		cout << Grades [i] << ", ";
	}
}

void Student::displayStudent (const Student & student){

	char Lines [10] [25] = {"100,100,100,100,100",
							"95,100,80,75,40,",
							"35,38,44,53,75"};


	int Grades [5]; //three sets of 5 grades.

	for (int i = 0; i < 3; i++){
		getGrades (Lines [i], Grades);
		cout << "Grades [" << i << "] are: " << endl;
		showGrades (Grades);

	}

}

#endif /* STUDENT_H_*/
