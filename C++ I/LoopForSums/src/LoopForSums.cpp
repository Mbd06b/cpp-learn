//============================================================================
// Name        : LoopForSums.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>

using namespace std;

int main ()
	{
	long	Sum;
	long	Counter;

	Sum = 0;
	for (Counter = 1; Counter <= 10; Counter++)
			Sum = Sum + Counter;
	cout << "Sum is " << Sum << endl;


	return 0;
}


