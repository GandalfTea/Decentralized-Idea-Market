#pragma once
#include <vector>
#include <map>

typedef std::map<std::string, std::string> dict;

class Database{
	public:
		Database() = default;

		// get latest external orders
		void updateOrders(std::vector<dict> newOrders);
		// update external order list
		std::vector<dict> retrieveOrders(std::vector<dict> alreadyIndexedd);

	private:
		const static double Version;	




};





