/*
 * Commands.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: mbd06b
 */




#include <iostream>
#include <string.h>
using namespace std;

#include "Party.h"
#include "Plane.h"
#include "Commands.h"
#include "ReadString.h"

char * CmdStrings [NumCommands] = {
									"Alpha",
									"Bravo",
									"Lounge",
									"Fly",
									"Arrive",
									"Display",
									"Shutdown",
};

Commands GetCommand ()
{
	char * Cmd;
	int	i;


	Cmd = ReadString();

	for (i = CmdAlpha; i < NumCommands; i++) //NumCommands in at the bottom of our Commands Enumeration and will always hold the largest integer.
	{
		if (strcmp (Cmd, CmdStrings [i]) == 0) //  _strcmpi is strcmp "case insensitive" if
		{
			delete [] Cmd;
			return (Commands)i; //added (Commands) to specify return a commands enumeration integer
		}

	}

		delete [] Cmd;
		return CmdInvalid; //CmdInvalid is part of the Commands Enumeration (-1)



}
