/*
 * Commands.h
 *
 *  Created on: Nov 9, 2015
 *      Author: mbd06b
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

enum Commands {
		CmdInvalid = -1, //an invalid command if we recieve something that doesn't match our ticketer is a terrible typist remember
		CmdAlpha,
		CmdBravo,
		CmdLounge,
		CmdFly,
		CmdArrive,
		CmdShutdown,

		NumCommands //will always confirm how many commands we have.
};


Commands GetCommand ();


#endif /* COMMANDS_H_ */
