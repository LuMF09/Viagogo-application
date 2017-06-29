/*!
* \file Ticket.h
* \author Lucien MAMAN
* \date 26/06/2017
* \brief Class Ticket
*/
#ifndef HEADER_TICKET
#define HEADER_TICKET

class Ticket
{
protected:
	double price;/*Price of the ticket*/

public:

	Ticket(double price);

	double getPrice();
	void setPrice(double p);

};
#endif