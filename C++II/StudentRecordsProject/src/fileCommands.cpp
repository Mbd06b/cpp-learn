#include "fileCommands.h"
#include <iostream>
#include <string.h>
#include <ctype.h> //for isdigit
#include <stdio.h>


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
};

void displayHelp(){
	  cout << "Commands are: " << endl;
	  cout << "[Import]  - Select a .txt file in directory (Import Sample is named ToRead.txt)." << endl;
	  cout << "[Input]   - Input new student records to the program" << endl;
	  cout << "[Sort]    -  Sort records by name." << endl;
	  cout << "[Display] - Displays student records currently loaded in program." << endl;
	  cout << "[Export]  - Writes Student Records to a .txt file in project directory." << endl;
	  cout << "[Help] and [Exit]- Show these commands again or End Program" << endl;
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
	char * Cmds;
	int	i;

	Cmds = ReadString();

	for (int i = CompareFirst; i < NumCompareOptions; i++){ //NumCommands in at the bottom of our Commands Enumeration and will always hold the largest integer.
		if (strcasecmp (Cmds, CompareStrings [i]) == 0){ //  _strcmpi is strcmp "case insensitive" if
			delete [] Cmds;
			return (CompareOption)i; //added (Commands) to specify return a commands enumeration integer
		}
	}
		delete [] Cmds;
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

	bool errEntry = true;
	bool wrongLength = true;
	bool stillWrong = true;
	int		i; //we need to keep track of the number of characters typed
	char * pDTemp;
	pDTemp = new char [length + 1];
	i = 0;

	cout << "input [" << length << "] digits>";
				while((stillWrong) || (wrongLength)){
						char Ch;
						cin >> Ch;
								if(Ch == '0' || Ch == '1' || Ch == '2'|| Ch == '3'|| Ch == '4'|| Ch == '5'||Ch == '6'|| Ch == '7' || Ch == '8'|| Ch == '9' || Ch == '\n'){
									pDTemp[i++] = Ch;
									errEntry = false;
								}else{
									errEntry = true;
									i = 0;
								};
									if(errEntry || (i > length)){ //if error entry turns on, it stays on
										stillWrong = true;
									};

								if(i != (length)){ // will only be Length once.
									wrongLength = true;
								}else{
									wrongLength = false;
								};

								if(!wrongLength && stillWrong){
									i = 0;

								}else{
									stillWrong = false; //loop ends;

								}
				};



			pDTemp[length + 1] = '\0';

			cin.sync();
		cin.ignore(100, '\n');

			return pDTemp;
}








