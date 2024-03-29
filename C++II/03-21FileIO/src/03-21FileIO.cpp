//============================================================================
// Name        : 03-21FileIO.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream> // for dealing with IO using files  "is_open" is a member of fstream class
#include <iostream> // for cin and cout;

using namespace std;

int main() {
	fstream myFile; // there is a constructor that takes the same parameters
					// as the open method


	myFile.open (
				//first parameter is the file name, MUST BE C-TYPE string.
				//if not fully qualified, (like data.txt), the system looks in the current worknig directory
				//if it is fully qualified (like C:\xxx\yyy\data.txt) it looks in the directory
				// second parameter is a set of options joined by | (the bit wise OR operator)
				//
		"Test.txt",  // giving the file a name
		ios_base::in | // open the file for input (to read from the file)
						//with this option, the file must exist or the open fails
						//for ifstream types, this option is there by default
		ios_base::out | //open the file for output (writing to the file)
						//for ofstream types, this option is there by default
						//if used with ios_base::in, the file must exist or the open fails.
							//otherwise if the file does not exist, it will be created
						//if used by itself and the file does exist, it will be be destroyed.

		ios_base::ate | //"ate" or  At The End, open the file and goes to the end of the file
							//you CAN back up and write over what is already there
		ios_base::app | //"app" or Append, open the file and go to the end of the file.
							//if you back up and try to write, it will automatically move you
							//to the end of file and write there, prevents overwrite.
							//really great for log files for program records.

		ios_base::trunc | //"trunc" or Tuncate, truncates or DELETES the file when you open it.

		ios_base::binary  //"binary" A MISNOMER here. This refers to how the compiler interperets the the newline character \n.
							//files can be opened two ways, text (cooked), or binary (raw),
							//in files, there is some automatic conversions of the bit stream,
							//if you have a text file, you might want the \n code to be converted for readability
							//if you have a .jpg or something, you don't want a combination of bits that looks like the \n charater to screw with your picture.
							//an image to print out a cr/lf "carraige return line feed" or a line  return \n
							//IF YOU DON'T SPECIFY BINARY,  TEXT Mode is the DEFAULT"
	);

	if (myFile.is_open ()) //true if the file has been opened

	if (myFile.good()) // true if the last file operation worked, else false.
    if (myFile.fail()) // true if the last file operation did not work, ielse false.
    if (myFile.bad ()) //true if the operation really didn't work
    if (myFile.eof ()) //"eof" or End OF File, true if the last read ran into the end-of-file - "the wall"

    	//if fail, bad, or eof becomes true, no other IO operation wil work on this file
    	//UNTIL you call"clear ()"
    	myFile.clear();


	//WHEN YOU ARE WORKING WITH FILES, DO NOT USE << endl;
	//endl AUTOMATICALLY flushes the buffer.
	//use << '\n' the endline character, this does not flush the buffer, which taxes hard-drive resources

	//if you open a file make sure at some point you close it.
	myFile.close(); //if you don't close, you may lose saved data.

/*
	myFile >> x;  //to read

	myFile << x; //to write

	myFile.getline (---);
*/


	return 0;
}
