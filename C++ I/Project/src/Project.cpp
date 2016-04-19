//============================================================================
// DESCRIPTION : Airline Project
// CLASS       : COSC 1436.S01
// AUTHOR      : Matthew Dowell
// DATE        : 12/02/2015
//============================================================================

#include <iostream>
using namespace std;

#include "Party.h"
#include "ReadInt.h"
#include "ReadString.h"
#include "Plane.h"
#include "Commands.h"

void InitPlane (Plane &, int, char *, Planes); // prototype  '&' allows us to pass the STRUCTURE itself to change it. Rather than a single value.
void Display (Plane &);
void FlyPlane (Plane &);
void LoungeLoad(Plane & P, Plane & L, Planes);


int main() {


	Plane Lounge;
	Plane Alpha;
	Plane Bravo;
	Planes Which;

	Party party;
	Party tooBigParty;
	Plane plane;
	Plane tempLounge; //place to que parties that should go to the front of the line.
	int selection;


	const int PlanesArraySize = NumPlanes;
	Plane PlanesArray [PlanesArraySize];

	int Size;

	bool ShutdownDetected = false;
	bool KeepFlying = true;

	bool FullDetected = false; // For testing automatic triggers.




cout << "Tree Top TICKE.TRON ACTIVATED... " << endl;

cout << "Commands are: Alpha, Bravo, and Lounge (To change seating size)" << endl;;
cout << "Arrive, Fly, Display, and Shutdown." << endl;

cout << "Initial Values have been set: " << endl;
//Initially, the ticket system will determine the number of seats

Size = 5;
InitPlane (Alpha, Size, "Alpha", PlaneAlpha);
PlanesArray[PlaneAlpha] = Alpha;

Size = 10;
InitPlane (Bravo, Size, "Bravo", PlaneBravo);
PlanesArray[PlaneBravo] = Bravo;

Size = 20;
InitPlane (Lounge, Size, "Lounge", InvalidPlane);
cout << endl;

Display(Alpha);
Display(Bravo);
Display(Lounge);

do{
cout << "Input Command >";
	//Switch to handle the questions (Which Plane, Which Party, Which
	switch (GetCommand()){
		case CmdAlpha:
			cout << "Enter Plane Alpha Seating Size> ";
			Size = ReadInt ();
			InitPlane (Alpha, Size, "Alpha", PlaneAlpha);
							/*  REPLACED BY INIT PLANE FUNCTIONS
								Alpha.NumSeats = Size;
								Alpha.NumEmpty = Size; //first time I show up, all the seats are empty.
								Alpha.NumParties = 0;
								Alpha.Parties =  new Party [Size]; //dynamic array of parties, maximum number of parties we can have is "Size".
								*/
			cout << endl;
			cout << "Alpha now has: ";
			Display(Alpha);
			PlanesArray[PlaneAlpha] = Alpha;

			break;
		case CmdBravo:
			cout << "Enter Bravo Seating Size> ";
					Size = ReadInt ();
					InitPlane (Bravo,  Size, "Bravo", PlaneBravo);
					cout << endl;
					cout << "Bravo now has: ";
					Display(Bravo);
					PlanesArray[PlaneBravo] = Bravo;

						break;
		case CmdLounge:
			cout << "Enter Lounge Seating Size> ";
					Size = ReadInt ();
					InitPlane (Lounge,  Size, "Lounge", InvalidPlane);
					cout << endl;
					cout << "Lounge now has: ";
					Display(Lounge);
						break;
		case CmdFly:
				cout << "Which Plane do you want to fly? >";
				Which = GetPlane (); //Get which plane we are flying
				FlyPlane (PlanesArray [Which]);
				LoungeLoad(PlanesArray [Which], Lounge, PlanesArray[Which].FlightNum);


				//Loop that flies that plane
					//Print names of all parties on board
					//Delete the names of each party on board free up our dynamic memory. (delete [] ?Array)
					//Set number of parties on plane to 0
					//Set number of empty seats on to max value (NumSeats) of plane.


				break;
		case CmdArrive:

				cout << "Which Plane do you want to board? >";
				do{
					Which = GetPlane (); //assigns party to plane (identified in array because it's difficult to target a single struct entity.
					if (Which == -1){
						cout << "Invalid Plane, try again. >" << endl;
						}else;
					}while(Which == -1);

				party.ArrivalPlane = Which; //assign party to arrival plane.


				cout << "How Many in your Party?";
				do{
					party.Size = ReadInt (); //assigning how big our party, party is the struct variable as defined in plane.h
					if (party.Size == 0){
					cout << "Enter Valid Party Size. >" << endl;
					}
				}while(party.Size == 0);


				cout << "Enter Party Name >";
				do{
					party.Name = ReadString ();//assigning our party name
					if (*party.Name =='\0'){
					cout << "Enter Valid Party Name. >" << endl;
					}
				}while(*party.Name =='\0');


				plane = PlanesArray [Which]; //assigning plane struct, the Plane(Alpha/Bravo) we are loading
											//this allows us to continue values assignment in the correct location.
				cout << endl;
				cout << "Party Name is: " << party.Name << " Size: " << party.Size << endl;
				cout << endl;

					if (plane.NumSeats < party.Size){
//------------------ 3) If Plane Requested is too small to hold the entire party, party is rejected - msg printed ----------
					cout << "Your Party is larger than the plane can hold, please re-register in smaller parties" << endl;
					}
					else if(plane.NumEmpty >= party.Size){
	//------------------- 1) Party is Seated on Requested Plane - msg printed --------------------------

						plane.Parties [plane.NumParties] = party; //However many parties are on (ex:Bravo already,  assign our party struct to the plane Parties * array
						plane.NumParties++; //add one to NumParties, so if another is assigned it goes to the target location.
						plane.NumEmpty = plane.NumEmpty - party.Size; //seats are now taken.
						PlanesArray [Which] = plane;
						cout << "Please board " << plane.PlaneName << ", your flight will take off momentarily." << endl;
						Display (plane);
						}

					else if (Lounge.NumEmpty >= party.Size){
	//---------------------2) If Plane Selected is full, party is directed to wait in lounge (if room) - msg printed
						plane = Lounge; //Lounge becomes the target for the party.
						plane.Parties [plane.NumParties] = party; //However many parties are on (ex:Bravo already,  assign our party struct to the plane Parties * array
						plane.NumParties++; //add one to NumParties, so if another is assigned it goes to the target location.
						plane.NumEmpty = plane.NumEmpty - party.Size; //lounge seats are now taken.
						cout << "The Plane cannot accommodate your party at this time," << endl;
						cout << "please feel free to enjoy our lounge facilities, you will be re-booked on a later flight." << endl;
						cout << "There are now " << plane.NumEmpty << " available spaces in the Lounge." << endl;
						Lounge = plane;
						}
					else
						{
	//-------------------- 3) If there is no room on the plane, and no room in the Lounge Either - msg printed sending away-------
							cout << "Thank You, Come again. There is not enough room on the plane or the lounge to accommodate your party at this time." << endl;
						}

				break;

		case CmdDisplay:
					cout << "Which Plane would you like to display?>";
					switch (GetPlane()){
					case PlaneAlpha: Display (Alpha);
						break;
					case PlaneBravo: Display(Bravo);
						break;
					case InvalidPlane: Display(Lounge);
						break;
					}



			break;
		case CmdShutdown:

			cout << "SHUTDOWN SEQUENCE TRIGGERED" << endl;

				// as long as people are on the plane (even if not full) or in the lounge
				// keep flying the plane as we did with the fly command
					// after everything is done flying and such, delete the array of parties for each plane.
					// delete [] Party;

			ShutdownDetected = true;

			break;
		case CmdInvalid:
					cout << "Invalid Command, try again" << endl;
					break;



		default:
				cout << "Internal error #1, contact customer support" << endl; //this is a common error message that people should never see
		}


/*------------6) Auto Commands If a plane is Full, Fly Plane, and Move Passengers in Lounge onto empty Plan-----------
			  8) upon the return of the plane the system will move people from the lounge to the plane in the order in which the parties
			  	 arrived, but will skip parties that cannot fit and search for those which can fit. - PartyNames printed.
*/


do{
    int i = 0;
	for (i = 0; i < PlanesArraySize; i++){ //for Loop to check all planes.

			if (FullDetected == true)
			{
				//cout << "TOPFULL DETECTED TRUE DETECTOR" << endl;
			i--;
			}
			else;

		if ((PlanesArray[i].NumEmpty == 0) || (FullDetected == true)){ //THE PLANE IS FULL FLY!

		/*	cout << endl;
			cout << endl;
			cout << "i before fly is: " << i << endl;
		*/

			FlyPlane (PlanesArray [i]);
		//	cout << "i after fly before load is: " << i << endl;
			LoungeLoad(PlanesArray [i], Lounge, PlanesArray[i].FlightNum);
		//	cout << "i after LoadLounge is: " << i << endl;


			if (PlanesArray[i].NumEmpty == 0){ //THE PLANE IS FULL FLY!
				FullDetected = true;
		//		cout << "FullDetected i is: " << i << endl;
				}
			else{
				FullDetected = false;
		//		cout << "NOT FULLDetected i is:" << i << endl;
				}
			}else; //does nothing, just the end of our plane full if statement.

		}

//cout << "End of do loop i is: " << i << endl;

}while(FullDetected);



cout << endl;
}while (!ShutdownDetected);

cout << endl;
cout << "SYSTEM IS SHUTTING DOWN";
cout << endl;

//SHUTDOWN DETECTED

	do{
		for (int i = 0; i < PlanesArraySize; i++){ //for Loop to check all planes.


			if((PlanesArray[i].NumEmpty != PlanesArray[i].NumSeats) || (Lounge.NumEmpty != Lounge.NumSeats)){

				FlyPlane (PlanesArray [i]);
				LoungeLoad(PlanesArray [i], Lounge, PlanesArray[i].FlightNum);
				}
				else{
				KeepFlying = false;
				}

			}
		}while(KeepFlying);//Done Flying

cout << endl;
cout << "ATTEMPTING TO DELETE DYNAMIC MEMORY";
cout << endl;

		for (int i = 0; i < PlanesArraySize; i++){ //for Loop to check all planes.

			cout << "ABOUT TO DELETE PlanesArray[i}.Parties" << endl;
			 delete [] PlanesArray[i].Parties;
			}


cout << endl;
cout << "SYSTEM HAS SHUTDOWN";

	return 0;
}





