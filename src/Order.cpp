#include "Order.h"
#include <iostream>
#include <vector>

using namespace std;

Order::Order(std::string user, 
      	     double time, 
      	     std::string security,
      	     double quantity, 
      	     double price, 
      	     size_t type, 
      	     std::string orderExecutionType)

	: Time(time), Security(security),
	  Quantity(quantity), Price(price), orderType(type),
	  orderExecution(orderExecutionType), ID(Order::orderID++)
{
	// Check if user exists
	// Check and lock required money or security.
}	

//Debug
void Order::printOrder() {
	std::cout << "\nOrder " << this->ID << " : {" << endl;
	std::cout << "\tUser : " << this->User << endl
		  << "\tSecurity : " << this->Security << endl
		  << "\tQuantity : " << this->Quantity << endl
		  << "\tTime : " << this->Time << endl
		  << "\tPrice : " << this->Price << endl
		  << "\tType : " << this->orderType << endl
		  << "\tExecution : " << this->orderExecution << endl 
		  << "}" << endl; 
}	

size_t Order::orderID = 0;

