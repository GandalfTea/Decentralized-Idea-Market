#include<marketMaker.h>


size_t marketMaker::updateRate = 1;

// Used as a return for the live search of transactions.
// Allows for parallel running of search and transaction fulfilment.


markerMaker::marketMaker(){

	pairOrder searchTransaction(){
		for(auto ask : orderFlow.Buy){
			for(auto bid : orderFlow.Sell){
				if ask["Price"] == bid["Price"]{
					pairOrders order(ask, bid);
					buffer.push_back(order);
				}
			}	
		}
	}


	while(True){
		
		updateOrderFlow();
		std::thread searchTransaction();
		std::thread createTransaction();
	}
}

void markerMaker::createTransaction(){

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
		dict sell = *transaction.Sell;
		dict buy = *transaction.Buy;

		orderFlow.Buy.remove(transaction.Buy);
		orderFlow.Sell.remove(transaction.Sell);


		// Full Order Fulfillment
		if (sell["quantity"] == buy["quantity"]){
			// Complete transaction
			saveTransaction(transaction);


		// Partial Order Fulfillment
		}else if (sell["quantity"] > buy["quantity"] || sell["quantity"] < buy["quantity"]){
			

			{
				//Transfer money and security
			}



			// In case of partial-completed order, update the order and
			// push it back in the orderFlow.
			
			if(sell["quantity"] > buy["quantity"]){
				int diff = std::stoi(sell["quantity"]) - std::stoi(buy["quantity"]);
				sell["quantity"] = to_string(diff);
				orderFlow.Sell.push_back(sell);
			}else if(sell["quantity"] < buy["quantity"]) {
				int diff = std::stoi(buy["quantity"]) - std::stoi(sell["quantity"]);
				buy["quantity"] = to_string(diff);
				orderFlow.Buy.push_back(buy);
			}

			saveTransaction(transaction);
		}
	}
}

void marketMaker::saveTransaction(pairOrders transaction){
	// Create a completed transaction in a separate file
	// that takes the place of a block. This transaction should be 
	// signed by with the account's public keys. It should also
	// have an identity hash.


}


bool marketMaker::transactionIntegrity(dict sell, dict buy){

	// Checking for integrity:
	// * Expiration date not passed.
	// * Buyer must have enough money in acc, seller must have security.
	// * Money or security should be in the order

}

void marketMaker::updatePriceAndVolume(std::string security){
	// * Access the security in the securities.h file
	// * Update price.
	// * Update volume.

}


void marketMaker::updateOrderFlow(){

	orderFlow = retrieveOrders();
}
