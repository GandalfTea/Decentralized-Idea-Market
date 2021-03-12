#define _WIN32_WINNT 0x0501
#include "marketMaker.h"
#include <iostream>
#include <chrono>
#include "mingw.thread.h"
#include "./data/securities.h"
#include "./data/users.h"

void marketMaker::Start(){

	// Debug transactions.
	marketMaker::Database.createOrder("AL001", "GME", "169.69", "10", "1", "Not now", "ASAP");
	marketMaker::Database.createOrder("MA001", "GME", "169.69", "10", "0", "Not now", "ASAP");


	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(1));
		updateOrderFlow();


		std::thread t1(&marketMaker::searchTransaction, this);
		std::thread t2(&marketMaker::createTransaction, this);
		t1.join();
		t2.join();
		std::cout << "Another one." << std::endl;
	}
}


void marketMaker::searchTransaction(){
	if(marketMaker::orderFlow.Buy.size() != 0 && marketMaker::orderFlow.Sell.size() != 0) {
		std::cout << "Searched commenced" << std::endl;
		for(size_t i = 0; i < marketMaker::orderFlow.Buy.size(); i++){
			for(size_t j = 0; j < marketMaker::orderFlow.Sell.size(); j ++){
				if(std::stoi(marketMaker::orderFlow.Buy[i]["price"]) == std::stoi(marketMaker::orderFlow.Sell[j]["price"])){
					pairOrder order{marketMaker::orderFlow.Buy[i], marketMaker::orderFlow.Sell[j],i, j};
					marketMaker::buffer.push_back(order);
				}
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

	// Debug	
	if(buffer.size() == 0) { std::cout << "'noting here chief." << std::endl;}

	for(size_t i = 0; i < buffer.size(); i++){

		if(transactionIntegrity(buffer[i].Sell, buffer[i].Buy)){
			std::cout << "Transaction commenced." << std::endl;

			// Remove the orders from orderFlow and buffer
			dict sell = buffer[i].Sell;
			dict buy = buffer[i].Buy;

			orderFlow.Buy.erase(orderFlow.Buy.begin() + buffer[i].indexBuy);
			orderFlow.Sell.erase(orderFlow.Sell.begin() + buffer[i].indexSell);

			buffer.erase(buffer.begin() + i);

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

				std::cout << "Full Order Fulfillment" << std::endl;

				saveTransaction(buffer[i]);
				updatePriceAndVolume(buy);

				return;

			// Partial Order Fulfillment
			}else if (std::stoi(sell["quantity"]) > std::stoi(buy["quantity"]) || std::stoi(sell["quantity"]) < std::stoi(buy["quantity"])){
				
				std::cout << "Partial Order Fulfillment" << std::endl;

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

				saveTransaction(buffer[i]);

				return;
			}
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
	
	allSecurities[order["security"]].Price = std::stoi(order["quantity"]);
	allSecurities[order["security"]].dailyVolume += std::stoi(order["price"]);

	return;
}


void marketMaker::updateOrderFlow(){
	marketMaker::orderFlow = marketMaker::Database.getOrders();
}
