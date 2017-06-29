/*
* \file Event.h
* \author Lucien MAMAN
* \date 26/06/2017
* \brief Class Event
*/
#ifndef HEADER_EVENT
#define HEADER_EVENT

#include "Ticket.h"
#include<vector>

class Event
{
protected:
	int id;/*Unique Id of the event*/
	std::vector<Ticket>listOfTickets;/*List of all the tickets of the event*/

public:

	Event(int id, std::vector<Ticket>tickets);

	int getId();
	std::vector<Ticket> getListTickets();
};
#endif