void InitPlane (Plane & P, int Size, char * PlaneNames, Planes FlightNum){   //& we are passing by reference because we want to change things. Allows us to pass the STRUCTURE itself.
				P.FlightNum = FlightNum;
				P.PlaneName = PlaneNames;
				P.NumSeats = Size;
				P.NumEmpty = Size; //first time I show up, all the seats are empty.
				P.NumParties = 0;
				P.Parties =  new Party [Size]; //dynamic array of parties, maximum number of parties we can have is "Size".
				P.MaxParties = Size;

}


void Display (Plane & P){
	cout << P.PlaneName << ": ";
	cout << "  Seats: " << P.NumSeats;
	cout << "  Empty Seats: " << P.NumEmpty;
	cout << "  Parties Booked: " << P.NumParties << endl;

}

void FlyPlane(Plane & P){


			cout << endl;
			cout << P.PlaneName << " FLEW!" << endl;
			cout << endl;


			cout << "Parties OnBoard: " << endl;
	for (int i = 0; i < P.NumParties; i++){ //prints for the number of parties on the plane.
					cout << P.Parties [i].Name << endl; //print the party name.
		}

				//takes the existing plane and copies basic values..

				delete [] P.Parties; // Clears the Dynamic Memory Array for Parties struct.
				InitPlane (P, P.NumSeats, P.PlaneName, P.FlightNum); //Reinitializes that from scratch.

			cout << endl;
			cout << "A fresh plane has landed and is ready to board!" << endl;
			Display (P);
}


