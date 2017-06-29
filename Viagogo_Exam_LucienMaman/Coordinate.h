/*
* \file Coordinate.h
* \author Lucien MAMAN
* \date 26/06/2017
* \brief Class Coordinate
*/
#ifndef HEADER_COORDINATE
#define HEADER_COORDINATE

#include "Event.h"
#include<vector>
#include <exception>

class Coordinate
{
protected:
	double x;
	double y;
	double manhattanDistanceFromUser;
	std::vector<Event>listOfEvents;

public:
	Coordinate();
	Coordinate(double x, double y);
	double getX();
	double getY();
	Event getEvent();
	double getDistance();

	void setEvent(Event e);
	void setCoordinate(double a, double b);
	void setDistance(double dist);
};
#endif