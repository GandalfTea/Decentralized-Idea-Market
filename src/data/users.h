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


// Example of user

std::map<std::string, double> stocks { {"AAPL", 14.5} };
std::map<std::string, double> stonks { {"GME",456.3}, {"AAPL", 0.78}};

user Alex {"Alex Voldigord", "AL001", 265.89, "USD", stocks};;

user Maria{ "Maria Duhovnicescu DeLaMare", "MA001", 90724587375.5, "USD", stonks};

std::map<std::string,user> allUsers { {"MA001",Maria}, {"AL001",Alex} };


