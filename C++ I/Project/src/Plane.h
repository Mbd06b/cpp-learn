/*
 * Plane.h
 *
 *  Created on: Nov 9, 2015
 *      Author: mbd06b
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Party.h"

//note, when creating your variables, list your larger data-types First. Pointer > Int. Like Short > Char.
//this helps you to save memory that might be lost between storing variables in odd & even locations.


struct Plane {

	Party * Parties; //pointer to the parties, (Max here can be # of seats)
					//pointer because this number can be any combination possible.
					//this is broader
	Planes FlightNum;

	char * PlaneName;
	int NumSeats;
	int NumEmpty;
	int NumParties; //keeps track of how many parties are on the plane.
	int MaxParties;

};


#endif /* PLANE_H_ */
