/*
Author: Lucien MAMAN
Date: 23/06/2017
Description
*/

#include "Coordinate.h"

double const X_LEFT_BOUNDARY(-10), Y_TOP_BOUNDARY(10);

Coordinate::Coordinate() : x(X_LEFT_BOUNDARY - 1), y(Y_TOP_BOUNDARY+1){}
Coordinate::Coordinate(double x, double y) : x(x), y(y){}

double Coordinate::getX(){
	return x;
}

double Coordinate::getY(){
	return y;
}

double Coordinate::getDistance(){
	return manhattanDistanceFromUser;
}
Event Coordinate::getEvent(){
	//throw an error if undefined or out of range
	return listOfEvents.at(0);
}

void Coordinate::setEvent(Event e){
	listOfEvents.push_back(e);
}

void Coordinate::setCoordinate(double a, double b){
	x = a;
	y = b;
}

void Coordinate::setDistance(double dist){
	manhattanDistanceFromUser = dist;
}
