//============================================================================
// Name        : Program4Solution.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const 	long	MaxCounter (100000000);
			long	Counter;
			double	dSumDown;
			double	dSumUp;
			float	fSumDown;
			float	fSumUp;

		dSumDown = 	0;
		dSumUp = 	0;
		fSumUp =	0;
		fSumDown =	0;


	for (Counter = 1; Counter <= MaxCounter; Counter++)
	{
	dSumDown	+= (1.0 / Counter);
	dSumUp		+= (1.0 / ((MaxCounter +1)- Counter));
	fSumDown	+= (1.0f / Counter);
	fSumUp		+= (1.0f / ((MaxCounter +1)- Counter));
	}

	cout.precision(14);
	cout << "Sum as double counting down is:  " << dSumDown << endl;
	cout << "Sum as double counting up is:  " << dSumUp << endl;

	cout.precision(7);
	cout << "Sum as float counting down is:  " << fSumDown << endl;
	cout << "Sum as float counting up is:  " << fSumUp << endl;

	cout << "The lesson here:  Each time a math operator is used, you lose the digits on floats and eventually doubles, as you divide over and over and over" << endl;
	cout << "So use doubles (almost by default), and sum up from the smallest absolute values first to the larger absolute numbers for accuracy";


	return 0;
}
