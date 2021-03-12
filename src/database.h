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

		void createOrder( std::string userAddress,
				  std::string Security,
				  std::string Price,
				  std::string Quantity,
				  std::string orderType,
				  std::string Expiration,
				  std::string Execution );

		// get latest external orders
		void updateOrders(std::vector<dict> newOrders);
		// update external order list
		Flow getOrders();

	private:
		Flow orderFlow;
		int orderID;
		const static double Version;	

};

