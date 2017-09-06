#pragma once
#include "ResInterface.h"
#include "Plane.h"

class ReservationServer : public ResInterface
{
public:
	static ReservationServer* instance();

	bool makeReservation(void);
	bool cancelReservation(void);

private:
	ReservationServer();
	virtual ~ReservationServer();

	static ReservationServer* m_instance;
	Plane* plane_seats;
};
