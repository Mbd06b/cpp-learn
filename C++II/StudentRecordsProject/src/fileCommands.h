
#ifndef FILECOMMANDS_H_
#define FILECOMMANDS_H_

enum Commands{
	CmdInvalid = -1,
	CmdImportRecords,
	CmdInputRecords,
	CmdSortRecords,
	CmdDisplayRecords,
	CmdExportRecords,
	CmdHelp,
	CmdExit,
	NumCommands

};

Commands getCommand();

void displayHelp();

char * ReadString ();




#endif /* FILECOMMANDS_H_ */
