/*
Author: Lucien MAMAN
Date: 23/06/2017
*/
#include "Ticket.h"

Ticket::Ticket(double price) : price(price){}

double Ticket::getPrice(){
	return price;
}

void Ticket::setPrice(double p){
	price = p;
}