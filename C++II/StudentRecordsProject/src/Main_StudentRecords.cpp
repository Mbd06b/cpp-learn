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

/*
When we write to a disk, Bill says that the easiest way to do that is one string at a time.
 * 	Example:
 *
 * Name-
	 * 	First
	 * 	Middle
	 * 	Last
  Address-
	 * 	Street
	 * 	City
	 * 	State
	 * 	Zip
  Phone-
	 * 	Area Code
	 * 	Phone NUmber
	 * 	ID
*/



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
