#pragma once
#include <vector>
#include <map>

typedef std::map<std::string, std::string> dict;

class Database{
	public:
		Database();

		// get latest external orders
		void updateOrders(std::vector<dict> newOrders);
		// update external order list
		std::vector<dict> retrieveOrders();

	private:
		const static double Version;	

		// vector containing all orders
		// you check this vector to update
		// and update vector when updating
		std::vector<dict> backendCheck;
};





