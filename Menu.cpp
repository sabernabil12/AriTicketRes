#include <iostream>
#include "Menu.h"
#include "ReservationServer.h"
#include "ResInterface.h"

using namespace std;

namespace CSC300
{


	Menu::Menu()
	{

	}


	Menu::~Menu()
	{

	}

	void
		Menu::displayMenu(void)
	{
			std::cout << "\nYour options are:" << endl;
			std::cout << "Make Reservation   - 1" << endl;
			std::cout << "Change Reservation - 2" << endl;
			std::cout << "Cancel Reservation - 3" << endl;
			std::cout << "View Reservation   - 4" << endl;
			std::cout << "Exit System        - 10" << endl;

			std::cout << "\nMake selection: ";
		}

	// overloaded istream cin style operator
	// used to read in choice_t types
	// istream_type (cin) >> choice_t type (m_choice)
	std::istream& operator>>(std::istream& strm, CSC300::choice_t& c)
	{
		int x;
		strm >> x;
		c = static_cast<choice_t>(x);
		return strm;
	}


	void
		Menu::getUserSelection(void)
	{
			while (1)
			{
				std::cin >> m_choice;
				if (cin.fail()) // oops we got junk in the stream - not expecting ...
				{
					// clear out all junk and rewind stream to read afresh
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "try again: ";
					continue;
				}
				else
				{
					break;
				}
			}
		}

	void
		Menu::displayUserSelection(void)
	{
			std::cout << "You selected :" << m_choice << endl << endl;
		}

	bool
		Menu::validateUserSelection()
	{

			if (m_choice >= 1 && m_choice <= 4)
				return true;
			else
				return false;

		}

	void
		Menu::run(void)
	{
			do{

				displayMenu();
				getUserSelection();

				// user wants to terminate
				if (m_choice == EXIT)
				{
					cout << "Shutting down system" << endl;
					break;
				}

				// user typed in junk
				if (!validateUserSelection())
				{
					cout << "Invalid selection - try again" << endl;
					continue;
				}
				else // user input was good
				{
					displayUserSelection();
					dispatchWork(); // do what user asked
				}

			} while (1);
		}

	void Menu::dispatchWork(void)
	{
		switch (m_choice)
		{
		case MAKE_RES:
			// do something by invoking methods on reservation server
			cout << "you selected MAKE RESERVATION" << endl;
			ReservationServer::instance()->makeReservation();
			//alternate
			&ResInterface::makeReservation;
			break;

		case CHANGE_RES:
			cout << "you selected Change RESERVATION" << endl;
			ReservationServer::instance()->cancelReservation();

			break;

		case CANCEL_RES:
			cout << "you selected Change RESERVATION" << endl;
			ReservationServer::instance()->cancelReservation();

			break;

		case VIEW_RES:

			break;

		default:

			break;
		}
	}


}
