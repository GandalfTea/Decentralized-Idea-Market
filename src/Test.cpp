
#include "Order.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	std::vector<Order> orders = {};

	Order order1("user001", 23.95, "$GME", 6, 312.45,
		     0, "Immidiately");
	Order order2("user001", 23.3395, "$APL", 5, 0.45,
		     1, "when it go up");
	orders.push_back(order1);
	orders.push_back(order2);

	for(size_t i = 0; i <= orders.size()-1; i++) {
		orders[i].printOrder();
	}
	return 0;
}
