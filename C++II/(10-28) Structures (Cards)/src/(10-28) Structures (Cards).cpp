//============================================================================
// Name        : (10-28).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "Card.h"
using namespace std;

int main() {


	Card C; //now a datatype like int or size_t.
	Card C2;
	Card Deck [52];
	int i;

	C.Suit = Hearts;  // 0 could be recognize as a
	C.Value = 5;

	Show (C);

	//C2 = C; // = works even though their are multiple items inside a structure.

	Deck [3].Suit = Clubs;
	Deck [3].Value = Ace;

	Show (Deck [3]);

	C2 = C; // = works even though their are multiple items inside a structure.

	InitDeck (Deck);
	//system ("cls");  //clears the screen for windows, part of stdlib.h
system ("clear"); //UNIX version.

	cout << "Deck is: " << endl;
	for (i = 0; i < 52; i++)
		Show (Deck [i]);

	Shuffle(Deck);


system ("clear");

	cout << "Deck is: " << endl;
	for (i = 0; i < 52; i++)
		Show (Deck [i]);

/* THREE OF A KIND
	for (i = 0; i < 4; i++)
	{
		if (ThreeOfAKind (Hand [i])
			cout << "It is Three of a Kind " << endl;
	}
*/

	return 0;
}
