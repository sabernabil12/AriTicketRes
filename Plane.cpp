#include "Plane.h"
#include "user.h"

Plane::Plane()
{
	{
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				fc_seats[i][j].seat.push_back(char(65 + j));
			}
		}
		for (size_t i = 0; i < 30; i++)
		{
			for (size_t j = 0; j < 6; j++)
			{
				ec_seats[i][j].seat.push_back(char(65 + j));
			}
		}
	}

	passenger = new user;
}

Plane* Plane::Iptr = 0; // initializing to 0

Plane* Plane::I() // initializing 
{
	if (Iptr == 0) // checking if initialize already if true that means the object has not been created
	{
		Iptr = new Plane; // create the object
	}
	return Iptr; // return the pointer to the object 
}

Plane::~Plane()
{
}
