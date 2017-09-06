#pragma once
class ResInterface
{
public:
	ResInterface();

	virtual bool makeReservation(void) = 0;
	virtual bool cancelReservation(void) = 0;

	virtual ~ResInterface();

};
