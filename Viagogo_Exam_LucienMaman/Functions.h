/*!
* \file Functions.h
* \author Lucien MAMAN
* \date 23/06/2017
* \brief Independent functions used in the program
*/
#ifndef HEADER_FUNCTIONS
#define HEADER_FUNCTIONS

#include <random>
#include "Coordinate.h"

class Functions
{
public:
	static double randomDouble(double min, double max);
	static bool isUnique(std::vector<Coordinate> listOfCoordinates, Coordinate set);/*Test the uniqueness of a coordinate*/
	static std::vector<Coordinate> generateRandomData();/*Generate random data used for the simulation*/
	static double manhattanDistance(Coordinate set1, Coordinate set2);/*Compute the Manhattan distance beetween 2points */
	static Coordinate askCorrectInputs();/*Ask and force the user to enter correct values*/
	static bool sortByDistance(Coordinate &set1, Coordinate &set2) { return set1.getDistance() < set2.getDistance(); }/*Funtion used to sort the events by distance*/
};
#endif