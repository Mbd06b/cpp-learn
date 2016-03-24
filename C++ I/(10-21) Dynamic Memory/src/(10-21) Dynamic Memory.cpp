//============================================================================
// Name        : (10-21).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <malloc.h>  // this is a older (now unecessary library) use to allocate dynamic memory. (See example below)
						// replaced with new and free.  (see example comparison below).
int Sum1 (int [], int);
int Sum2 (int *, int);
int Sum3 (int [], int);
int Sum4 (int *, int);


int main() {

	int		i;
	int * pInt1;
	int * pInt2;
	int		NumElements;



	cout << "How many items need to be in the array?";
	cin >> NumElements;

				//the following is the newer style of getting and releasing dynamic memory.
	pInt1 = new int [NumElements]; //creates a one dimensional array of type int.
	for (i = 0; i < NumElements; i++)
		pInt1 [i] = 0;  // set each element to 0
	cout << "Sum is " << Sum1 (pInt1, NumElements) << endl;
	cout << "Sum is " << Sum2 (pInt1, NumElements) << endl;
	cout << "Sum is " << Sum3 (pInt1, NumElements) << endl;
	cout << "Sum is " << Sum4(pInt1, NumElements) << endl;
	delete [] pInt1;	//you must give the memory back to the system when you are through with it.
//Brackets ^^ Needed   //if you don't do this, you eat memory until the machine needs to reboot
						//Error: "Your computer is running out of resources"  is founded on this common
						//coding screwup.


	pInt2 = (int *) malloc (NumElements * sizeof (int)); //based on the old malloc library in header.
	for (i = 0; i < NumElements; i++)
			pInt2 [i] = 0;  // set each element to 0
		free (pInt2);								// free in malloc library to deallocate memory.

					// if you use new, then use delete
					// if you use malloc, then use free


	int Sum1 (int Data [], int NumElements)
		{
			int i;
			int Sum;

			for (Sum = 0, i = 0; i < NumElements; i++)

			Sum += Data [i];


			return Sum;
			}

	int Sum2 (int * pData, int NumElements)
		{
				int i;
				int Sum;

				for (Sum = 0, i = 0; i < NumElements; i++)

				Sum += *pData;
				pData++;


				return Sum;
		}

	int Sum3 (int * pData, int NumElements)
			{
					int i;
					int Sum;

					for (Sum = 0, i = 0; i < NumElements; i++)

					Sum += *pData;
					pData++;


					return Sum;
			}


	int Sum4 (int Data [], int NumElements) 		//BECAUSE WE USED Data[]
		{
			int i;
			int Sum;

			for (Sum = 0, i = 0; i < NumElements; i++)
			{
			Sum += *Data;
			Data++; 				//OUR COMPILER MAY NOT BE ABEL TO DO the Data++.
									//This may be a unique Microsoft Feature.
			}

			return Sum;
			}

	return 0;
}
