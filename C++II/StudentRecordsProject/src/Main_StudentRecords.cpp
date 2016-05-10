//============================================================================
// DESCRIPTION : Semester Project Studest Records C++II
// CLASS       : COSC 1437.S02 –
// AUTHOR      : Matthew Dowell
// DATE        : 04/23/2015
//============================================================================


#include "Student.h"
#include "fileCommands.h"
#include <fstream> //fstream is used for file operations.
//http://www.cplusplus.com/reference/fstream/fstream/
#include <iostream>
#include <stdlib.h>

//Make a change


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
	 * 	Zip - 7 digits
  Phone-
	 * 	Area Code - 3 digits
	 * 	Phone Number - 7 digits (no spaces)
	 * 	ID - 9 numeric digits exactly
	 *
	 * 	The user will be allowed to enter records from the keyboard,
	 * 	sort records by either name (last, first, middle) or by ID,
	 * 	save the records to a disk file (name supplied by user),
	 * 	and read the records from a disk file (name again supplied by user).
	 *
*/


int main (){

  option = CompareLast;
  bool continueon = true;
  Array  <Student, 0, 25> studentGArray;
  fstream studentFile;
  string line;

 //to Open a file, by prompting the user.
  fstream studentFile2;
  String fileName;

  string test;



  cout << "Tree Top University STUDENT RECORD.TRON ACTIVATED ... " << endl;
  displayHelp();



do{
cout << "Input Command >";

	switch (getCommand()){
		case CmdImportRecords:
			cout << "Enter File Name >";
			cin >> fileName;
			studentFile.open((const char *) fileName, ios_base::in | ios_base::binary); //binary, i don't want to pick up the \n char conversion

			  if (studentFile.is_open ()){
				 cout << "File is open" << endl;
				 studentGArray.importData(studentFile);
				 cout << studentGArray.importCount() << " Records Imported" << endl;
			  } else{
				  cout << "File failed to open" << endl;
			  };
			  studentFile.clear();
			  studentFile.close();



			break;
		case CmdInputRecords:

			studentGArray.inputData();


			break;
		case CmdSortRecords:
					cout << "How should we sort the students? by [First], [Last], [Middle], or [ID]?" << endl;
					cout << ">";
					option = getCompareOption(); //option is global static variable
					studentGArray.sortStudents();
					 cout << "Students Sorted" << endl;

			break;
		case CmdDisplayRecords:

					cout << endl;
					cout << studentGArray.importCount()<< " Students On Record:"<< endl;
					cout << endl;
				if(studentGArray.importCount() == 0){
					cout << "No Records to Display" << endl;
					  }
				else{
					for (int i = 0; i < (studentGArray.importCount()); i++){
						  studentGArray[i].displayStudent();
						  cout << endl;
						  cout << endl;
						}
					}


			break;
		case CmdExportRecords:
					cout << "Enter File Name >";
					cin >> fileName;
					studentFile2.open((const char *) fileName, ios_base::out);

					if(studentFile2.is_open()){
						cout << fileName << " is open to write." << endl;
					}else{
						cout << "File is not open" << endl;
					};
							studentGArray.exportData(studentFile2);
					cout << studentGArray.importCount() << " Student Records Exported" << endl;
					studentFile2.clear();
					studentFile2.close();

			break;
		case CmdHelp:
			displayHelp();

			break;
		case CmdExit:
			 continueon = false;

			 break;
		case CmdInvalid:
						cout << "Command Invalid try again, or type 'Help'" << endl;
			break;
		default: cout << "Internal error #1, don't abandon all hope, contact customer support" << endl;
				 cout << "Or if this is Bill, just give me an 'A', this was hard enough for less than a page of instruction" << endl;
	}


}while(continueon);

cout << "Program Ended" << endl;
  return 0; 
}

/*
 *
 */
