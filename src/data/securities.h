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

std::vector<security> allSecurities;

{
	// For some unknown reason, those only compute inside a code block.
	// Really fucking wierd.

	security GME;
	GME.fullName = "GameStop Corporation";
	GME.Price = 132.35;
	GME.dailyVolume = 0;
	GME.marketCap = 9321000000;
	GME.Float = 54487000;

	security AAPL;
	AAPL.fullName = "Apple Inc";
	AAPL.Price = 120.13;
	AAPL.dailyVolume = 0;
	AAPL.marketCap = 2020000000000;
	AAPL.Float = 16770000000;


	security GOOGL;
	GOOGL.fullName = "Alphabet Inc Class A";
	GOOGL.Price = 2033.93;
	GOOGL.dailyVolume = 0;
	GOOGL.marketCap = 138000000000;
	GOOGL.Float = 674140000;

	allSecurities.push_back(GME);
	allSecurities.push_back(AAPL);
	allSecurities.push_back(GOOGL);
}
