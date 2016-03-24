//============================================================================
// DESCRIPTION : Programming Excercise Five, build a string test for palindromes
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 09/21/2015
//============================================================================


#include <iostream>
using namespace std;

#include <string.h>;
#include <cstring>;
#include <cstdlib>
#include <ctype.h>; // (toupper - "for purposes of this statement, treat all the characters as if it were uppercase")

int main()
{

	bool	checker = true;
	char	name [80];
	int		length;



do
{	cout << "Input text: " << endl;
	cin >> name;

		length = strlen(name); //length contains a number here
	int (length / 2);
		if(length > 0 ) //check to see if the string has characters, if true do what is in the next bracket
		{

			for (int i = 0; i < (length); i++) //for loop goes character by character through the string (i is 0, check to see if it is smaller than "length", if true add 1, stops when it is = length
			{
			 if(name [i] != name[length -1 -i]) //if statement checks for palindrome and prints either this is or is NOT
				checker = false;
			} //BillS-Option here "toupper command" if(touupper(line[i])==toupper(Line[j]) - This treats each caracter as it loops through the palindrome as if it were uppercase
		}		// Using this makes your loop less sensitive to upper and lowercase throwing off your palindrome analysis.
		else
			{
			cout << "Error, you did not input a string" << endl; // warning if the length is 0.
			}

		if(checker == true)
			 	 {
			 	 cout << "This is a palindrome" << endl;
			 	 }
			 	 else
			 	 {
			 	cout << "This is Not a palindrome" << endl;
			 	 }
checker = true;


} while (name != "END");


}
