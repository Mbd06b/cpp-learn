/*
 * Import.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: mbd06b
 */

#include "Student.h"
#include <stdlib.h>




Student::Student(){
}

Student::Student (const Student & student){
	studentName = student.studentName;
	grades = student.grades;

};

Student::~Student(){
};


bool Student::importObject (fstream & file){ //from file


	char Line [80];
		//file.getline(line,80); //gets the line (should be name, to start)
		file.getline(Line,80);



	if(strcmp(Line,"EOF") == 0){ //should avoid loading the EOF.
		   (file.close());
		   return false;
		}else{
<<<<<<< HEAD
		studentName.setFirst(Line);//should capture a Name
		file.getline(Line,80);
=======
		file.getline(Line,80); //moves line forward by 1; 
>>>>>>> branch 'master' of https://MatthewBDowell@bitbucket.org/MatthewBDowell/mbd06b-c-learn.git
		getGrades(Line);
			return true;
		};

};

Name & Student::getSName(){
	return studentName.getName();
}

void Student::displayStudent (){

	studentName.Display();    //display the name
	for(int i = 0; i < 5; i++){ //and the grades
	cout << grades [i] << ", ";
	};
};


void Student::getGrades (char Line []){

	char * pNumber;
	int i = 0;
	pNumber = strtok (Line, ","); // strtok dilimeates a C-type String by whatever character you put in the argument, (commas ",");

	while (pNumber != NULL){
		grades [i++] = atoi (pNumber); //atoi changes the ascii code into
		pNumber = strtok (NULL, ",");
	}

};
