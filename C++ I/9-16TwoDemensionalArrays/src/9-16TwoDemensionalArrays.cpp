//============================================================================
// Name        : 9-16TwoDemensionalArrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



int main() {

	const	int		MaxCols (4); //puts in 4 columns  (numbered 0, 1, 2, 3)
	const	int		MaxRows	(3); //puts in 3 rown	(numbered 0, 1, 2)


			int		Array1 [MaxRows] [MaxCols];  // two dimensional array
			int  	Array2 [MaxRows] [MaxCols] = {{1, 42, 3, 4},   // This is one way to see your rows and columns in a visual way
												  {5, 6, 7, 8},
												  {9, 10, 11, 12}};
			int		Array3 [MaxRows] [MaxCols] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // this completes the table just going to the next row for the numbers, less visually pleasing
			int		Col;
			int		Row;


	for (Row = 0; Row < MaxRows; Row++)
		//using curly braces here tells it to complete a whole row, then to go to the next row, and execute function
		{
		for (Col = 0; Col < MaxCols; Col++)
			cout << '\t' << Array2 [Row] [Col];
		cout << endl;
		}

		Row = 0;
		for  (Col = 0; Col < (MaxCols * MaxRows); Col++)
			{
			cout << '\t' << Array2 [Row] [Col];
			if (((Col + 1) % 4) == 0)
			{}
			else;
					cout << endl;
			}






	return 0;
}
