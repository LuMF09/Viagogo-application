/*
Author: Lucien MAMAN
Date: 23/06/2017
*/
#include "Event.h"

Event::Event(int id, std::vector<Ticket>tickets) :id(id), listOfTickets(tickets){}

int Event::getId(){
	return id;
}

std::vector<Ticket> Event::getListTickets(){
	return listOfTickets;
}