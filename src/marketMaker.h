#include "database.h"
#include "/data/securities.h"


/* 

 Order processing:

 1.  Original vector from database.h will be updated.
 2.  Filter the orders into buy - sell and update:
 	* All orders for different securities
	  are held in the same vectors.
     the orderFlow vectors.
 3.  Organize the orders in the vector:
 	* Buy  - highest bid first.
 	* Sell - lowest sell price first.
 4.  Go through vectors and match transactions:
	* Same security
 	* Orders with the same price.
 5.  Check the orders integrity:
 	* The money or security must be locked in the
	  order OR it must be in the account.
	* Check expiration date.
 6.  Sign digital contract with acc private key.
 7.  Transfer the money and security.
 8.  If order is not full due to volume, update
     the numbers and put in orderFlow again.
 9.  Update price based on price of most transactions.
 10. Update volume based on traded shares.
 
*/

class marketMaker(){

	public:
		// handle transactions
		marketMaker();
	
	private:

		new Flow orderFlow;
		size_t updateRate;

		bool transactionIntegrity();

		void updatePrice();
		void updateVolume();
		void updateOrderFlow();
}


