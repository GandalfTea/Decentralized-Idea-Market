#include <string>
#include "database.h"
#include <fstream>
#include <iostream>

const double Database::Version = 0.1;

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


// RETURN : Vector argument, updated.
Flow Database::retrieveOrders() {

	std::ifstream orders("orders.txt");

	std::string delimeter = ":";
	bool inOrder = false;		// keep track of position
	bool alreadyExists = false;	// if order already indexed
	dict newOrder;			// order to write and push

	std::string s;			// write the current string to it
	size_t a;			
	
	while(getline(orders, s)){
	
		static size_t index = 0;

		// Orders are 10 lines long.
		if(index % 10 == 0) {
			
			inOrder = true;

			// Get ID line and check if already indexed.
			std::string ID = s.substr(s.find(delimeter)+1);
			for(auto order : orderFlow.Buy) {
				if(order["ID"] == ID){
					alreadyExists = true;
					break;
			}
			if(!alreadyExists) {
				for(auto order : orderFlow.Sell) {
					if(order["ID"] == ID){
						alreadyExists = true;
						break;
				}
			}
		}
		
		if(alreadyExists){
			inOrder = false;
			break;
		}else{
			// Push the ID in the new dict
			newOrder["ID"] = ID;
		}

		// Freeze index value when in order.
		if(!inOrder){
			a = index;
		}

		// Read and index order
		if(inOrder && !alreadyExists){
			
			if(index < a+8){
				
				std::string name = s.substr(0,s.find(delimeter));
				std::string value = s.substr(s.find(delimeter)+1);

				newOrder[name] = value;
			}
			
			if(index != 0 && index != 1 && index % 8 == 0){
				
				//Sell
				if(newOrder["type"] == 0){
					orderFlow.Sell.push_back(newOrder);

				// Buy		
				}else if(newOrder["type"] == 1){
					orderFlow.Buy.push_back(newOrder);
				}

				newOrder.clear();

				alreadyExists = false;
				inOrder = false;
			}
		}
		++index;
	}
	return Database::orderFlow;
}