void LoungeLoad(Plane & P, Plane & L, Planes FlightNum){ //LoungeLoad(Plane,Lounge, Plane-to-Load)

	Plane tempLounge;


	tempLounge.NumSeats = L.NumSeats;
	tempLounge.NumEmpty = L.NumSeats; //first time I show up, all the seats are empty.
	tempLounge.NumParties = 0;
	tempLounge.Parties =  new Party [L.NumSeats]; //dynamic array of parties, maximum number of parties we can have is "Size".
	tempLounge.MaxParties = L.NumSeats;

	int i;
	int j = 0;


	for (i = 0; i < L.NumParties; i++){ //checks every party in the lounge

		if ((L.Parties[i].ArrivalPlane == FlightNum) && (L.Parties[i].Size <= P.NumEmpty)){ //if the Party in Lounge, want to board the now empty plane...
			P.Parties [P.NumParties] = L.Parties[i]; //Starts at 0, from FlyFunc prior , because planes are only loaded after (ex:Bravo already,  assign our party struct to the plane Parties * array
			P.NumParties++; //add one to NumParties, so if another is assigned it goes to the target location.
			P.NumEmpty = P.NumEmpty - L.Parties[i].Size; //seats are now taken.
			cout << L.Parties[i].Name << " Has Boarded " << P.PlaneName << " from Lounge"<< endl; //print Party name
			}
		else{
			tempLounge.Parties [j] = L.Parties [i];//assign to first location in priority que.
			tempLounge.NumParties++; //increase the number of parties.
			tempLounge.NumEmpty = tempLounge.NumEmpty - tempLounge.Parties[j].Size; //reduce the number of avaliable seats.
			j++; // we've assigned someone in the slot, go to next slot in tempLounge.


			if (L.Parties[i].ArrivalPlane == FlightNum){
				cout << L.Parties[i].Name << " - Party is too large to board " << P.PlaneName << " right now. You will be next to board from lounge."<< endl;
				cout << endl;
				}
			}
		}

	L = tempLounge; //The temp lounge now has all of our
	delete [] tempLounge.Parties;
}

