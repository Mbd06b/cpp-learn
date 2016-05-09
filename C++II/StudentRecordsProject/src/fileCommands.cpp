#include "fileCommands.h"
#include <iostream>
#include <string.h>
#include <ctype.h> //for isdigit

//----------------Stuff needed to getch working
#include <termios.h>
#include <stdio.h>
//------------------

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

char * readFLDString (int length){

		char 	c;
		int		CurrNumChars;
		char *	pData2;

		CurrNumChars = 0;
		pData2 		= new char [length + 1]; // +1 to capture the "End of String" mark returned if we don't input any names.

		do{
		c = cin.get();

			if (!isdigit(c)){
				cout << "Invalid Character, string should be [" << length << "] digits. Start over.";
				CurrNumChars = 0;
			}else{
				pData2 [CurrNumChars++] = c;  // this is valid +1 arithmetic because it's in the [] brackets.
			};
		}while(CurrNumChars < length);
			pData2 [length + 1] = '\0';  // when we hit the ENTER KEY, we need to put a end of string mark at the end.
		return pData2;
}



