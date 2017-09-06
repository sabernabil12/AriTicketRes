#include <iostream>
#include <string>
#include <sstream>
#include "ReservationServer.h"
#include "Seat.h"

ReservationServer*
ReservationServer::m_instance = 0;

ReservationServer*
ReservationServer::instance() {
	if (!m_instance)
		m_instance = new ReservationServer;
	return m_instance;}

ReservationServer::ReservationServer(){ }

bool ReservationServer::makeReservation(void) {
	plane_seats = Plane::I();
	using std::cout;
	using std::endl;

	// insert Plane code here?;

	cout << "current seats avalable First Class: " << endl;

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Row:" << i + 1 << " ";
		for (size_t j = 0; j < 4; j++)
		{
			std::string s = plane_seats->fc_seats[i][j].seat;
			cout << i + 1 << s << " ";
		}
		cout << endl;
	}
	cout << "current seats avalable economy: " << endl;
	for (size_t i = 0; i < 30; i++)
	{
		cout << "Row:" << i + 1 << " ";
		for (size_t j = 0; j < 6; j++)
		{
			std::string es = plane_seats->ec_seats[i][j].seat;
			cout << i + 1 << es << " ";
		}
		cout << endl;
	}

	cout << "seat selection for First Class enter F " << endl;
	cout << "Row 1-4, seat A-D , widow seats are A,D isle B,C " << endl;
	cout << "seat selection for economy enter E " << endl;
	cout << "Row 1-30, seat A-F , widow seats are A,F isle B,C " << endl;
	cout << "all upper case" << endl;
	cout << "enter your user name: ";
	std::string get_respence_passenger = "";
	std::cin >> get_respence_passenger;

	cout << "Enter economy or First Class E or F: " << endl;
	std::string get_respence_efc = "";
	std::cin >> get_respence_efc;
	cout << "Enter your seat selection row #: " << endl;
	int get_respence_row = 0;
	std::cin >> get_respence_row;
	cout << "Enter your seat selection isle letter: " << endl;
	std::string get_respence_isle = "";
	std::cin >> get_respence_isle;
	int efc = 0;
	efc = int(get_respence_efc[0]) - 65;
	int row = 0;
	row = get_respence_row - 1;
	int isle;
	isle = int(get_respence_isle[0]) - 65;
	if (row < 0)
	{
		cout << "there was an error in your selection please try again" << endl;
		return false;
	}
	if (row > 30)
	{
		cout << "there was an error in your selection please try again" << endl;
		return false;
	}
	if (isle < 0)
	{
		cout << "there was an error in your selection please try again" << endl;
		return false;
	}
	if (isle > 6)
	{
		cout << "there was an error in your selection please try again" << endl;
		return false;
	}
	if (efc == 5)
	{
		if (row >= 0)
		{
			if (row < 4)
			{
				if (isle >= 0)
				{
					if (isle < 4)
					{
						std::string s = plane_seats->fc_seats[row][isle].seat;
						if (s[0] == 'R')
						{
							cout << "that seat is already reserver" << endl;
							//return true;
						}
						else
						{
							plane_seats->fc_seats[row][isle].seat.pop_back();
							plane_seats->fc_seats[row][isle].seat.push_back('R');
						}
					}
					cout << "current seats avalable First Class: " << endl;
					for (size_t i = 0; i < 4; i++)
					{
						cout << "Row:" << i + 1 << " ";
						for (size_t j = 0; j < 4; j++)
						{
							std::string s = plane_seats->fc_seats[i][j].seat;
							cout << i + 1 << s << " ";
						}
						cout << endl;
					}
				}
			}
		}
	}
	if (efc == 4)
	{
		if (row >= 0)
		{
			if (row < 30)
			{
				if (isle >= 0)
				{
					if (isle < 6)
					{
						std::string s = plane_seats->ec_seats[row][isle].seat;
						if (s[0] == 'R')
						{
							cout << "that seat is already reserver" << endl;
							//return true;
						}
						else
						{
							plane_seats->ec_seats[row][isle].seat.pop_back();
							plane_seats->ec_seats[row][isle].seat.push_back('R');

							plane_seats->passenger->set_name(get_respence_passenger);

							plane_seats->passenger->set_seat_row(row);
							plane_seats->passenger->set_seat_row(isle);
							plane_seats->list.push_back(*plane_seats->passenger);
							//	list.push_back(*passenger);

						}
					}
					cout << "current First Class seats avalable: " << endl;
					for (size_t i = 0; i < 4; i++)
					{
						cout << "Row:" << i + 1 << " ";
						for (size_t j = 0; j < 4; j++)
						{
							std::string s = plane_seats->fc_seats[i][j].seat;
							cout << i + 1 << s << " ";
						}
						cout << endl;
					}
					cout << "current economy seats avalable: " << endl;
					for (size_t i = 0; i < 30; i++)
					{
						cout << "Row:" << i + 1 << " ";
						for (size_t j = 0; j < 6; j++)
						{
							std::string s = plane_seats->ec_seats[i][j].seat;
							cout << i + 1 << s << " ";
						}
						cout << endl;
					}
				}
			}
		}
	}
	cout << "ReservationServer::makeReservation called" << endl;
	return true;
}

bool ReservationServer::cancelReservation(void)
{
	std::cout << "enter your user name: ";
	std::string get_user_name = "";
	std::cin >> get_user_name;
	int length = plane_seats->list.size();
	for (size_t i = 0; i < length; i++)
	{
		std::string tmp = plane_seats->list[i].get_name();
		if (get_user_name == tmp)
		{
			int row = plane_seats->list[i].get_seat_row();
			int isle = plane_seats->list[i].get_seat_isle();
			plane_seats->ec_seats[row][isle].seat.pop_back();
		}

	}

	return true;
}


ReservationServer::~ReservationServer(){}
