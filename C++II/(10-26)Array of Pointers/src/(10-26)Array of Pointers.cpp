//=========================Other Notes Top ===================================================

/* struct Card  //struct is a information type that creates custom datatypes. like Card;
 	 	 	 	//class is a form of struct, but on steroids, very commonly used.
	{
	char Suit;
	int Value;
	}

	Card C1;  // C1 is now a Card.

	Card Deck [52]; so now we have an array of cards with dual values of Suit and Value.

	struct Name
	{
	char First[16];
	char Middle [16];
	char Last [26];
	char Title [6];
	char Suffix [6];
	}


*/


#include <iostream>
using namespace std;
//include "ReadString.h" (no header created, ReadString prototype below)

char * ReadString (); // prototype
void Sort (char * [], int);
void Swap (char *, int , int);

//---------------------------FUNCTIONS ---------------------

void Swap (char * pNames [], int i, int j)  //passing the array of pointers, and two values we want to swap
{
 char * Temp;

 Temp = pNames[i];        //swapping
 pNames [i] = pNames [j];
 pNames[j] = Temp;
}

//---------------------------MAIN----------------------------


int main() {

	int 	i;
	int 	NumNames;
	char * pNames1 [20]; //the most names this can handle is 20
	char ** pNames2;  // a dynamic array of addresses (pointers) so our array can hold a variety of values.



	i = 0;
	pNames1 [i] = ReadString ();
	i++;
	pNames1 [i] = ReadString ();

	if (pNames1 [i] [0] == '\0') //check if the name is empty
		{
		cout << "Done" << endl;
		NumNames = i;
		}
	else;

	Sort (pNames1, NumNames);

	Swap (pNames1, 0, 1);


//--------------------------------------------Creating an "DYNAMIC" Array of Pointers ------------------------------------------


	i = 20;  //creating a dynamic array of pointers;
	pNames2 = new char * [i];  //new


	i = 0;
	pNames2 [i] = ReadString ();
	i++;
	pNames2 [i] = ReadString ();

	if (pNames2 [i] [0] == '\0') //check if the name is empty
				{
				// when the array fills up, create a bigger array
				//like what we did in writing ReadString
				}
		else;
	Sort (pNames2, NumNames);
	Swap (pNames2, 0, 1);


	return 0;
}






