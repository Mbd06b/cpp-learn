//============================================================================
// DESCRIPTION : Lab Three  C++II Generic Array Template Based Class w/some exception handling.
// CLASS       : COSC 1437.S02 – Lab 3
// AUTHOR      : Matthew Dowell
// DATE        : 02/23/2015
//============================================================================


#include "Array.h"
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int main (){

Array <int, -3, 6>  testObject;
Array <int, -3, 6>  secondObj;
Array <int, -3, 6> thirdObj;
Array <int, -3, 6> fourthObj;
Array <string, 0, 5> stringObj;
Array <string, 0, 5> stringCopy;
Array <string, 0, 5> stringOpCopy;

/* UNCOMMENT TO Test Exception Handling
try{

throw testObject.setAt(-3,10);
		testObject.setAt(-2,11);
		testObject.setAt(-4, 15);  //This Triggers Exception
}catch (int e){
	cout << "Exception " << e <<  " thrown, Index Out of Bounds!" << endl;
};
*/

secondObj.setAt(-3,10);
secondObj.setAt(-2,11);
secondObj.setAt(-1,12);
 //Copy Test

thirdObj = secondObj;

cout << "Assigned, Copied using overloaded operator (=) and object method, and displayed value.";
cout << "Third Obj index value at [0] is: " << thirdObj.getAt(-3) << endl; //Copy Proof with Display Method.

fourthObj.Copy(thirdObj);

cout << "Using a Copy(Obj) method: " << endl;
cout << "Fourth Obj index value at [1] value is: " << fourthObj.getAt(-2) << endl;

stringObj.setAt(0,"Geewillies");
stringCopy.Copy(stringObj);
stringOpCopy = stringCopy;
cout << endl;

cout << "Assigned, Copied, and used operator (=), on a string type, proving generic nature of class." << endl;
cout << "StringOpCopy value at index location 0 is: " << stringOpCopy.getAt(0) << endl;

 cout << "\n Program Ended";
	return 0;
}
















