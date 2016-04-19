/*
 * Card.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: mbd06b
 */
#include <iostream>
//#include <time.h> time.h used in VStudio,for srand.
#include <stdlib.h>
#include "Card.h"
using namespace std;

static char * ValueNames [] = { 				//using an Array of pointers, we avoid a twoD array with wasted space
								"Two",			// that would come after the '/0' end of string mark
								"Three",
								"Four",
								"Five",
								"Six",
								"Seven",
								"Eight",
								"Nine",
								"Ten",
								"Jack",
								"Queen",
								"King",
								"Ace"
								};

void InitDeck (Card Deck [])
{
	int i;
	Suits S;
	Values V;

	srand (time (0));
	for (S = Hearts; S <= Spades; S = (Suits) (S + 1)) // (Suits) tells the compiler that we know whats going on.
		for (V = Two; V <= Ace; V = (Values) (V + 1)) //
			{
			Deck [i].Suit = S;
			Deck [i].Value = V;
			i++;
			}

	}

void Show (const Card & C)//
//void Show (Card C)   //by default when you pass a structure it is "pass by value"
{					//most of the time people do a reference when passing a structure.
					//since structures can be huge!
	cout << "Cards is the " << ValueNames [C.Value] << " of " << (char) C.Suit << endl; //(char) pulls heart from the ASCII code table.

}

void Shuffle (Card Deck [])
{
	int i;
	int j;
	Card Temp;

	for (i = 0; i < 52; i++)
		{
		j	= rand () % 52;
		Temp = Deck [i]; //picked card out of deck
		Deck [i] = Deck [j]; //gets a random number, and does the remainder of 52;
		}


}

bool ThreeOfAKind (const Card Hand []) //you want to check 4 of a kind first. Because this will return true even if you have 4 of a kind.
{
	if ((Hand [0].Value == Hand [2].Value) ||
		(Hand [1].Value == Hand [3].Value) ||
		(Hand [2].Value == Hand [4].Value))
			return true; //true, you have three of a kind.
	else
			return false;
}

bool Straight (const Card Hand [])
{
	//Hand 9, 10 , J, Q, K should result in  Straight
	//Hand 2, 3, 4, 5, A // should result in a Straight. (TRICKY)
			//Write a special if statement to handle this one case.
			//if((Hand[0].Vaule == Two) &&
			// (Hand [1].Value == Three) &&
			// ...Four) &&
			// ...Five) &&
			// (Hand [4].Value == Ace)  // TRUE Straight.



	//Card [0].Value == (Card[1]Value-1)) &&
	//Card [1].Value == (Card[2].Value-1) &&
	//Card...
}



