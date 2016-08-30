

#include <WCS_String.h>
#include <iostream>
#include "UBArray.h"

using namespace std;

WCS_String Names [5];//Global Variable

void Func (const UBArray <int, WCS_String> &);

int main (){

	UBArray <int, WCS_String> List;

	Names[0] = "George";
	Names[1] = "Megan";
	Names[2] = "Bill";
	Names[3] = "Frank";
	Names[4] = "Ann";

	List [Names[2]] = -99; //put -99 into position "Bill"
	List [Names[1]] = -8;
	List [Names[4]] = 33;
	List [Names[0]] = 3333;
	List [Names[3]] = -3333;


	return 0;
}

void Func (const UBArray <int, WCS_String> & UB){

	cout << UB [Names [1]] << endl;

}
