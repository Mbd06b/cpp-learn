//============================================================================
// DESCRIPTION : Lab Four  C++II Person Class, with Name & Address Classes.
// CLASS       : COSC 1437.S02 – Lab 4
// AUTHOR      : Matthew Dowell
// DATE        : 04/04/2015
//============================================================================

#pragma warning (disable:4996)

#include <iostream>
#include "Name.h"
#include "Address.h"
#include "Person.h"
#include <string.h>
//#include "myStringclass.h"
using namespace std;

int main() {
    int compare;
	Name A1;
	Name Temp;
	int test;

	String beta;

	string mark;


cout << "By Grapthar's Hammer! Never Give Up, Never Surrender!" << endl;

cout << "Name Tests" << endl;
cout << endl;

	A1.setName("Peter", first);
	A1.setName("Blake", middle);
	A1.setName("Dowell", last);

	Name A2;

	A2 = A1;

	//compare tests

	//A2.setFirst ("Nathaniel");/**/
	Temp = A1;
	A1 = A2;
	A2 = Temp;


	cout << endl;
	A2.setLast("Dowell");
	A2.setFirst("George");
	test = A1.Compare(A2);
	cout << "Compare Test (A1.Compare(A2) is: " << test << endl;


	cout << "A1 is: " << A1 << endl;
	cout << "A2 is: " << A2 << endl;


if(A1 != A2){      //if == 0 aka false this means that they are the same name,
	if(A1 > A2){
		 cout << A1 << "  is larger than " << A2;
	}else
		cout << A1 <<  " is smaller than " << A2;

}else
	{
	test = (A1 == A2);
	cout << "test is: " << test << endl;
	cout << endl;
	cout << "They are the same name" << endl;
	}


cout << endl;
cout << endl;
cout << "Address Tests: " << endl;

Address A;
Address B;
Address C;
Address D;

	A.setStreet("408_Southfork");
	A.setCity ("Wylie");
	A.setState ("Texas");
	A.setZip   ("78240");



cout << endl;
cout << "Copy = operator assignment" << endl;
B = A; //assignment



cout << endl;
cout << "Display methods: " << endl;

cout << B.getStreet() << endl;
B.Display();
cout << endl;
cout << B << endl;

//DECOMMENT FOR COMPARISON TEST
//B.setZip ("78241");


	if (A == B){
		 cout << "Address A & B are the same" << endl;
	}else
		 cout << "They are different" <<endl;


cout << endl;
cout << "Person Tests: " << endl;

Person X (A1,B);

X.setFName("Bill");
X.setMName("C.");
X.setLName("Slater");
X.setStreet("2800 E Spring Creek Pkwy");
X.setCity("Plano");
X.setZip("75074");

cout << endl;
cout << "Set and Display Methods: " << endl;
cout << X << endl;
cout << "Display()" << endl;
 X.Display();




	return 0;
}
