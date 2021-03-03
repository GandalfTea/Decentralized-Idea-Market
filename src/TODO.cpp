


// How to calculate the price :.
// There are ask orders with prices and bid orders with prices.
// When some are the same price, the transaction takes place.
// The price of the transaction becomes the new market price.
// If large volume, price of most transactions

// SMART CONTRACTS

//Decentralyzed blockchain stock market:

// Agreaments are done by Smart Contracts
// They are registered on the blockchain
// Can be called later by transaction calls
// Best known leadgers that provide smart contracts are NXT, Side Chains, Hyperledger and Etherium.

// The smart contract should define the following:
// * symbol - the asset
// * ownedStocks - a mapping between the owner address and the quantity of the assets owned.
// * marketPrice - price of last executed action
// * bids - sorted array of all unexecuted sells
// * asks - sorted array of all unexecuted orders

//CONSENSUS

//Before the block is implemented on the chain, every node in a network needs to agree to it's validity. This is done through a consensus algorithm. The main ones are:
// * Proof of Work  - most used
// * Proof of Stake - most used
// * Proof of Burn
// * Delegated Proof of Stake
// * Proof of Inportance

// Proof of WORK
// It gives the miners a difficult mathematical challenge and whoever manages to solve it first gets to be the miner. This has a big performance hit.

// Proof of STAKE
// It relies on validators taking part in voting for the next block. The weight of each validators's vote is dependent on how much it deposited in the system. Nodes who are allowed to create a block act as validators that need to deposit some crypto as a stake in the network that will be locked 


// ORDERS

// Each order should contain:
// * address of actor
// * timestamp of registry
// * asset quantity
// * willing price
// * Sell or But
// * Order Type (Limit or Market)
// * Availability (how much until expiry)
// * Locked Amount of Money in case of settlement

// The contract must have access to a mapping of address and holdings of each user. This mapping acts as a Decentralyzed Depository. Any modification to this depository is governed by a consensus between peers. Any kind of attack is unfeasable since the state of the depository is stored in blocks in a temper proof manner.

// Once the order transaction is gossiped among the peers, the integrity of the order is checked in the platform before execution. Performing the task of a Decentralyzed Clearing House, each node in the network will check the validity of the order by guaranteeing the success in case of matching order. During the validation, it is checked weather there is enough locked money to complete the transaction and pay for securitits. This is checked with the information on the sell order. The money will then be controlled by the contract and sent to the seller once the order is executed. Similarly, the network will validate that the seller has the securites  by checking te Decentralized Depository entries. 

// Since the contract is replicated across all nodes in the network, the incoming transactions in a block are validated like this. To create a block, it must contain together with the transactions also the latest state of the accounts, the contract. The latest states are determined by the miner after applying the sequence of actions represented by the transactions stored in that block. When a miner wins a competition, the block will be propagated to the intire network for verification and acceptance. Each node will recieve this block and will execute the state transitions by executing all the transactions with respect to the state of the previous block. Then, it will compare the resultis with the block recieved from the miner. If it is correct, the proposed state is accepted, otherwise the block is dropped and new block proposals are accepted.

//  As a result, each node validates all transactions.

//  The transfer fees are replaced by the amount payed to the miner. 

