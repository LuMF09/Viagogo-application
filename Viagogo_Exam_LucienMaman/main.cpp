/*
Author: Lucien MAMAN
Date: 23/06/2017
brief: Main of the project
*/

#include "Functions.h"
#include "Coordinate.h"
#include <iostream>
#include <algorithm>//to check
#include <string> 
#include <iomanip>

int const MAX_EVENT_TO_DISPLAY = 5;
std::string const NO_TICKET_MESSAGE("No ticket available");

int main()
{
	int numberOfEventToDisplay = 0;
	double cheapestTicket = -1;

	//Generation of random data
	std::vector<Coordinate>listOfCoordinates=Functions::generateRandomData();  

	//Ask correct inputs to the user
	Coordinate inputUser = Functions::askCorrectInputs();
	std::cout << std::endl << "Closest Events to (" << inputUser.getX() << "," << inputUser.getY() << "):"<<std::endl<<std::endl;
	
	try{
		//Calculate the Manhattan distance for each coordinate containing an event from the user coordinates
		for (int i = 0; i < listOfCoordinates.size(); i++){
			listOfCoordinates.at(i).setDistance(Functions::manhattanDistance(inputUser, listOfCoordinates.at(i)));
		}

		//Sort the list of coordinates by distances
		std::sort(listOfCoordinates.begin(), listOfCoordinates.end(), Functions::sortByDistance);

		//Define the number of evenement to display
		if (listOfCoordinates.size()>MAX_EVENT_TO_DISPLAY){
			numberOfEventToDisplay = MAX_EVENT_TO_DISPLAY;
		}
		else numberOfEventToDisplay = listOfCoordinates.size();

		for (int i = 0; i < numberOfEventToDisplay; i++){

			//Sort the tickets of each event by price ONLY if there are tickets, otherwise NO_TICKET_MESSAGE displayed
			if (listOfCoordinates.at(i).getEvent().getListTickets().size() != 0){
				cheapestTicket = listOfCoordinates.at(i).getEvent().getListTickets()[0].getPrice();
			}


			//Display results
			std::cout << std::fixed << std::setprecision(2) << "Event " << listOfCoordinates.at(i).getEvent().getId() << " - ";
			//If no ticket available
			if (cheapestTicket == -1){
				std::cout << NO_TICKET_MESSAGE;
			}
			else{
				std::cout << "$" << cheapestTicket;
			}
			std::cout << ", Distance " << listOfCoordinates.at(i).getDistance() << std::endl;
		}
		std::cout << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << "ERROR : " << e.what() << std::endl;
	}
	std::cout << "Simulation finished, press ENTER to close the window.";
	std::cin.clear();
	std::cin.ignore(2);
	return 0;
}