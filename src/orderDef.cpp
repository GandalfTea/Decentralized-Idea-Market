#include <map>
#include <vector>
#include <iostream>

//Orders should contain:
// * Addresss of user
// * Timestamp
// 	* Date
// 	* Time
// * Security
// * Price
// * Quantity
// * Type: sell of buy
// * Expiration
// 	* Date
// 	* Time
// * Execution type :
// * Locked money or security

typedef std::map<std::string,std::string> dict;

struct Flow {
	std::vector<dict> Buy;
	std::vector<dict> Sell;
}

dict createOrder(std::string userAddress,
		std::string Security,
		std::string Price,
		std::string Quantity,
		std::string Type,
		std::string Expiration,
		std::string Execution) {

	Timestapm = "Automatic time allocation.";

	//create dict of order
	dict order;
	order["user"] = userAddress;
	order["time"] = Timestamp;
	order["security"] = Security;
	order["price"] = Price;
	order["quantity"] = Quantity;
	order["type"] = Type;
	order["expiration"] = Expiration;
	order["execution"] = Execution;

	// Add order to order flow
	// Filter order flow

	return order;
}

int main(){
	dict a = createOrder("user001", "GME", "314.45", 
			"3.4", "0","2021-04-05", "Pronto");

	for(auto elem : a) {
		std::cout << elem.first << " : " << elem.second << std::endl;
	}
	return 0;
}

// Structure order into order flow
// Create transactions
// Update state
// Validate transactions
// Create genesis block
