//============================================================================
// Name        : (11-09).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Party.h"
#include "Plane.h"
#include "ReadInt.h"
#include "ReadString.h"
#include "Commands.h"

void InitPlane (Plane &, int); // prototype  '&' allwos us to pass the STRUCTURE itself to change it. Rather than a single value.



int main() {

	Plane Lounge;
	Plane Alpha;
	Plane Bravo;
	Planes Which;
	int Size;


	//Switch to handle the questions (Which Plane, Which Party, Which
	switch (GetCommand())
		{
		case CmdAlpha:
			Size = ReadInt ();
			InitPlane (Alpha,  Size);
							/*  REPLACED BY INIT PLANE FUNCTIONS
								Alpha.NumSeats = Size;
								Alpha.NumEmpty = Size; //first time I show up, all the seats are empty.
								Alpha.NumParties = 0;
								Alpha.Parties =  new Party [Size]; //dynamic array of paties, maximum number of parties we can have is "Size".
								*/
			break;
		case CmdBravo:
			Size = ReadInt ();
			InitPlane (Bravo, Size);

						break;
		case CmdLounge:
			Size = ReadInt ();
						Lounge.NumSeats = Size;
						Lounge.NumEmpty = Size; //first time I show up, all the seats are empty.
						Lounge.NumParties = 0;
						Lounge.Parties =  new Party [Size]; //dynamic array of paties, maximum number of parties we can have is "Size".

						break;
		case CmdFly:
				Which = GetPlane (); //Get which plane we are flying

				//Loop that flies that plane
					//Print names of all parties on board
					//Delete the names of each party on board free up our dynamic memory. (delete [] ?Array)
					//Set number of parties on plane to 0
					//Set number of empty seats on to max value (NumSeats) of plane.

					//NEXT INSTRUCTION - Move Parties from the Lounge to the Plane.
					//Only move parties that can fit into the number of available.
					// if party does not fit or wants the other plane, skip it
					// if the party fills up the plane, loop back and fly the plane again.

				break;
		case CmdArrive:
				Which = GetPlane ();
				Size = ReadString();
				// Get which plane, get party name, get size of party.
				//if party can never fit on plane
						// true - send party away
						// false - (party can fit)
						// 		Are there enough seats avaliable now?
					 	//				YES - copy party onto plane
						//						Update number of empty seats
						//					 is plane full?
						//							yes - Fly plane with fly command
						//							no -  nothing else to do, loop back for another command.
						//				NO - are there enough empty seats in the lounge?
						//							yes - add ptruearty to the lounge
						//							no - send party away
						//								delete the name of the party


		case CmdShutdown:
				// as long as people are on the plane (even if not full) or in the lounge
				// keep flying the plane as we did with the fly command
				// after everything is done flying and such, delete the array of parties for each plane.
					delete [] Party;

			break;
		case CmdInvalid:
					cout << "Invalid Command, try again" << endl;
					break;
		default:
				cout << "Internal error #1, contact customer support" << endl; //this is a common error message that people should never see
		}


	return 0;
}

void InitPlane (Plane & plane, int Size){   //& we are passing by reference because we want to change things. Allows us to pass the STRUCTURE itself.
				plane.NumSeats = Size;
				plane.NumEmpty = Size; //first time I show up, all the seats are empty.
				plane.NumParties = 0;
				plane.Parties =  new Party [Size]; //dynamic array of paties, maximum number of parties we can have is "Size".

}
