
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

Array <Student, 0, 24> &  importData (fstream &);
				void	 displayStudent (const Student &);
				void	 getGrades  	(char [], Array<int, 0, 4>);




	private:
		Name studentName;
		Array <int, 0, 4> grades; //five integer slots

};


inline Array <Student, 0, 24> & Student::importData (fstream & file){ //from file

	 //we need a place to capture our data from file
	int linecounter = 1; //line counter
	int studentcounter = 0; //starting odd, to delinate names and grades by even and odd lines.
	char Line [80];

	if(file.good()){ //if file is open properly, continue


		//file.getline(line,80); //gets the line (should be name, to start)

		do{
			file.getline(Line,80);

			if(linecounter % 2 == 0){ //if line is even, load grades
					getGrades(Line, this[studentcounter].grades);
					studentcounter++; //and go to next student.
			}else{
			this[studentcounter].studentName.setFirst(Line); //should capture a Name
			};

			linecounter++;
		}while(!file.eof());
		file.clear();
		file.close();

	}else{
		cout << "file did not open in importData method" << endl;
	};


	return *this;
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






#endif /* STUDENT_H_*/
