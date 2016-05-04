

#include "Plane.h"
#include "ReadString.h"

char * PlaneNames [NumPlanes] =
{
		"Alpha",
		"Bravo"
};

Planes GetPlane ()
{
	char * Name;
	int	i;

	Name = ReadString();
	for (i = PlaneAlpha; i < NumPlanes; i = (Planes) (i+1))
	{
		if (strcasecmp (Name, PlaneNames [i]) == 0) //  _strcmpi is strcmp "case insensitive"
		{

			delete [] Name;
			return i;
		}
		else;
		{

		delete [] Name;
		return InvalidPlane;
}
