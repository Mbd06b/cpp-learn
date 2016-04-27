//============================================================================
// DESCRIPTION : Lab 06  C++II ReadIn File, Sort, and Display
// CLASS       : COSC 1437.S02 – Lab 06
// AUTHOR      : Matthew Dowell
// DATE        : 04/23/2015
//============================================================================

#include "Student.h"
#include <fstream> //fstream is used for file operations.
//http://www.cplusplus.com/reference/fstream/fstream/
#include <iostream>


using namespace std; 

int main (){

  Array  <Student, 0, 25> studentGArray;
  fstream studentFile;
  string line;

  

  studentFile.open("Lab06data.txt", ios_base::in);

  if (studentFile.is_open ()){
	  cout << "File is open" << endl;

	 studentGArray.importData(studentFile);


  } else{
	  cout << "File is not open" << endl;
  };
  

  for (int i = 0; i < (studentGArray.importCount()); i++){
	  studentGArray[i].displayStudent();
	  cout << endl;
	  cout << endl;
  }

  cout << endl;
  cout << "Mystery Bug Here" << endl;
  cout << "Sort Students function believes it is successfully sorting students" << endl;
  cout << "It goes through and checks the first name of each student using compare functions in the Name class" << endl;
  cout << "While using strcasecmp when comparing Peter & George,in this particular instance strcasecmp(Peter,George)"<< endl;
  cout << "Incorrectly returns a negative integer,-127. Which testing stand alone with char* strcasecmp should result in a positive integer" << endl;
  cout << "The incorrect integer, then returns an incorrect bool and the SortFunction is thereby fooled, I believe the syntax however is sound" << endl;
  cout << "I'm Soliciting feedback on this bug." << endl;
  cout << endl;


  studentGArray.sortStudents();



  cout << "Students Sorted: " << endl;

  for (int i = 0; i < (studentGArray.importCount()); i++){
	  studentGArray[i].displayStudent();
	  cout << endl;
	  cout << endl;
  }





  cout << "Made it to the end" << endl;

 // while(studentGArray[i++].Read(studentFile));

  
  return 0; 
}

/*
 *
 */
