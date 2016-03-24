//============================================================================
// Name        : GoLifeNotes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//#include <conio.h> // needed for _kbhit use below, used with WIN/DOS,
#include <curses.h>// _kbhit on UNIX/Linux use curses  (will need to add ncurses library to our compiler)
#include <memory.h> //needed to use memset function below.
#include <stdlib.h> //needed to use system "cls"(WIN or DOS), in linux or unix it's "clear"
#include <time.h> // needed to get the current time


int main()
{
	const	int		MaxCols(10);  //creating variables so we can cascade changes through the program later
	const	int		MaxRows(10);
	const	time_t 	WaitTime	(2); //sets time a 2 seconds

		bool	Board [MaxRows] [MaxCols]; // this works pretty well because bool just True or False
		int		Col; //variables for the input below
		int		Row;
		int		Whiletest;
		int		Generation;
		bool	Continue;
		time_t 	CurrTime; //shortcut way of writing unsigned long



		//set an initial pattern into our array
		//		we want the whole array "Board" to be set to false before we start input (using the memset controls)
				memset (Board, false, MaxCols * MaxRows * sizeof (bool)); // "sizeof" giving the number of bytes of bool so we don't have to specify
		cout << "Enter row and column to be occupied: ";
		do {
			cout << "> ";
			cin >> Row >> Col;
			if ((Row == -1) && (Col == -1))
				{
				Continue = false;
				}
			else
				{
				if ((Row < 0) || (Row >= MaxRows) || (Col > 0) || (Col >= MaxCols))
					{
					cout << "Error - outside the array boundaries try again" << endl;

					Board [Row] [Col] = true;
					}
				}
break;
			}while (Continue == true); //while (Continue)// while (condition) == true continually execute {}; False?- stops
			//create a Loop for each generation
				for (Generation = 0 ; ; Generation ++)
					//		display the board (current generation)
				{
				system ("clear");  //"clear" is when using linux, Windows or DOS is "cls".
				cout << "\t Generation" << Generation << endl;
				for (Row = 0; Row < MaxRows; Row++)
				{

				for (Col = 0; Col < MaxCols; Col++)
					cout <<  (Board [Row] [Col] ? '*' : ' ');
				cout << endl;
			}
		}

		//		for each cell on the board
		//			count how many neighbors are occupied
		//			apply the rules to determine what happens in the next generation
		//			if user wants to continue, start the loop over again
	/*		if (curses ())	//returns true if user hit a key, false if not
			CurrTime = time (0); //gets current time in seconds since Jan 1
			while ((time (0)- CurrTime) < WaitTime);   //called a busy wait, will keep looking at the clock until the time has passed.
*/
	return 0;
}


// To analyze the board:   use  (if


for(int r=0; r<ROWS; r++)
{
	for(int c = 0; c<COLS;c++)
	{
		cell = 0 % 7;
		if(cell >= 5)
		{
			life[r][c] = LIVE;
		}
		else
		{
			life[r][c]=DEAD;
		}
	}
}
for(int r = 0; r < ROWS; r++)
{
	for (int c = 0; c < COLS; c++)
	{
		cout << life[r][c] << " ";
	}
	cout << endl;
}
for(int k = 0; k < 10; k++)
{
for(int r = 0; r < ROWS; r++)
{
	for (int c = 0; c < COLS; c++, ans=0)
	{
		if(life[r][c] == LIVE)
		{
			if((c-1)>=0 && (life[r][c-1] == LIVE))
				ans++;
			if(c<COLS && (life[r][c+1] == LIVE))
				ans++;
			if(c<COLS && r<ROWS && (life[r+1][c+1] == LIVE))
				ans++;
			if((r<ROWS) &&(life[r+1][c]) == LIVE)
				ans++;
			if(r<ROWS && c>=0 && (life[r+1][c-1]) == LIVE)
				ans++;
			if(r>=0 && c>=0 && (life[r-1][c-1] == LIVE))
				ans++;
			if(r>=0 && (life[r-1][c] == LIVE))
				ans++;
			if(r>=0 && c<COLS && (life[r-1][c+1] == LIVE))
				ans++;
			if(ans==2 || ans == 3)
				life1[r][c] = LIVE;
			if(ans>3)
				life1[r][c] = DEAD;
			if(ans<2)
				life1[r][c] = LIVE;
		}
		else
		{
			if (life[r][c] == DEAD)
			{
            if(c>=0 && (life[r][c-1] == DEAD))
                ans++;
            if(c<COLS && (life[r][c+1] == DEAD))
                ans++;
            if(r<ROWS && c<COLS && (life[r+1][c+1] == DEAD))
                ans++;
            if(r<ROWS && (life[r][c] == life[r+1][c]))
                ans++;
            if(r<ROWS && c>0 && (life[r][c] == life[r+1][c-1]))
                ans++;
            if(r>=0 && c>=0 && (life[r][c] == life[r-1][c-1]))
                ans++;
            if(r>=0 && (life[r][c] == life[r-1][c]))
                ans++;
            if(r>=0 && c<COLS && (life[r][c] == life[r-1][c+1]))
                ans++;
            if (ans==3)
                life[r][c] = LIVE;
			}
		}
	}
}
for(int r = 0; r < ROWS; r++)
{
	for (int c = 0; c < COLS; c++)
	{
		life[r][c]=life1[r][c];
	}
}

for(int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
		cout << life[r][c] << " ";
		}
		cout << endl;
	}
}
}
