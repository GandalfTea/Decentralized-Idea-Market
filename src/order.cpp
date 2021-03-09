#include <map>
#include <vector>

typedef std::map<std::string, std::string> dict;

struct Flow{
	std::vector<dict> Buy;
	std::vector<dict> Sell;
};

Flow orderFlow;


//Orders should contain:

// * Addresss of user
// 	* Public key
// 	* Account address
// * Timestamp
// 	* Date
// 	* Time
// * Security
// * Price
// * Quantity
// * Type: sell of buy -- 1 is buy, 0 is sell
// * Expiration  -- only day
// * Execution type :
// * Locked money or security

dict createOrder(std::string userAddress,
		std::string Security,
		std::string Price,
		std::string Quantity,
		std::string Type,
		std::string Expiration,
		std::string Execution) {

	std::string timestampDay = "Automatic time allocation.";
	std::string timestampHour = "Automatic time allocation.";

	std::string Timestamp = timestampDay + " " + timestampHour;

	static size_t ID = 1;


	//create dict of order
	dict order;
	order["ID"] = to_string(ID++);
	order["user"] = userAddress;
	order["time"] = Timestamp;
	order["security"] = Security;
	order["price"] = Price;
	order["quantity"] = Quantity;
	order["type"] = Type;
	order["expiration"] = Expiration;
	order["execution"] = Execution;

	if(order["type"] == "1") {
		orderFlow.Buy.push_back(order);
	} else if (order["type"] == "0"){
		orderFlow.Sell.push_back(order);
	} else {
		// raise exception
	}

	// Find way to connect an order to a wallet
	// Lock money or security in ledger

	return order;
}




// filter order flow so that:
// * buy vector is high price -> low price
// * sell vector is low price -> high price

// Structure order into order flow
