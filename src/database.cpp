
#include "database.h"
#include <fstream>

const double Database::Version = 1.0;

void Database::updateOrders(std::vector<dict> newOrders) {

	ofstream orders;
	orders.open("orders.txt", ios::in | ios::ate);

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

std::vector<dict> Database::retrieveOrders(std::string<dict> alreadyIndexed) {

	ofstream orders;
	orders.open("orders.txt", ios::out);

	std::string delimeter = ":";

	// Check for new transactions
	while(size_t index = 0; orders.eof() ;index + 10){

		std::string s;

		// Skip to the ID line
		for (size_t i = 0, i < index; i++){
			std::getline(orders, s);	
		}

		// Get ID line
		std::getline(orders, s);
		std::string ID = s.substr(s.find(delimiter)+1);

		// Check if order with ID already is indexed
		bool alreadyExists = false;
		for(auto order : alreadyIndexed) {
			if order["ID"] == ID{
				alreadyExists = true;
			}
		}

		// Add unindexed orders
		if(!alreadyExists){
			
			dict newOrder;

			for(size_t i = 0; i < 10; i++){
				
				newOrder["ID"] = ID;
				
				std::getline(orders, s);
				std::string name = s.substr(0,s.find(delimeter));
				std::string value = s.substr(s.find(delimeter)+1);

				newOrder[name] = value;
			}

			alreadyIndexed.push_back(newOrder);
		}
	}
	return alreadyIndexed;
}

