//============================================================================
// Name        : 9-16WorkingWithC-Type_Strings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h> // use this when doing the functions starting with str to work with C-Type Strings
int main()
{
	char	Str1 [31] = "Bill";  //using " " makes this the same as = {'B','i','l','l'} using string quotes is a shortcut. with the endl mark
	char	Str2 [31] = "George";
	char	Str3 [31] = "Megan";
	char	Str4 [31] = "PETER";
	char	Str5 [31] = "MILLIE";

				//what comes back from strcmp -- what it means
				// 			<0	First string is less than the second
				//			== 0 Two strings are the same
				//			>0  second string is less than the first

	if (strcmp (Str2, Str3,) < 0)   // strcmp compares ASCII codes for the characters (ie. uppercase ABCD, comes before lowercase abcd)
			cout << Str2 << " comes before " << Str3 << endl;
	else
			cout << Str2 << " is NOT before " << Str3 << endl;

	if (strcmpi (Str3, Str4,) < 0)	// strcmpi compares the case(upper or lower in visual studio
									// this could be stringcase or some other SYNTAX in GCC (linux) or Xcode(Mac).
			cout << Str3 << " comes before " << Str4 << endl;
	else
			cout << Str3 << " is NOT before " << Str4 << endl;

	cout << "The number of characters in " << Str2 << " is " << strlen (Str2) << endl;

	//Cannot use equals sign Str1 = Str2, does not work with arrays
	cout << "Str1 starts as " << Str1 << endl;
	strcpy (Str1, Str2); // copies the characters from Str2 into Str1 and copies them
	cout << "After copy, Str1 is " << Str1 << endl;

	cout << "Str2 starts as " << Str2 << endl;
		strcpy (Str2, Str4, 3); // copies the characters from Str2 into Str1 and copies them, then copies three characters
		cout << "After strncopy, Str4 is " << Str4 << endl;
		return 0;


	return 0;
}
