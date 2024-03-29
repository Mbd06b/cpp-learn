//============================================================================
// Name        : (10-19).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int * pInt; //the * means that this variable will contain the address of pInt;
	char* pChar; //the space between the data type and * is optional
	int		X; 		//just a style thing,  adding 'p' to the beginning our our named variable
  	  	  	  	 //helps us to identify that this is a pointer.

  X = 5;
  pInt = &X; //the & here means get the address of variable X

  cout << "X is at location " << pInt << " and contains " << *pInt << endl;



  	 *pInt = -99; //places a value at the address found in pInt
  	 cout << "X now contains " << X << endl;

  	 //doing *pInt means to get what is at the address in pInt
		  //this is known as dereferencing pInt

  	 pInt = (int *) 123456;
  	 /* DOING THIS IS DANGEROUS, We are Applying to values to the memory, which could step on some other program or fuction.
  	 ;
  	 *pInt = -9999;
  	 cout << "At the address " << pInt << " we now have " << *pInt << endl;
  	 */

  	 int 	A [10] = {-1, -2, -3, -4, -5, -6, -8, -9, -10};

  	 pInt 	= &A [0]; //got the address of the first item in the array
  	 cout << "pInt now has " << (unsigned long long)pInt << endl;  // pInt, "I want the address printed as a regular integer.
  	 pInt 	= A;   //using an array name by itself means use & A [0]
  	 cout << "pInt now has " << (int)pInt << endl;  // prints the same address.

  	 cout << "pInt contains " << (int) pInt << " and now points to " << *pInt << endl; // prints points to the -1 in our array.
  	 pInt++;  //actualy adding 1 of however big an int is.
  	 cout << "pInt contains " << (int) pInt << " and now points to " << *pInt << endl; //points to -2 in our array A.
  	 	 //the memory address increases by 4, because an int is 4 bytes. shown by (int) pInt
  	 pInt += 2;
  	cout << "pInt contains " << (int) pInt << " and now points to " << *pInt << endl;
  		//since we added 2,  memory address increases by 8,  and our array number is -4.

  	pInt = A; // pInt is now pInt = A [0]; Remember... this is the same thing.
  	cout << "pInt contains " << (int) pInt << " and now points to " << *pInt << endl;
  	// the two following statements are sying the same thing....
  	cout << "the third element contains " << *(pInt + 3) << endl; // prints -4
  	cout << "the third element contains " << pInt[3] << endl;  // prints -4, note: it looks like, but this is not really an array.
  	cout << "the third element contains " << A[3] << endl;    //prints -4
  	cout << "the third element contains " << *(A + 3) << endl;  //same as saying cout A[0] so prints -4

  	//THE WHOLE POINT HERE ^^ IS THAT WE CAN MAKE POINTERS LOOK AND ACT LIKE ARRAYS.

  		cout << A [5] << endl; //should print -6
  	  	cout << *(A + 5) << endl; // should print -6
  	  	cout << *(5 + A) << endl; // prints -6 (math works both ways)
  	  	cout << 5 [A] << endl;  //prints -6




  	int TwoD [3][4] ={
  			{11, 12, 13, 14},
  			{21, 22, 23, 24},
  			{31, 32, 33, 34}
  	};

  	int Col;
  	int Row;

  	pInt = &TwoD [0][0];
  	Col = 3;
  	Row = 2;

  	cout << "Row two, column three contains " << *(pInt + (Row * 4) + Col) << endl;
  	//take the row ou want to be on X times the number
  	//calculate by getting starting address
  	// Multiply/y the row you want times the number of columns in array.
  	// add the product to the starting address
  	//then add the column you want.



  	 return 0;
}

