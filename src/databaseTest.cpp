#include "database.h"
#include "order.cpp"
#include <iostream>

int main(){

	dict a = createOrder("00000001", "GME", "321.45", "6", "0",
			"26/03", "ASAP");

	std::vector<dict> orders;
	std::vector<dict> updatedOrders;

	Database database;

	orders.push_back(a);
	
	database.updateOrders(orders);
	updatedOrders = database.retrieveOrders(updatedOrders);

	std::cout << "\nSIZE OF VECTOR : " << updatedOrders.size() << std::endl << std::endl;
	for(auto order : updatedOrders){
		for(auto pair : order){
			std::cout << pair.first << " : " << pair.second << std::endl;
		}
	}

	return 0;
}



