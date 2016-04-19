//============================================================================
// DESCRIPTION : Program 9, A Modified Craps Game
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 10/20/2015
//============================================================================



#include <time.h>	//used to load our random number generator.
#include <stdlib.h> //for Srand and Exit Functions
#include <iostream>
using namespace std;


	int		 Die1, Die2;
	int		 Sum;
	int		 Point;
	double	 Wallet, Bet, Checksum;
	bool	Checker = true;
	char	Continue = 'y';
	char	Begin;

int main()
{

	Wallet = 50.00;
	cout << "Welcome to the Craps Table!" << endl;
	cout.precision(4);

	cout  << "You have $" << Wallet << " in your wallet to start." << endl;
	cout << endl;


	while (Continue == 'y' || Continue == 'Y')
	{
	srand(time(0)); //1 is 1000 seconds. So a zero is stopping time.

	//Ask for Bet
	//Subtract Bet, Display Wallet and Bet balance.

		cout << "How much do you want to bet?" << endl;
		cout << ">$";

		do
		{
		cin >> Bet;
		Checksum = Wallet - Bet; //checks to see if your bet is bigger than the wallet.

				if (Checksum < 0)
				{
					cout << "You don't have that much to bet" << endl;
					Checker = false;
				}
				else if (Bet <= 0)
				{
					cout << "You need to bet something to play" << endl;
					Checker = false;
				}
				else
				{
				Checker = true;
				}

		} while (Checker == false);


	Wallet = Wallet - Bet;
	cout << "You Bet: $" << Bet << " And have: $" << Wallet << " left in your wallet." << endl; //Display Wallet Balance
	cout << endl;

	Die1 = (rand()+1) % 6 + 1; //+1 added to rand time so the result
	Die2 = rand() % 6 + 1;
	Sum = Die1 + Die2;

	cout << "Die1: " << Die1 << " Die2: "<< Die2 << endl;
	cout << "You rolled: " << Sum << endl;


	 //Create Rules

	 //If the total value is 7 or 11,  the user is an instant winner.
		switch (Sum)
			{
			 case 7:
			 case 11:
				 Wallet = (Bet * 2) + Wallet;  //amount bet added back to total.
				 Checker = false;
				 cout << "YOU WON!" << endl;
				 Bet = 0;
				 	 break;
			 case 2:
	 	 	 case 3:	//If the value is 2, 3, or 12, Instant Lose.
	 	 	 case 12: 	 	 	 	 	 //amount bet is set to zero, nothing is added back to wallet.
	 	 		 Wallet = Wallet - Bet;
	 	 		 Checker = false;
	 		 	cout << "YOU LOSE!" << endl;
	 		 	Bet = 0;
	 		 		break;

	 	 	 default:  //If 4, 5, 6, 8, 9, 10.
	 	 		 	 cout << "Roll again" << endl;
	 	 		 	 Checker = true;
	 	 		 	 Point = Sum;


	 	 		 	while (Checker == true)
	 	 		 		 {
	 	 		 		 	 Point = Sum;
	 	 		 		 	 Die1 = (rand()+1) % 6 + 1; //+1 added to rand time so the results are different
	 	 		 		 	 Die2 = rand() % 6 + 1;
	 	 		 		 	 Sum = Die1 + Die2;
	 	 		 		 	 cout << "Die1: " << Die1 << " Die2: "<< Die2 << endl;
	 	 		 		 	 cout << "You rolled: " << Sum << endl;



	 	 		 		 	 	 if (Sum == Point)
	 	 		 		 	 	 	 {
	 	 		 		 	 		 Wallet = (Bet * 2) + Wallet;  //amount bet added back to total.
	 	 		 		 	 		 cout << "YOU WON!" << " You have $" << Wallet << " in your wallet." << endl;
	 	 		 		 	 		 Bet = 0;
	 	 		 		 	 		 Checker = false;
	 	 		 		 	 	 	 }
	 	 		 		 		 else if (Sum == 7)
	 	 		 		 		 	 {
	 	 		 		 			  //Bet is set to zero, nothing is added to Wallet.
	 	 		 		 		 	 Bet = 0;
	 	 		 		 		 		cout << "YOU LOST!" << " You have $" << Wallet << " left in your wallet." << endl;
	 	 		 		 		 		Checker = false;
	 	 		 		 		 		}
	 	 		 		 		 else
	 	 		 		 		 	 {
	 	 		 		 			 cout << "Roll Again" << endl;
	 	 		 		 			 Checker = true; //Roll again (Loop)
	 	 		 		 		 	 }
	 	 		 		 	 }  //end of while loop
	 	 		 	 //Save dice Value "point"
			 	 } //end of switch





			 //end of switch

			cout << " You have $" << Wallet << " left in your wallet." << endl;
	 		cout << "Continue? (y or n)" << endl; //Request to continue?
	 		cin >> Continue;
	 			if (Continue == 'n' || Continue == 'N')
	 			{
	 			cout << "Program Ended" << endl;
	 			exit (0);
	 			}

	 }//end of while loop

	return 0;
} //end of main.
