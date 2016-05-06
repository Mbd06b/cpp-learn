


//#include <curses.h> //conio.h is the Visual Studio
#include "ReadInt.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

int ReadInt()
	{
	char	c;
	bool	IsNegative;
	int		Num;
	int		NumCharsEntered; //we need to keep track of the number of characters typed



	IsNegative = false;
	Num = 0;
	NumCharsEntered = 0;

	while ((c = cin.get()) != '\n') // \r is the enter key, we will read until you hit "ENTER"
							//_getch gets a character AS SOON AS YOU TYPE IT,
							// and it does show it on the screen (good for typing in passwords)
		{
		switch (c)
			{

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
						NumCharsEntered++;
						Num = (Num * 10) + (c - '0');  //'0' ASCII code for the character 48
						break;
			case '\b':
						if (NumCharsEntered > 0)
							{
							Num = Num / 10; // taking 1234 divided by 10 is a whole number 123 because we are not dealing with fractional numbers
							NumCharsEntered--;
							if (NumCharsEntered == 0)
									IsNegative = false;

							}


						break;

			default:
				break;


			}
		}


	return Num;	// send the number back to where we came from
	}

