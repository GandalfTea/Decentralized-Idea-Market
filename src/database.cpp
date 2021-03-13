#include <string>
#include "database.h"
#include <fstream>
#include <iostream>

#include <chrono>
#include <ctime>


// Version of Database
const double Database::Version = 0.1;


void Database::createOrder( std::string userAddress,
		  std::string Security,
		  std::string Price,
		  std::string Quantity,
		  std::string orderType,
		  std::string Expiration,
		  std::string Execution ) {

	/*
	   ORDERS SHOULD CONTAIN:
	 
	 * ID (automatic)
	 * ADDRESS of user: Public key. (automatic (not yet))
	 * TIMESTAMP of creation (automatic)
	 * SECURITY to exchange.
	 * PRICE of transaction. (empty in case of instant best price)
	 * QUANTITY of transaction (Volume)
	 * TYPE: 1 is buy, 0 is sell.
	 * EXPIRATION date: only Day.
	 * EXECUTION type: Immediate, TBD. 
	 * ? MONEY or SECURITY locked. 
	 
	 */

	// Get live time
	//auto time = std::chrono::system_clock::now();
	//std::time_t Time = std::chrono::system_clock::to_time_t(time);
	//std::string timeStamp = std::to_string(std::ctime(&Time));

	std::string timeStamp = "it does not fucking work. You get this instead: 8==D.";

	dict order;
	order["ID"] = orderID++;
	order["user"] = userAddress;
	order["time"] = timeStamp;
	order["security"] = Security;
	order["price"] = Price;
	order["quantity"] = Quantity;
	order["type"] = orderType;

	if(order["type"] == "1"){
		orderFlow.Buy.push_back(order);

	}else if (order["type"] == "0"){
		orderFlow.Sell.push_back(order);
	}

	return;
}


void Database::updateOrders(std::vector<dict> newOrders) {

	std::ofstream orders;
	orders.open("orders.txt", std::ios::in | std::ios::ate);

	for(auto order : newOrders){
		size_t lineIndex = 1;
		for(auto line : order){
			orders << line.first << ":" << line.second << "\n";
			lineIndex++;
		}	
		
		// pad to 10 lines
		while(lineIndex != 10){
			orders << ".\n";
			lineIndex++;
		}
	}
}


Flow Database::getOrders(){
	Flow temp = orderFlow;

	//temp solution to not repeat orders:
	orderFlow.Buy.clear();
	orderFlow.Sell.clear();

	return temp;
}

