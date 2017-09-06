#include "user.h"
#include <string>

user::user()
{
	name = "";
	seat_row = 0;
	seat_isle = 0;
}

void user::set_name(std::string n)
{
	name = n;
}
std::string user::get_name(void)
{
	return name;
}

void user::set_seat_row(int r)
{
	seat_row = r;

}
int user::get_seat_row(void)
{
	return seat_row;
}
void user::set_seat_isle(int i)
{
	seat_isle = i;
}
int user::get_seat_isle(void)
{
	return seat_isle;
}
user::~user()
{
}
