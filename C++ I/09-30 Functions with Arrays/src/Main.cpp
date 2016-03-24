/*
 * Main.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: mbd06b
 */


#include <iostream>
using namespace std;

#include "functions.h"

int main ()
{
	char	Str1 [] = "abcdefghijklmnopqrstuvwxyz";
	char	ValidOperators [] = "+-*/XxCc";
	char 	Op;

	cout << "Number of characters in " << Str1 << " is " << CountCharacters (Str1) << endl;
}

