#include "fileCommands.h"
#include <iostream>
#include <string.h>



using namespace std;


char * CmdStrings [NumCommands] = {
									"Import", //ReadInRecords
									"Input",
									"Sort",
									"Display",
									"Export",
									"Help",
									"Exit",
};

char * CompareStrings [NumCompareOptions] = {
									"First",
									"Middle",
									"Last",
									"", //Default
};

void displayHelp(){
	  cout << "Commands are: " << endl;
	  cout << "[Import] - Select a file in project directory to read, (Sample is named ToRead.txt)." << endl;
	  cout << "[Input] - Input new student records to the program" << endl;
	  cout << "[Sort] -  Sort records by name." << endl;
	  cout << "[Display] - Displays student records currently loaded in program." << endl;
	  cout << "[Export] - Writes Student Records to a .txt file in project directory." << endl;
	  cout << "[Help] - Show available commands." << endl;
}

Commands getCommand (){

	char * Cmd;
	Cmd = ReadString();
	for (int i = CmdImportRecords; i < NumCommands; i++){ //NumCommands in at the bottom of our Commands Enumeration and will always hold the largest integer.

		if (strcasecmp (Cmd, CmdStrings [i]) == 0){ //
			delete [] Cmd;
			return (Commands)i; //added (Commands) to specify return a commands enumeration integer
		}else;
	}
		delete [] Cmd;
		return CmdInvalid; //CmdInvalid is part of the Commands Enumeration (-1)
}



CompareOption getCompareOption (){
	char * Cmd;
	int	i;

	Cmd = ReadString();

	for (i = CompareLast; i < NumCompareOptions; i++){ //NumCommands in at the bottom of our Commands Enumeration and will always hold the largest integer.
		if (strcmp (Cmd, CompareStrings [i]) == 0){ //  _strcmpi is strcmp "case insensitive" if
			delete [] Cmd;
			return (CompareOption)i; //added (Commands) to specify return a commands enumeration integer
		}
	}
		delete [] Cmd;
		return CompareInvalid; //CmdInvalid is part of the Commands Enumeration (-1)
}


char * ReadString ()
{
	const int		FirstGuess (50);
	char 	c;
	int		CurrNumChars;
	int		CurrSize;
	char *	pString;
	char *	pTempString;

	CurrNumChars = 0;
	CurrSize 	= FirstGuess;
	pString 		= new char [CurrSize +1]; // +1 to capture the "End of String" mark returned if we don't input any names.

	while ((c = cin.get()) != '\n') //cin.get gets the characters as you type them  \n is the ENTER or RETURN character on the keyboard.
			{
			pString [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
				if (CurrNumChars >= CurrSize)  // is the array full?
					{			// Yes, I need a bigger array
						CurrSize += FirstGuess;
						pTempString = new char [CurrSize + 1];
						//stingcopy won't work, because we haven't used an end of string mark to judge the size
						memcpy (pTempString, pString, CurrNumChars); //copies string Chars to TempString
						delete [] pString;  //data is not needed now so we are giving it back to the system.
											// String still contains a memory address, we dont "own" that location anymore.
											//IF YOU DONT DELETE THE ALLOCATED MEMORY YOU WILL HAVE a memory leak RESOURCE FAILURE.
						pString = pTempString; //not moving any characters
					}else;
			}//end of while
		pString [CurrNumChars] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.
		return pString;
}

size_t ReadDigit(){
	char	c;
	bool	IsNegative;
	size_t		Num;
	int		NumCharsEntered; //we need to keep track of the number of characters typed

	IsNegative = false;
	Num = 0;
	NumCharsEntered = 0;

	while ((c = cin.get()) != '\n'){ // \r is the enter key, we will read until you hit "ENTER"
							//_getch gets a character AS SOON AS YOU TYPE IT,
							// and it does show it on the screen (good for typing in passwords)
		switch (c){
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
						if (NumCharsEntered > 0){
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

