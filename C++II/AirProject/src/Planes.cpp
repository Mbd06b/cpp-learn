

#include "Plane.h"
#include "ReadString.h"
#include <string.h>
#include <iostream>
using namespace std;

char * PlaneNames [NumPlanes] =
{
		"Alpha",
		"Bravo",
};

Planes GetPlane ()
{
	char * Name;
	int	i;

	Name = ReadString();

	for (i = PlaneAlpha; i < NumPlanes; i = (Planes) (i+1))
	{
		if (strcmp (Name, PlaneNames [i]) == 0) //  _strcmpi is strcmp "case insensitive"
		{
			delete [] Name;
			return (Planes)i;
		}
		else;
		{
		}
	}
		delete [] Name;
		return InvalidPlane;


}



