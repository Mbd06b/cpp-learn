//============================================================================
// DESCRIPTION : Programming Excercise Five, build a string test for palindromes
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/14/2015
//============================================================================
#include <iostream>
#include <memory.h> //header file for the memset function. is string.h on other compilers.
#include <cstdlib>

using namespace std;


int main()
{
	//NUMBER OF ROWS AND COLUMNS
		const int MaxCols(60); //creating adjustable constants labling them MaxCols/Rows so we could easily resize the array
		const int MaxRows(60);
		int TotalCells;

		TotalCells = MaxCols * MaxRows; //Total Cells in the array. Ex 60 col X 60 rows is 3600 cells.

		//const	time_t 	WaitTime	(2); //sets time a 2 seconds

			bool 	Board [MaxRows + 2] [MaxCols + 2]; // 2D ARRAY  (0-59y, 0-59x)  this works pretty well because bool just True or False
			bool	NextGen [MaxRows + 2] [MaxCols + 2]; // a 2D array, we can copy our first generation into.
			int		Col = 0; //variables for the input below
			int		Row = 0;
			int		Generation;
			char	Check;
			int		NumLiveCells = 0;  // surrounding cells
			//int		Temp; //temporary variable to hold the swap value, to copy to new array.

			//int		Cell;
			char	Check2;



			//Set entire array to 0 values:
			//		we want the whole array "Board" to be set to false before we start input (using the memset controls)
			memset (Board, false, (MaxCols + 2) * (MaxRows +2) * sizeof (bool)); // "sizeof" giving the number of bytes of bool so we don't have to specify
			//the +2 in this memset line, gives us more area set to false than our petri dish uses, so when we start our checks at 1,1 we only need to test 8 cells to avoid test confusion with corners and boarders.
			memset (NextGen, false, (MaxCols +2) * (MaxRows +2) * sizeof (bool)); //setting up our copy array to zeros (to start so we can copy in Gen 1's values.)

			cout << "We have a " << MaxCols << "c X " << MaxRows << "r Cell Petri Dish" << endl;
			cout << "There are: " << TotalCells << "Cells in total" << endl;



			cout << "Enter life in to the cell coordinates (Row & Column) enter 0, 0 to stop: " << endl;

			//To set an initial pattern into our array
			//need a loop here to gather Row & Col Inputs, and save them to our Array

		do
		{	cout << ">";
			cin >> Row >> Col;

			if ((Row >= MaxRows) || (Col >= MaxCols)) //error message for boundaries check, or || indicates if either row or column is greater than Max___ then it's to issue (true) error message and loop back.
						{
						cout << "Error - Row and/or Col outside the boundaries try again" << endl;
						}
			else  if ((Row == 0) && (Col == 0))  	//check for exit, with && AND operator both statements need to be true to issue true. .
						{
						  // if it is zero, leave entry at zero so the if statement drops to the while test. Which exits.
						}

			else
				{
				// If it makes it to this step, COL & Row assign the 2d Array coordinates  here.
				Board [Row] [Col] = true;  // assigns that coordinate to true


				cout << "You seeded Row:" << Row << " Column:"<< Col << endl;
				cout << "Enter another coordinate, enter 0, 0 to stop: " << endl;
				}

		} while (Row != 0 || Col != 0); //needs to always be true unless Col & Row are both 0 OR returns true if any one of the operands is true.
			{ cout << "Here is your petri dish. " << endl;

			//PRINT initial array...
				for (int r = 1; r < MaxRows ; r++)	//for loop prints array one cell at a time.
				{
					for (int c = 1; c < MaxCols; c++) //r (current row), and c (current column) start at 1 so we
					{
						if (Board [r][c] == 0)
							{cout << " ";
							}
						else
							{cout << "*";
							}


					} cout << endl;  //this endline occurs at the end of the column loop, ending the line, and starting the next row(loop) in our array.
				}cout << "Generation:0 ";
				Generation = 0;
			}

			cout << "Are you ready to put your petri dish in the incubator? (Y or N)?" << endl;
			cout << ">"; cin >> Check;
			if (Check == 'N')
			{
				cout << "You said No" << endl;


			}
			else
			{
			cout << "You said Yes" << endl;

				for (int r = 1; r < MaxRows ; r++)	//for loop analyzes array one cell at a time, checks surrounding cells, and prepares the Next Generation to be displayed.
				{
					for (int c = 1; c < MaxCols; c++)
					{
						//Board [r][c];  //rc starting at 1,1, due to the 0 "edges" on our array.
						NumLiveCells = 0; //resets counter to zero

						//determine count of surrounding cells
								if ((Board [r - 1] [c - 1]) > 0) //checks top left corner  and only adds 1 to NumLiveCells counter if that cell is > than 0
								{
								NumLiveCells++;
								}
								if ((Board [r - 1] [c]) > 0) //checks top center
								{
								NumLiveCells++;
								}
								if ((Board [r - 1] [c + 1]) > 0) //checks top right corner
								{
								NumLiveCells++;
								}
								if ((Board [r] [c - 1]) > 0) //checks left
								{
								NumLiveCells++;
								}
								if ((Board [r] [c + 1]) > 0) //checks right
								{
								NumLiveCells++;
								}
								if ((Board [r + 1] [c -1]) > 0) //checks bottom left
								{
								NumLiveCells++;
								}
								if ((Board [r + 1] [c]) > 0) //checks bottom center
								{
								NumLiveCells++;
								}
								if ((Board [r + 1] [c + 1]) > 0) //checks right
								{
								NumLiveCells++;
								}
									 		//Now NumLiveCells should have our correct count a we added one only when a surrounding cell was occupied.
									//If our starting cell was already alive
									if (((Board [r] [c]) > 0) && (NumLiveCells >= 4)) //If our cell was alive at first, and has 4 or more neighbors,
										 {
										NextGen [r] [c] = false;  //zero, death by overcrowding
										 } else
									if (((Board [r] [c]) > 0) && (NumLiveCells <= 1)) //If our cell was alive at first, and has 1 or fewer neighbors,
										{
									 	NextGen [r] [c] = false;  //zero, death by loneliness
										} else
									if (((Board [r] [c]) == false) && (NumLiveCells == 3)) //If our cell was empty, and has exactly 3 occupied neighbors,
										{
										NextGen [r] [c] = true;  //cell in now alive.
										}
										else  						//if none of the above applies, using swap strategy to get our data.
											{
											NextGen [r] [c] = Board [r] [c]; //  the old value becomes the new value (nothing changes)
											}

					}

				}//Board Analysis for loop completes.  Data should now be a part of our NextGen Array
				cout << "Generation:" << ++Generation << endl;

				for (int r = 1; r < MaxRows ; r++)	// Prints our Next Generation Array.
				{
					for (int c = 1; c < MaxCols; c++) //r (current row), and c (current column) start at 1 so we
					{
						if (Board [r][c] == 0)
													{cout << " ";
													}
												else
													{cout << "*";
													}
					} cout << endl;
				}




			cout << "Continue? (Y or N)" << endl;
			cout << ">" << endl;
			cin >> Check;

 if (Check == 'Y' || Check == 'y')
 {

// CIN CHECK IS NOT WORKING

			do
			{
				memcpy (Board, NextGen, (MaxCols +2) * (MaxRows +2) * sizeof (bool)); //copies Nextgen to Board,

						for (int r = 1; r < MaxRows ; r++)	//Prints Board as a check. to make sure it looks like NextGen
						{
							for (int c = 1; c < MaxCols; c++) //r (current row), and c (current column) start at 1 so we
							{

								//Board [r][c];  //rc starting at 1,1, due to the 0 "edges" on our array.
								NumLiveCells = 0; //resets counter to zero

								//determine count of surrounding cells
										if ((Board [r - 1] [c - 1]) > 0) //checks top left corner  and only adds 1 to NumLiveCells counter if that cell is > than 0
										{
										NumLiveCells++;
										}
										if ((Board [r - 1] [c]) > 0) //checks top center
										{
										NumLiveCells++;
										}
										if ((Board [r - 1] [c + 1]) > 0) //checks top right corner
										{
										NumLiveCells++;
										}
										if ((Board [r] [c - 1]) > 0) //checks left
										{
										NumLiveCells++;
										}
										if ((Board [r] [c + 1]) > 0) //checks right
										{
										NumLiveCells++;
										}
										if ((Board [r + 1] [c -1]) > 0) //checks bottom left
										{
										NumLiveCells++;
										}
										if ((Board [r + 1] [c]) > 0) //checks bottom center
										{
										NumLiveCells++;
										}
										if ((Board [r + 1] [c + 1]) > 0) //checks right
										{
										NumLiveCells++;
										}
											 		//Now NumLiveCells should have our correct count a we added one only when a surrounding cell was occupied.
											//If our starting cell was already alive
											if (((Board [r] [c]) > 0) && (NumLiveCells >= 4)) //If our cell was alive at first, and has 4 or more neighbors,
												 {
												NextGen [r] [c] = false;  //zero, death by overcrowding
												 } else
											if (((Board [r] [c]) > 0) && (NumLiveCells <= 1)) //If our cell was alive at first, and has 1 or fewer neighbors,
												{
											 	NextGen [r] [c] = false;  //zero, death by loneliness
												} else
											if (((Board [r] [c]) == false) && (NumLiveCells == 3)) //If our cell was empty, and has exactly 3 occupied neighbors,
												{
												NextGen [r] [c] = true;  //cell in now alive.
												}
												else  						//if none of the above applies, using swap strategy to get our data.
													{
													NextGen [r] [c] = Board [r] [c]; //  the old value becomes the new value (nothing changes)
													}


							}
						}cout << "Generation:" << ++Generation << endl;
						cout << endl;

						for (int r = 1; r < MaxRows ; r++)	// Prints our Next Generation Array.
							{
							for (int c = 1; c < MaxCols; c++) //r (current row), and c (current column) start at 1 so we
								{
								if (Board [r][c] == 0)
															{cout << " ";
															}
														else
															{cout << "*";
															}
								} cout << endl;
							}
						cout << "Continue? (Y or N):";
						std::cin >> Check2;

			}while (Check2 == 'Y' || Check2 == 'y');
 	 	 }

			}	//end of else statement


cout << "Program has ended" << endl;



 return 0;
}


