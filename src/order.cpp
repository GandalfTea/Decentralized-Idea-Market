#include <map>
#include <vector>

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

	timestampDay = "Automatic time allocation.";
	timestampHour = "Automatic time allocation.";

	//create dict of order
	dict order;
	order["user"] = userAddress;
	order["time"] = dict Timestamp {"day" : timestampDay,
	       				"hour" : timestampHour};
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


int main()


// filter order flow so that:
// * buy vector is high price -> low price
// * sell vector is low price -> high price

// Structure order into order flow
