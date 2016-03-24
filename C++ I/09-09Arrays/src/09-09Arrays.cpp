//============================================================================
// Name        : 09-09Arrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <memory.h> // needed if we want to use the "memset" code below....

int main()

{


	const	int NumGrades (10);  // creates a named constant (NumGrades), everywhere the compiler sees it
								// it will replace with 10
	int		Grades [NumGrades];  // creates a variable to hold a collection of integers
						  // the number inside the [ ] has to be a constant
	int		Grades2 [NumGrades] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //initial values set using curly braces{ }
	int		Grades3 [NumGrades] = {1, 2, 3, 4, 5, 6, 7, 8};// last to slots of the array {9, 10} will have whatever is leftover in the program memory
	//int		Grades4 [NumGrades] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //trying to initialize too many "slots" results in an error.
	int		Grades5 [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // if you don't provide a number of slots in the brackets this ignores the constant "NumGrades(10)" and creates however many slots you use.
	int		Grades6 [100];  // this would be arduous to input upto 100,  using the memset code allows us to set all the values to zero.
	int		i;
	int		Avg;
	int		Sum;

	cout << "Grades2 prints: " << Grades2 [NumGrades] << endl;
	cout << "\n" << endl;
	cout << "Grades3 prints: " << Grades3 [NumGrades] << endl;
	cout << "\n" << endl;
	cout << "Grades 5 prints: " << Grades5 [NumGrades] << endl;
	cout << "\n" << endl;


	memset (Grades6, 0, 100 * sizeof (int)); //will put an initial value of 0
											// give array name, initial value (zero), and the size of the array in bytes

	Grades [4] = 85;	// place a value into slot number 4 inside Grades
	i = 4;				// when using the array, you can use a variable to say what you want
	cout << "Value at position " << i << " is " << Grades [i] << endl;

//	for (i = 0; i < NumGrades; i++)  //the numbering of slots starts at 0 and goes up to size -1
//		Grades [i] = i * 3;
//	for (i = 0; i < NumGrades; i++)NumGrades
//		cout << "Grades [" << i << "] holds " << Grades [i] << endl;

//	for (i = 0; i < NumGrades; i++)  //the numbering of slots starts at 0 and goes up to size -1
//			Grades [i] = i * 3;
//	for (i = 0; i < 12; i++)     // !! THE COMPILER DOES NOT CHECK IF YOU GO OUTSIDE THE BOUNDS OF THE ARRAY!!
//			cout << "Grades [" << i << "] holds " << Grades [i] << endl;

	for (i = 0; i < NumGrades; i++)  //the numbering of slots starts at 0 and goes up to size -1
				Grades [i] = i * 3;
		for (i = 0; i < NumGrades; i++)     // !! THE COMPILER DOES NOT CHECK IF YOU GO OUTSIDE THE BOUNDS OF THE ARRAY!!
				cout << "Grades [" << i << "] holds " << Grades [i] << endl;

		Sum = 0;			//make sure you define your SUM = 0, or you will get an existing variable from your IDE.
		for (int j = 0; j < NumGrades; j++)  // j is now a variable that exists only inside this 'for' loop
			Sum += Grades [j];  // we need to define the variable 'j' as 0, because if we didn't define it, it could be whatever was stored previously for 'j"
		Avg = Sum / NumGrades;
		cout << "Average = " << Avg << endl;







	return 0;
}
