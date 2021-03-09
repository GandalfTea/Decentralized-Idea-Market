#include "./data/users.h"
#include "marketMaker.h"
#include <thread>


marketMaker::marketMaker(){


	while(true){
		updateOrderFlow();
		std::thread searchTransaction();
		std::thread t2(createTransaction());
	}
}


void marketMaker::searchTransaction(){
	for(size_t i = 0; i == orderFlow.Buy.size(); i++){
		for(size_t j = 0; j == orderFlow.Sell.size(); j ++){
			if(orderFlow.Buy[i]["Price"] == orderFlow.Sell[j]["Price"]){
				pairOrder order{orderFlow.Buy[i], orderFlow.Sell[j],i, j};
				marketMaker::buffer.push_back(order);
			}
		}
	}
}

void marketMaker::createTransaction(){

	/* 
	 * Check transaction integrity.
	 * Check volume.
	 * Transfer volume and money from one account to another.
	 * *Sign transfer with public key.
	 * *Put transaction on block
	 * ~ Update the order and return to orderFlow(of more volume)
	 */
	
	for(auto transaction : buffer){	

		transactionIntegrity(transaction.Sell, transaction.Buy);

		// Remove the orders from orderFlow	
		dict& sell = transaction.Sell;
		dict& buy = transaction.Buy;

		orderFlow.Buy.erase(orderFlow.Buy.begin() + transaction.indexBuy);
		orderFlow.Sell.erase(orderFlow.Sell.begin() + transaction.indexSell);


		// Full Order Fulfillment
		if (sell["quantity"] == buy["quantity"]){

			{
				//Transfer money and security
				double Quantity = std::stoi(sell["quantity"]);
				double Value = std::stoi(sell["quantity"]) * std::stoi(sell["price"]);

				allUsers[sell["user"]].Stocks[sell["security"]] -= Quantity;
				allUsers[buy["user"]].Money -= Value;
				allUsers[buy["user"]].Stocks[buy["security"]] += Quantity;
				allUsers[sell["user"]].Money += Value;

			}

			saveTransaction(transaction);
			updatePriceAndVolume(buy);

			return;

		// Partial Order Fulfillment
		}else if (std::stoi(sell["quantity"]) > std::stoi(buy["quantity"]) || std::stoi(sell["quantity"]) < std::stoi(buy["quantity"])){
			

			if(std::stoi(sell["quantity"]) > std::stoi(buy["quantity"])){

				{
					// Transfer money and security.

					double Quantity = std::stoi(buy["quantity"]);
					double Price = std::stoi(buy["price"]);

					allUsers[sell["user"]].Stocks[sell["security"]] -= Quantity;
					allUsers[buy["user"]].Money -= Price;
					allUsers[buy["user"]].Stocks[buy["security"]] += Quantity;
					allUsers[sell["user"]].Money += Price;
				}

				// Push back the order that is partially fulfilled.
				double Remainder = std::stoi(sell["quantity"]) - std::stoi(buy["quantity"]);
				sell["quantity"] = std::to_string(Remainder);
				orderFlow.Sell.push_back(sell);

				updatePriceAndVolume(buy);

			}else if(std::stoi(sell["quantity"]) < std::stoi(buy["quantity"])) {
				
				{
					// Transfer money and security.
				
					double Quantity = std::stoi(sell["quantity"]);
					double Price = std::stoi(buy["price"]);

					allUsers[sell["user"]].Stocks[sell["security"]] -= Quantity;
					allUsers[buy["user"]].Money -= Price;
					allUsers[buy["user"]].Stocks[buy["security"]] += Quantity;
					allUsers[sell["user"]].Money += Price;
				}
				
				// Push back the order that is partially fulfilled.
				double Remainder = std::stoi(buy["quantity"]) - std::stoi(sell["quantity"]);
				buy["quantity"] = std::to_string(Remainder);
				orderFlow.Sell.push_back(sell);

				updatePriceAndVolume(sell);
			}

			saveTransaction(transaction);

			return;
		}
	}
}

void marketMaker::saveTransaction(pairOrder transaction){

	// Save transaction on block.	
	// Implement later.
	return;

}


bool marketMaker::transactionIntegrity(dict sell, dict buy){

	// Checking for integrity:
	// * Expiration date not passed.
	// * Buyer must have enough money in acc, seller must have security.
	// * Money or security should be in the order

	return true;
}

void marketMaker::updatePriceAndVolume(dict order){
	// * Access the security in the securities.h file
	// * Update price.
	// * Update volume.
	
	double orderVolume = std::stoi(order["quantity"]);
	double orderPrice = std::stoi(order["price"]);
	// Get security.
	return;
}


void marketMaker::updateOrderFlow(){

	orderFlow = Database.retrieveOrders();
}
