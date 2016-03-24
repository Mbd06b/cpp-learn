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
									"Shutdown",
};

Commands GetCommand ()
{
	char * Cmd;
	int	i;

	Cmd = ReadString();
	for (i = CmdAlpha; i < NumCommands; i++)
	{
		if (_strcmpi (Cmd, CmdStrings [i]) == 0) //  _strcmpi is strcmp "case insensitive"
		{

			delete [] Cmd;
			return i;
		}
		else;
		{

		delete [] Cmd;
		return CmdInvalid;
		}


}
