#pragma once
#include <string>
class user
{
public:
	user();
	void set_name(std::string n);
	std::string get_name(void);
	void set_seat_row(int r);
	int get_seat_row(void);
	void set_seat_isle(int i);
	int get_seat_isle(void);
	virtual ~user();
private:
	std::string name;
	int seat_row;
	int seat_isle;

};
