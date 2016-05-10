/*
 * Import.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: mbd06b
 */

#include "Student.h"
#include "Name.h"
#include "FLdigitString.h"
#include "fileCommands.h"
#include "Address.h"
#include <stdlib.h>

#define STRING_SIZE 80



Student::Student(){
}

Student::Student (const Student & student){
	studentName = student.studentName;
	studentID = student.studentID;
	studentAddress = student.studentAddress;
	studentphoneNum = student.studentphoneNum;
	studentareaCode = student.studentareaCode;
	//grades = student.grades;
	//averageGrade = student.averageGrade;

};

Student::~Student(){
};

int Student::sCompare (const Student & a, const Student & b){
	return (a.getSName().Compare(b.getSName(), option)); //static global variable option is in fileCommands.
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

			file.getline(Line,STRING_SIZE); //moves line forward by 1;
				studentAddress.setZip(Line);

			file.getline(Line,STRING_SIZE); //moves line forward by 1;
				setAreaCode(Line);


			file.getline(Line,STRING_SIZE); //moves line forward by 1;
				setPhoneNum(Line);

			file.getline(Line,STRING_SIZE); //moves line forward by 1;
				setstudentID(Line);

//		getGrades(Line);
			return true;
		};
};


bool	 Student::inputData			(){ //from file


			cout << "First Name>";
			studentName.setFirst(ReadString());

			if(!studentName.get1Name(first).Compare("End")){
				studentName.setFirst("");
				return false;
			}


			cout << "Middle Name>";
			studentName.setMiddle(ReadString());

			cout << "Last Name>";
			studentName.setLast(ReadString());

			cout << "Street Address>";
			studentAddress.setStreet(ReadString());

			cout << "City>";
			studentAddress.setCity(ReadString());

			cout << "State>";
			studentAddress.setState(ReadString());


			cout << "Zip ";
			studentAddress.setZip(readFLDString(5));

			cout << "Area Code ";
			setAreaCode(readFLDString(3));

			cout << "Phone ";
			setPhoneNum(readFLDString(7));

			cout << "StudentID ";
			setstudentID(readFLDString(9));


//		getGrades(Line);
			return true;
};

bool Student::exportObject (fstream & file){ //fr

		file << "--------------------------------------------------------------------------" << '\n';
		file << studentName.get1Name(first) << '\n';
		file << studentName.get1Name(middle)<< '\n';
		file << studentName.get1Name(last) << '\n';
		file << "ID#: " << getSID() << '\n';
		file << "\n";
		file << getAStreet() << '\n';
		file << getACity() << '\n';
		file << getAState() << getAZip() << '\n';
		file << "Area Code: " << getAreaCode() << '\n';
		file << "Phone#: " << getSPhone() << '\n';
		file << "\n";
		file << "\n";
	return true;
}


const Name & Student::getSName()const{
	return studentName.getName();
}

const String & Student::getAStreet()const{
	return studentAddress.getStreet();
}

const String & Student::getACity() const{
	return studentAddress.getCity();
}

const String & Student::getAState() const {
	return studentAddress.getState();
}

const FLdigitString<5> & Student::getAZip()const {
	return studentAddress.getZip();
}


const FLdigitString<9> & Student::getSID ()const{
	return studentID.getFLDstring();
}

const Address & Student::getSAddress()const{
	return studentAddress;
}

const FLdigitString<3> & Student::getAreaCode()const{
	return studentareaCode.getFLDstring();
}

const FLdigitString<7> & Student::getSPhone()const{
	return studentphoneNum.getFLDstring();
}



Student & 	Student::setstudentID (const FLdigitString<9> & str){
	studentID = str;
	return *this;
}

Student & Student::setAreaCode (const FLdigitString<3> & str){
	studentareaCode = str;
	return *this;
}

Student & Student::setPhoneNum (const FLdigitString<7> & str){
	studentphoneNum = str;
	return *this;
}

void Student::displayStudent (){
  cout << "------------------------------------------------------------------------------" << endl;

	cout << studentName;    //display the name
	cout << endl;
	cout << "ID#: " << studentID;
	cout << endl;
	studentAddress.Display();
	cout << endl;
	cout << "Area Code: ";
	studentareaCode.Display();
	cout << "Phone: ";
	studentphoneNum.Display();

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
