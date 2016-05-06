/*
 * Import.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: mbd06b
 */

#include "Student.h"
#include "Name.h"
#include "FLdigitString.h"
#include "PhoneNo.h"
#include "Address.h"
#include <stdlib.h>

#define STRING_SIZE 80



Student::Student(){
}

Student::Student (const Student & student){
	studentName = student.studentName;
	studentID = student.studentID;
	studentAddress = student.studentAddress;
	studentPhone = student.studentPhone;
	//grades = student.grades;
	//averageGrade = student.averageGrade;

};

Student::~Student(){
};

int Student::sCompare (const Student & a, const Student & b){

	return (a.getSName().Compare(b.getSName(), option));
}


bool Student::importObject (fstream & file){ //from file


	char Line [STRING_SIZE];

	file.getline(Line,STRING_SIZE); //gets the line (should be name, to start)

		if(strcmp(Line,"EOF") == 0){ //should avoid loading the EOF.
		   (file.close());
		   return false;
		}else{

			studentName.setFirst(Line);//should capture a Name
			file.getline(Line,STRING_SIZE); //moves line forward by 1;
			studentName.setMiddle(Line);
			file.getline(Line,STRING_SIZE); //moves line forward by 1;
			studentName.setLast(Line);
			file.getline(Line,STRING_SIZE); //moves line forward by 1;
			studentAddress.setStreet(Line);
			file.getline(Line,STRING_SIZE); //moves line forward by 1;
			studentAddress.setCity(Line);
			file.getline(Line,STRING_SIZE); //moves line forward by 1;
			studentAddress.setState(Line);
			file.getline(Line,5); //moves line forward by 1;
			studentAddress.setZip(Line);
			file.getline(Line,3); //moves line forward by 1;
			studentPhone.setareaCode(Line);
				if(strlen(Line)!= 3){
					throw invalid_argument("Area code is not 3 digits long");
				};
			file.getline(Line,7); //moves line forward by 1;
			studentPhone.setphoneNum(Line);
			file.getline(Line,9); //moves line forward by 1;
			setstudentID(Line);

//		getGrades(Line);
			return true;
		};

};

const Name & Student::getSName()const{
	return studentName.getName();
}

const FLdigitString<10> & Student::getSID ()const{
	return studentID;
}

const Address & Student::getSAddress()const{
	return studentAddress;
}

const phoneNo & Student::getSPhone ()const{
	return studentPhone;
}

Student & 	Student::setstudentID (const String & str){

	studentID.setFLDstring(str);
	return *this;
}

void Student::displayStudent (){

	studentName.Display();    //display the name
	studentID.Display();
	studentAddress.Display();
	studentPhone.Display();

};

/*
void Student::getGrades (char Line []){

	char * pNumber;
	int i = 0;
	int sum = 0;
	pNumber = strtok (Line, ","); // strtok dilimeates a C-type String by whatever character you put in the argument, (commas ",");

	while (pNumber != NULL){
		grades [i] = atoi (pNumber); //atoi changes the ascii code into
		sum += grades[i];
		i++;
		pNumber = strtok (NULL, ",");
	}
	averageGrade = sum/i;  //calculates grade average when grades are captured.

};
*/
