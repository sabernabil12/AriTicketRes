#ifndef PLANE_H
#define PLANE_H
#include <string>
#include <vector>
#include "Seat.h"
#include "user.h"

class Plane

{
public:

	static Plane* I();
	Seat fc_seats[4][4];
	Seat ec_seats[30][6];

	std::vector<user> list;
	user* passenger;


protected:
	Plane();
	~Plane();

private:

	static Plane* Iptr;
};
#endif;
