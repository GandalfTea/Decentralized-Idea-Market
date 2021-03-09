#include <string>
#include <map>

// In the future, this should be decentralyzed and protected by public-key encryption.

struct user {
	std::string Name;
	std::string Address;
	double Money;
	std::string Currency;
	std::map<std::string, double> Stocks;
};

std::map<std::string, user> allUsers;

{
	// Example of user

	user Alex;
	Alex.Name = "Alex Voldigord";
	Alex.Address = "AL0001";
	Alex.Money = 265.89;
	Alex.Currency = "USD";

	std::map<std::string, double> stocks {
		"AAPL" : 14.5
	}
	Alex.Stocks = stocks;

	allUsers[Alex.Address] = Alex;


	user Maria;
	Maria.Name = "Maria Duhovnicescu DelaMare";
	Maria.Address = "MA001";
	Maria.Money = 9876093.00;
	Maria.Currency = "RON";

	std::map<std::string, double> stonks {
		"GME" : 456.3,
		"AAPL" : 0.78
	}
	Maria.Stocks = stonks;

	allUsers[Maria.Address] = Maria;
}