//create an array 60 x 60 visible elements
/*
 *
 * const char LIVE = '*', DEAD = ' ';
	const int ROWS = 7;
	const int COLS = 10;
	char life[ROWS][COLS];
	char life1[ROWS][COLS];
	int ans=0;



	int cell;


		//	memset (Board, false, MaxCols * MaxRows * sizeof (bool)); // "sizeof" giving the number of bytes of bool so we don't have to specify


//Introducton:
			cout << "Welcome to Matthew's Version of the Game of Life" << endl;
			cout << "You will be inputting coordinates on a 60 X 60 array." << endl;
			cout << "Type 'Done' to see your inputs, and display the first generation on your petri-dish." << endl;
			cout << "Enter coordinates (x , y) or enter 'done':" << endl;



			for (Generation = 0; Generation <'t  6; Generation++);
			{
			Col = 0;
			Row = 0;
			cin >> Col;
			cin >> Row;
			cout << "You entered: " << Col << Row << endl;

			}
			cout << "DIE!" << endl;


	int PetriDish [MaxRows] [MaxCols];
	*/




	//Ask the user to set which coordinates in the Array should be marked "alive" "*"

	//Display Generation 0

	//Rules:
		//creating a for loop to iterate over an array.
			//Iterating Over an Array




	// the new generation ie. 1, 2, 3 becomes the current generation and is displayed.

	//after displaying each new genartion, ask the user if they wish to continue to the next genartion or stop at this point.











