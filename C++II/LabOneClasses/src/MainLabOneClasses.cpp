//============================================================================
// DESCRIPTION : Lab Two  C++II Class with Operator
// CLASS       : COSC 1437.S02 – Lab 2
// AUTHOR      : Matthew Dowell
// DATE        : 02/24/2015
//============================================================================

#include <iostream>
#include "class.h"
#include "string.h"

using namespace std;



int main() {

	String defaultString; //DEFALT "for the default constructor - one with no parameters to initialize the class to empty;"
	String ctypeString ("abcdefg"); //CTYPE "one with a pointer to a “C” type string as a parameter to initialize the class to contain a copy of that string;"
	String copyofString (ctypeString); //and one with a parameter that is of class String to initialize to a copy of that value.
	String str2 ("hijklmnop");
	String str3;
	int toinput = 0;
	int check = 0;
	unsigned long len = 0;


	//Display function (Display) to display the characters in the String object.
	cout << "The following is the display inline function created by overloading the << operator" << endl;
	cout << copyofString << endl;


	cout << "\nCompare function" << endl;

	check = str2.Compare (copyofString);

	cout << "check is " << check << endl;

	cout << "\nString Concatenate example: " << endl;

	copyofString.Concat (str2);

	cout << copyofString << endl;


	cout << "\nC-Type String Concatenate example: " << endl;
	copyofString.Concat ("qrstuvwxyz");

	cout << copyofString << endl;

	cout << "\nString Length is: " << endl;

	len = copyofString.Length();

	cout << len << endl;

	cout << "\nDisplay Method" << endl;

	copyofString.Display();

	cout << "Overloading the = operator" << endl;

	str3 = ctypeString;
	cout << str3 << endl;

	cout << endl;
	cout << "ctypeString is: " << ctypeString << endl;

	cout << endl;
	cout << "Overloading the & concatenate Operator" << endl;


	str3 = ctypeString & str2;
	cout << str3 << endl;

	cout << endl;

	cout << "str2 is: " << str2 << endl;
	cout << "ctypeString is: " << ctypeString << endl;
	cout << endl;
	cout << "Overloading the &= concatnate assignment Operator" << endl;

	ctypeString &= str2;
    //str2 &= ctypeString;


	cout << ctypeString;


	cout << endl;
	cout << "\nProgram Finished" << endl;





	return 0;
}



/*
Modify Program One to add the following:
Assignment operator (“=”).
Comparison operators (“<”, “<=”, “==”, “!=”, “>=”, “>”)
Concatenation operator (“&”).
Concatenation and assignment operator (“&=”)
Input operator (“>>”).
Output operator (“<<”).

Above items 1 through 4 should have versions that work with a String object and a “C” type string on the right of the operator.

Items 5 and 6 require a String object to the right of the operator.

Items 1 and 4 will require a String object on the left of the operator.

Items 2 and 3 should have versions that allow both a String object and a “C” type string on the left of the operator.

Item 3 does not modify the object to the left of the operator.


 */
