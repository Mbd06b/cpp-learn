/*
 * dice.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: mbd06b
 */


#include "dice.h"
#include <time.h>
#include <stdlib.h>



void InitDice ()
{
	srand (time (0)); //srand sets the starting point (seed) fo our random number
}

int ThrowDice ()
	{
	return ThrowDie () + ThrowDie ();
	}

int ThrowDie ()
{
	return (rand () % 6) +1;
}
			//rand () : Returns a random number
			// % 6 returns a remainder between 0 and 5
			// +1  returns a numbers between 1 and 6, To show our die.

