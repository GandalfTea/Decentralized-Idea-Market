#include <string>
#include "database.h"
#include <fstream>
#include <iostream>

const double Database::Version = 1.0;

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
std::vector<dict> Database::retrieveOrders(std::vector<dict> alreadyIndexed) {

	std::ifstream orders("orders.txt");

	std::string delimeter = ":";
	bool inOrder = false;		// keep track of position
	bool alreadyExists = false;	// if order already indexed
	dict newOrder;			// order to write and push

	std::string s;			// write the current string to it
	size_t a;			
	
	while(getline(orders, s)){
	
		static size_t index = 0;

		if(index % 10 == 0) {
			
			inOrder = true;

			// Get ID line and check if already indexed.
			std::string ID = s.substr(s.find(delimeter)+1);
			for(auto order : alreadyIndexed) {
				if(order["ID"] == ID){
					alreadyExists = true;
				} else {
					newOrder["ID"] = ID;
				}
			}
		}
		
		// Keep track of index in order to know how many
		// lines it has to read to get the whole order.
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
				
				alreadyIndexed.push_back(newOrder);
				newOrder.clear();

				alreadyExists = false;
				inOrder = false;
			}
		}
		++index;
	}
	return alreadyIndexed;
}

