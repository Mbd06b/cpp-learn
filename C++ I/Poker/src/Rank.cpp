/*
 * Rank.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: mbd06b
 */
#include"Card.h"
#include"Rank.h"
#include<iostream>
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
							"Hearts",			// that would come after the '/0' end of string mark
							"Diamonds",
							"Clubs",
							"Spades"
							};



bool FourOfAKind (Card Hand []){

	if (((Hand [0].Value) == (Hand [1].Value) == (Hand [2].Value) == (Hand [3].Value)) ||
		((Hand [1].Value) == (Hand [2].Value) == (Hand [3].Value) == (Hand [4].Value)))
		{
				cout << "FOUR OF A KIND!  ";
				return true; //true, you have four of a kind.
		}
		else
		{
				return false;
		}

}


bool Flush (Card Hand []){

	int FlushCheck = 0;
	for (int i = 0; i < 5; i++)
	{
		if (Hand [i].Suit == Hand [0].Suit)
		{
		FlushCheck++;
		}

	}
	if (FlushCheck == 5)
		{
		return true;
		}
	else
		{
		return false;
		}
}



bool Straight (Card Hand []){

	if (((Hand [0].Value + 1) == (Hand [1].Value)) &&
		((Hand [1].Value + 1) == (Hand [2].Value)) &&
		((Hand [2].Value + 1) == (Hand [3].Value)) &&
		((Hand [3].Value + 1) == (Hand [4].Value)))  //EX: 1,222,3

			{
			cout << "STRAIGHT! ";
			return true; //true, you have three of a kind.
			}
		else
		{
			return false;
		}


}


bool ThreeOfAKind (Card Hand []){


	if (((Hand [0].Value) == (Hand [1].Value) == (Hand [2].Value)) || //EX: 111,2,3
		((Hand [1].Value) == (Hand [2].Value) == (Hand [3].Value)) || //EX: 1,222,3
		((Hand [2].Value) == (Hand [3].Value) == (Hand [4].Value)))	//EX: 1,2,333
		{
				return true; //true, you have three of a kind.
		}
		else
		{
				return false;
		}

}

bool FullHouse (Card Hand []){
	if ((((Hand [0].Value) == (Hand [1].Value) == (Hand [2].Value)) && ((Hand [3].Value) == (Hand [4].Value))) || //EX: 5,5,5, &&  4,4
		(((Hand [0].Value) == (Hand [2].Value)) && ((Hand [2].Value) == (Hand [3].Value) == (Hand [4].Value)))) 	//EX: 4,4    &&  5,5,5
		{
		cout << " FULL HOUSE!  ";
			return true; //true, you have a FULL HOUSE;
		}
	else
		{
			return false;
		}

}


bool Pair (Card Hand []){

	if (((Hand [0].Value) == (Hand [1].Value)) ||
		((Hand [1].Value) == (Hand [2].Value)) ||
		((Hand [2].Value) == (Hand [3].Value)) ||
		((Hand [3].Value) == (Hand [4].Value)))
		{
				return true; //true, you have three of a kind.
		}
		else
		{
				return false;
		}

}

bool TwoPair (Card Hand []){

	int PairCounter = 0;

	for (int i = 0; i < 4; i++) //Runs 3 times, Checks 0 &1, 1 &2, 2 &3, 3 &4
		{
			 if ((Hand [i].Value) == (Hand [i+1].Value))  // if 0 == 1 add 1,
			 {
				PairCounter++;
			 }
		}
	if (PairCounter > 1)
	{
		cout << "TWO PAIR, ";
		return true;
	}
	else
		return false;



}

int HighCard (Card Hand [], int Score){

	Card Highest;

	Highest.Value = 0; //assigning zero to correct set the value.

	for (int i = 0; i < 5; i++) //Check all 5 cards.
			{
				if (Highest.Value < Hand [i].Value) //if next card in hand is larger than the value of the card before
				{
				Highest = Hand [i]; //assign our Highest Card the higher value card.
				}

			}
			Show (Highest);
			cout << "-High. ";
			Score = Highest.Value; //+4 value of suit to break ties. b/c Suite value can only add 3 to score.
			return Score;

}



