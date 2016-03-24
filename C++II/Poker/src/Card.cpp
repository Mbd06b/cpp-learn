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
static char * ValueSuit [] = { 				//using an Array of pointers, we avoid a twoD array with wasted space
							"Diamonds",		// that would come after the '/0' end of string mark
							"Clubs",
							"Hearts",
							"Spades"
							};

void InitDeck (Card Deck [])   //Card (int Value, Suite, Hand), Creating array called Deck [].
{
	int i = 0;
	Suits S; //grabs "Suites" data from struct, assigned variable S.
	Values V; //grabs "Values".... assigns V.

	srand (time (0)); //seed random value.
	for (S = Diamonds; S <= Spades; S = (Suits) (S + 1)) // Loops 4 times. (Suits '0,1,2,3') Hearts is 0, Spades is 3,  we are telling the compiler what is going on with the (Suites) description.
		for (V = Two; V <= Ace; V = (Values) (V + 1)) //for each suite,  assign values 2 thru Ace.
			{
			Deck [i].Suit = S; // Assign Suite to card location in Deck
			Deck [i].Value = V; // Assign Value to card
			i++; //add 1, should equal 51 to complete, (0-51 is 52 cards)
			}

	}

void Show (const Card & C)//
//void Show (Card C)   //by default when you pass a structure it is "pass by value"
{					//most of the time people do a reference when passing a structure.
					//since structures can be huge!
	cout << ValueNames [C.Value] << " of " << ValueSuit [C.Suit]; //(char) pulls heart from the ASCII code table.

}

void Shuffle (Card Deck [])
{
	int i;
	int j;
	Card Temp;

	for (i = 0; i < 52; i++)
		{
		j	= rand () % 52;
		Temp = Deck [j]; //picked card out of deck
		Deck [j] = Deck [i];
		Deck [i] = Temp; //gets a random number, and does the remainder of 52;
		}

}





