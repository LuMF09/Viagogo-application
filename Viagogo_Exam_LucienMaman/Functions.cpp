/*
Author: Lucien MAMAN
Date: 23/06/2017
*/

#include "Functions.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include <time.h>

double const X_LEFT_BOUNDARY(-10.00), X_RIGHT_BOUNDARY(10.00), Y_BOTTOM_BOUNDARY(-10.00), Y_TOP_BOUNDARY(10.00), MIN_PRICE_TICKET(20.00), MAX_PRICE_TICKET(275);
int const NB_MAX_EVENT(150),NB_MAX_TICKETS(38000);

double Functions::randomDouble(double min, double max)
{
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

std::vector<Coordinate> Functions::generateRandomData(){
	std::vector<Coordinate>listOfCoordinates;//List of all the coordinates containing an event
	srand(time(NULL));
	
	//Number of event in the map
	int nbCoordinateWithEvent = std::rand() % (NB_MAX_EVENT) + 1;
	std::cout << "This simulation is running with " << nbCoordinateWithEvent << " events dispatched on the map." << std::endl << std::endl;

	//Create a random Coordinate to host an event
	for (int i = 0; i < nbCoordinateWithEvent; i++){

		double x = Functions::randomDouble(X_LEFT_BOUNDARY, X_RIGHT_BOUNDARY);
		double y = Functions::randomDouble(Y_BOTTOM_BOUNDARY, Y_TOP_BOUNDARY);
		Coordinate set(x, y);
		//Test of the uniqueness of the new coordinate
		if (Functions::isUnique(listOfCoordinates, set)){
			std::vector<Ticket>listOfTicket;
			//Number of ticket for this particular event
			int nbTicket = std::rand() % (NB_MAX_TICKETS+1);

			for (int j = 0; j < nbTicket; j++){
				//Create a ticket with a price between min and max prices defined at the top of the file
				Ticket ticket(Functions::randomDouble(MIN_PRICE_TICKET, MAX_PRICE_TICKET));
				//Put the less expensive ticket at the beginning of the list
				if (j != 0 && ticket.getPrice()<listOfTicket[0].getPrice()){
					listOfTicket.insert(listOfTicket.begin(), ticket);
				}
				else {
					listOfTicket.push_back(ticket);
				}
				
			}
			//Create the event with an unique Id and its number of tickets
			Event event(i, listOfTicket);
			//Assign the event to the coordinate
			set.setEvent(event);
			
			//Add the coordinate to the list of all  the coordinates containing an event
			listOfCoordinates.push_back(set);
			
		}
	}
	return listOfCoordinates;
}

bool Functions::isUnique(std::vector<Coordinate> listOfCoordinates, Coordinate set){
	for (int i = 0; i < listOfCoordinates.size(); i++){
		if (listOfCoordinates[i].getX() == set.getX() && listOfCoordinates[i].getY() == set.getY()){
			return false;
		}
	}
	//True if we can not find a specific coordinate in a vector of coordinates
	return true;
}

double Functions::manhattanDistance(Coordinate set1, Coordinate set2){
	return std::abs(set1.getX() - set2.getX()) + std::abs(set1.getY() - set2.getY());
}

Coordinate Functions::askCorrectInputs(){
	
	std::string userAnswer = "";	
	double xUser = -11;
	double yUser = -11;

	std::cout << "Please input your Coordinates as follow : x,y"<<std::endl;
	std::cin >> userAnswer;
	std::cout << std::endl;

	//test if correct format: x,y
	bool comaFound = (userAnswer.find_first_of(',') != std::string::npos);
	//Test if x and y are doubles and not empty
	bool xIsDouble = (userAnswer.substr(0, userAnswer.find(',')).find_first_not_of("0123456789.-") == std::string::npos && userAnswer.substr(0, userAnswer.find(','))!="");
	bool yIsDouble = (userAnswer.substr(userAnswer.find(',') + 1).find_first_not_of("0123456789.-") == std::string::npos && userAnswer.substr(userAnswer.find(',') + 1)!="");

	if (comaFound && xIsDouble && yIsDouble){
		xUser = std::stod(userAnswer.substr(0, userAnswer.find(userAnswer, ',')));
		yUser = std::stod(userAnswer.substr(userAnswer.find(',') + 1));
	}

	//Test if the user input is in the correct format and not out of bonds
	while (!comaFound || xUser<X_LEFT_BOUNDARY || xUser>X_RIGHT_BOUNDARY || yUser<Y_BOTTOM_BOUNDARY || yUser>Y_TOP_BOUNDARY){
		std::cout << "Input error!" << std::endl<<"Please choose a correct input for your Coordinates following this format: x, y"<<std::endl;
		std::cin >> userAnswer;
		std::cout << std::endl;

		//Redo all the tests to check the new answer
		comaFound = (userAnswer.find_first_of(',') != std::string::npos);
		xIsDouble = (userAnswer.substr(0, userAnswer.find(',')).find_first_not_of("0123456789.") == std::string::npos);
		yIsDouble = (userAnswer.substr(userAnswer.find(',') + 1).find_first_not_of("0123456789.") == std::string::npos);

		if (comaFound && xIsDouble && yIsDouble){
			xUser = std::stod(userAnswer.substr(0, userAnswer.find(userAnswer, ',')));
			yUser = std::stod(userAnswer.substr(userAnswer.find(',') + 1));
		}
	}
	//Coordinates are corrects
	Coordinate inputUser(xUser, yUser);
	return inputUser;
}