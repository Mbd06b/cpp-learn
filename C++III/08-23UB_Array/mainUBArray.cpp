


#include <iostream>
#include "WCS_UB_Array.h"
#include "WCS_String.h"


using namespace std;

WCS_String Names [5];//Global Variable

void Func (const WCS_UB_Array <int, WCS_String> &);

int main (){

	WCS_UB_Array <int, WCS_String> List;

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

	Func(List);

	int x;
	cin >> x;

	return 0;
}

void Func (const WCS_UB_Array <int, WCS_String> & UB){

	cout << UB [Names [1]] << endl;

}
