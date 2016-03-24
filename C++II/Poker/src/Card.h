/*
 * Card.h
 *
 *  Created on: Oct 28, 2015
 *      Author: mbd06b
 */

#ifndef CARD_H_
#define CARD_H_

enum Suits {Diamonds, Clubs, Hearts, Spades}; // enum is an enumeration. Hearts is 0, Diamonds is 1, Clubs is 3 ...ectra...
enum Values {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

//enum is similar to an "int" type, whole numbers only

struct Card
{
	int Value;
	int Suit;
	int Hand;

};

//void Show (Card); /// this is passing the WHOLE structure, this can be inefficent
void Show (const Card &); // adding the & ampersand, this is now passing a reference to a structure, which is more efficient					//
void InitDeck (Card []);
void Shuffle (Card []);  //create a function to

/*
bool ThreeOfAKind (Hand []);
bool Straight (Hand []);
*/

#endif /* CARD_H_ */
