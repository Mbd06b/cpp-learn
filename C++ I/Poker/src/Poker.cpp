//============================================================================
// DESCRIPTION : Program 13, Poker Game, With Hand Ranking and Winner Determination
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 11/18/2015
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "Card.h"
#include "CharSSort.h"
#include "Rank.h"
using namespace std;

int main() {

char Continue;

do{
	int iPlayerLoop;
	int iHandLoop;
	int DrawCounter = 0;
	Card Deck [52]; //our card deck is assigned 52 slots. (0-51)

	const int NumPlayers = 4;
	const int HandSize = 5;
	int SizeChecker1 = 0;
	int SizeChecker2 = 0;
	int HandRank [NumPlayers];
	int RankScore = 0;

	int HighCScoreRank [NumPlayers];
	int HighCScore = 0;



	Card PlayerHands [NumPlayers][HandSize]; //Card Array 4rows by 5 cards.



	cout << "Before we begin, please note that symbols work differently in UNIX and WINDOWS Environments " << endl;
	cout << "The Following prints a nice heart symbol" << endl;
	const char LinuxHeartSymbol [] = "\xe2\x99\xa5";
	cout << "On Linux: " << LinuxHeartSymbol;
	enum Example {HeartSymbol = 3};
	cout << " On Windows: " << (char) HeartSymbol << endl;
	cout << "Due to these complications, The hands will show the Value Suite as follows: " << endl;
	cout << "2 of Hearts, (or if a face card), K of Hearts " << endl;

//--------DECK TEST -----------------
	/*cout << "Deck is: " << endl;
		for (i = 0; i < 52; i++)
			Show (Deck [i]);
		*/

	InitDeck (Deck);
	Shuffle(Deck);



//------------------Deal Cards -----------------------------------------------
	for (iPlayerLoop = 0; iPlayerLoop < NumPlayers; iPlayerLoop++) //loop for each hand.
		{
				for (iHandLoop = 0; iHandLoop < HandSize; iHandLoop++)
				{
					PlayerHands [iPlayerLoop][iHandLoop] = Deck [DrawCounter]; //Assigns the Cards to a hand.
					Deck [DrawCounter].Hand = iPlayerLoop; //saves to which player (Hand) the Card Belongs.

					DrawCounter++;

				}
		}
	cout << endl;

//-------------------Sort Hands/Capture Ranks/Show Hands--------------------------------------------------

	for (iPlayerLoop = 0; iPlayerLoop < NumPlayers; iPlayerLoop++)
		{
		Sort (PlayerHands [iPlayerLoop]);
		}

	for (iPlayerLoop = 0; iPlayerLoop < NumPlayers; iPlayerLoop++)
			{
		/*bool StraightFlush (PlayerHands [iPlayerLoop]);
		bool FourOfAKind (PlayerHands [iPlayerLoop]);
		bool FullHouse (PlayerHands [iPlayerLoop]);
		bool Flush (PlayerHands [iPlayerLoop]);
		bool Straight (PlayerHands [iPlayerLoop]);
		bool ThreeOfAKind (PlayerHands [iPlayerLoop]);
		bool TwoPair (PlayerHands [iPlayerLoop]);
		*/

			}




	for (iPlayerLoop = 0; iPlayerLoop < NumPlayers; iPlayerLoop++) //loop for each hand.
			{ 	RankScore = 0; //set Rank to 0;
				cout << "Player Hand " << iPlayerLoop + 1 << ": ";
					for (iHandLoop = 0; iHandLoop < HandSize; iHandLoop++)
					{

						Show(PlayerHands [iPlayerLoop][iHandLoop]);//prints out all hands.
						cout << endl;

					}cout << endl;

//------------HAND ANALYSIS ---------------------------------------------
			if (Straight (PlayerHands [iPlayerLoop]))
				{
				RankScore += 7;
					if (Flush (PlayerHands [iPlayerLoop])) //STRAIGHT FLUSH
						{
						cout << "FLUSH!!,"; // Straight prints first, this adds Flush to the end.
						RankScore = RankScore + 1;
						}
				}

			else if (Flush (PlayerHands [iPlayerLoop])) //Normal FLUSH Triggers w/o Straight
					{
					cout << "Flush!,"; //since it is nested above
					RankScore += 5; ;
					}


			if (FourOfAKind (PlayerHands [iPlayerLoop])) //if only since Four of a Kind can beat a Flush.
					{
					RankScore += 6;
					}

			else if (ThreeOfAKind(PlayerHands [iPlayerLoop]))//else if we don't have a 4ofAKind, Check for 3.
					{
					if (FullHouse(PlayerHands [iPlayerLoop])) //Full House only checks if Three of a Kind is True
						{
						RankScore += 5;
						}
					else
						{
						RankScore += 3;
						cout << "THREE OF A KIND,"; // IF Three of a kind, but not a Full House
						}
					}

			else if (Pair (PlayerHands [iPlayerLoop])) //else if we don't have 3 of a Kind check if pair is true.
						{


							if (TwoPair(PlayerHands [iPlayerLoop])) //if pair is true, check for a second pair.
								{
								RankScore += 2;
								}
							else
							{
							RankScore += 1;
							cout << "Pair!,"; //pair already ranked above.
							}
						}




					HighCScore = HighCard (PlayerHands [iPlayerLoop], HighCScore);//Shows Highest Card, and Records value.


			//if TIE EXISTS Calculate HighCard Winner
					HandRank [iPlayerLoop] = RankScore;
					HighCScoreRank [iPlayerLoop] = HighCScore;


			}


/* -----------Display HAND RANKS ---------------
	for(int i = 0; i < NumPlayers; i++)
			{
		        cout << HandRank [i] << ", ";
		        }
-----------------------------------*/

	 int TopHand = 0;
	 int HighCard = 0;
	 int TieChecker = 0;

	    for(int i=0;i<5;i++)


cout << endl;

	for(int i = 0; i < NumPlayers; i++)
		{
	        if(HandRank[i]>TopHand)
	        {
	        TopHand = HandRank[i];
	        }
	    }

cout << "Winning Player:  ";
	for(int i = 0; i < NumPlayers; i++)
	{
			if (TopHand == HandRank[i])
				{
				TieChecker++;

				if(TieChecker > 1)
					{
						if (TopHand == HandRank[i])
							{
							 cout << " & " << i + 1;
							}
					}
					else
					{
					 cout << i + 1;
					}
	    	    }
				else
				{
				HighCScoreRank [i] = 0;
				}
	 }

	if (TieChecker > 1)
	{
		cout << "  TIE! Check High Cards ";
	}

	cout << endl;

	cout << "Continue y/n:" ;
	cin >> Continue;

	if(Continue == 'y')
	{
	system ("clear"); //UNIX version.
	}

}while (Continue == 'y');

cout << "END PROGRAM " << endl;

/* S ON CLEARING THE SCREEN -------------
	//system ("cls");  //clears the screen for windows, part of stdlib.h


----------------------------------------------------

	cout << "Deck is: " << endl;
	for (i = 0; i < 52; i++)
		Show (Deck [i]);


	cout << endl;
	cout << endl;

	//system ("clear");

	cout << "Deck is: " << endl;
	for (i = 0; i < 52; i++)
		Show (Deck [i]);
/*
// THREE OF A KIND
	for (i = 0; i < 4; i++)
	{
		if (ThreeOfAKind (Hand [i])
			cout << "It is Three of a Kind " << endl;
	}
*/

	return 0;
}
