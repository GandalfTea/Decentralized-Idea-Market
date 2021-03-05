#pragma once
#include <vector>
#include <map>

typedef std::map<std::string, std::string> dict;

struct Flow {
	std::vector<dict> Buy;
	std::vector<dict> Sell;
};

class Database{
	public:
		Database() = default;

		// get latest external orders
		void updateOrders(std::vector<dict> newOrders);
		// update external order list
		Flow retrieveOrders(std::vector<dict> alreadyIndexed);

	private:
		Flow orderFlow;
		const static double Version;	

};

