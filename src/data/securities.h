#include <vector>

// List of securities

// Should contain:
// * Full name
// * Price
// * Volume
// * Market Cap
// * Float

// TODO: Should be easy to change the info of the security in the database. Do not hardcode.

struct security{
	std::string fullName;
	double Price;
	size_t dailyVolume;
	double marketCap;
	double Float;
};


// This is absolutely fucking terrible formatting.
// This is just to test marketMaker.
// Still, fucking hurts just looking at it.

security GME { "Gamestop Corporation", 132.35, 0, 9321000000, 54487000};

security AAPL {"Apple Inc", 120.13, 0, 20200000000000, 16770000000};

security GOOGL {"Alphaber Inc Class A", 2033.93, 0, 1380000000000, 674140000};

std::map<std::string, security> allSecurities {
	{"GME", GME},
	{"AAPL", AAPL},
	{"GOOGL", GOOGL}
};
