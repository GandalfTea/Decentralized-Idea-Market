#include <string>

class Order {
	public:
		Order(std::string user = "Undefined", 
		      double time = 0, 
		      std::string security = "Undefined",
		      double quantity = 0, 
		      double price = 0, 
		      size_t type = 0, 
		      std::string orderExecutionType = "Undefined");

		//Debug
		void printOrder();
		
		std::string User;
		double Time;
		size_t ID;		
		std::string Security;
		double Quantity;
		double Price;
		size_t orderType; // 0 is sell, 1 is buy
		std::string orderExecution;

	private:
		// Used to get access to a vector of orders later
		static size_t orderID;

		// Address of user
		// Timestamp
		// security
		// Quantity
		// Price
		// Sell or Buy
		// Order Type
		// Availability
		// Locked Money
};



