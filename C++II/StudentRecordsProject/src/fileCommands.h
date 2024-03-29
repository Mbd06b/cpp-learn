
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

enum CompareOption{	CompareInvalid = -1,
					CompareFirst,
					CompareMiddle,
					CompareLast,
					CompareID,
					NumCompareOptions,
				};

CompareOption getCompareOption();


void displayHelp();

char * ReadString ();
char * readFLDString (int);

static CompareOption option;

#endif /* FILECOMMANDS_H_ */
