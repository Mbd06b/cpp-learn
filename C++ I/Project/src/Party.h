/*
 * Party.h
 *
 *  Created on: Nov 9, 2015
 *      Author: mbd06b
 */

#ifndef PARTY_H_
#define PARTY_H_

enum Planes {			//enum is good here because if the boss wants to buy another plane, we can just add it here,
			InvalidPlane = -1,		// it then becomes represented by name
			PlaneAlpha, //is 0
			PlaneBravo, // is 1

			NumPlanes
};

struct Party
	{
	char * Name; //dynamic array to put an unlimited size name using ReadString func.
	int	Size;	// how large the plane
	Planes ArrivalPlane;

	};


Planes GetPlane();




#endif /* PARTY_H_ */
