/*
 * Import.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: mbd06b
 */

#include "Student.h"




Student::Student(){
}

Student::Student (const Student & student){
	studentName = student.studentName;
	grades = student.grades;
};

Student::~Student(){
}








void Student::displayStudent (const Student & student){

	student.studentName.Display();
	cout << endl;
	for (int i = 0; i < 5; i++){
		cout << grades [i] << ", ";
	};
}


void Student::getGrades (char Line [], Array <int, 0, 4> Grades){

	char * pNumber;
	int i = 0;
	pNumber = strtok (Line, ","); // strtok dilimeates a C-type String by whatever character you put in the argument, (commas ",");
	while (pNumber != NULL){
		Grades [i++] = atoi (pNumber); //atoi changes the ascii code into
		pNumber = strtok (NULL, ",");

	}
}
