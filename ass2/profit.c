// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 03/06/15

// code that will help make decisions on movements based on profits 
// profit = (buyer price - seller price) * buyer quantity

#include "trader_bot.h"
#include "trader_functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
// funcion that finds the minimum of two values 

// function for calculating profit, and account for weight and volume
int calculate_profit(struct bot *b, struct commodity *commodity, int buyPrice, int sellPrice, int buyQuantity, int sellQuantity) {
	int value;
	int maxVolume = b->maximum_cargo_volume, maxWeight = b->maximum_cargo_volume; // maximum weight and volume bot can carry
	int commodityVolume = commodity->volume, commodityWeight = commodity->weight; // commodity wieght and volume
	int botMaxQuantity, buyerSellerQuantity; // the max quantity that the bot can carry, the max quantity that the buyer can buy/ seller can sell
	int quantity; // final quantity
	// finding the maximum quantity of a commodity it can buy in one move and call that - botMaxQuantity
	if (maxVolume/commodityVolume < maxWeight/commodityWeight) {
		botMaxQuantity = maxVolume/commodityVolume;
	} else {
		botMaxQuantity = maxWeight/commodityWeight;
	}
	// finding the maximum that a buyer/ seller is willing to buy/sell (minimum really)
	if (buyQuantity < sellQuantity) {
		buyerSellerQuantity = buyQuantity;
	} else {
		buyerSellerQuantity = sellQuantity;
	}
	if (botMaxQuantity < buyerSellerQuantity) { // determne final quantity depending of the what is least as that is wut will be bought/sold/carried
		quantity = botMaxQuantity;
	} else { 
		quantity = buyerSellerQuantity;
	}	
	value = (sellPrice - buyPrice)*quantity;// determine profit
	return value;
}

// determines the most profitable seller location, returns distance to best seller				
char *profit_seller(struct bot *b) { 
	struct location *buyerCurr = b->location;
	struct location *sellerCurr = b->location;
	struct location *start = b->location;
	struct location *bestSeller = b->location;
	int currProfit, bestProfit = 0;
	int stop = FALSE;
	int distance, forwards = 0, backwards = 0;
	
	// loop through sellers, when reaches a sellers, stop and loop through buyers
	// remember best seller 
	while (stop == FALSE) { // stop looping through sellers when reaches starting position again
		if (sellerCurr->type == LOCATION_SELLER && sellerCurr->quantity != 0) { // check for seller
			buyerCurr = sellerCurr->next; // set buyer to be after the seller, seller cannot be buyer
			while (buyerCurr != sellerCurr) { // loop through buyers until finds buyer which matches the commodity and is not 0
				if (buyerCurr->type == LOCATION_BUYER && strcmp(sellerCurr->commodity->name, buyerCurr->commodity->name) == 0 && buyerCurr->quantity != 0) {
					currProfit = calculate_profit(b, sellerCurr->commodity, sellerCurr->price, buyerCurr->price, buyerCurr->quantity, sellerCurr->quantity);
					currProfit = moves_profits(b, sellerCurr->name, currProfit);
					// calculate profit adjusted for weight and movement
				}
				if (currProfit> bestProfit) { // determine best profit and seller
					bestProfit = currProfit;
					bestSeller = sellerCurr;
				}
				buyerCurr = buyerCurr->next;
			}
		}
		sellerCurr = sellerCurr->next;
		if (sellerCurr == start) { // stop if reaches start again
			stop = TRUE;
		}
	}
	if (bestProfit > 0) {
		return bestSeller->name;
	} else {
		return 0;// if no profit making places
	}
}	
	// debugging stuff
	// printf("Best Seller: %s ", bestSeller->name);
	// distance to best seller
	/*sellerCurr = start;
	if (bestProfit > 0) {
		while (sellerCurr != bestSeller) {
			forwards++;
			sellerCurr = sellerCurr->next;
		}
		sellerCurr = start;
		while (sellerCurr != bestSeller) {
			backwards++;
			sellerCurr = sellerCurr->previous;
		}
		if (backwards < forwards) {
			distance = -backwards;
		} else {
			distance = forwards;
		}
	} else {
		distance = 0;
	}
	return distance;
}*/

// determines the most profitable buyer location for the commodity the bot is carrying, returns distance to best buyer
char *profit_buyer(struct bot *b) { 
	struct location *currBuyer = b->location;
	struct location *start = b->location;
	struct location *bestBuyer = b->location;
	int currProfit, bestProfit = 0;
	int stop = FALSE;
	int distance, forwards = 0, backwards = 0;
	
	// loop through places until finds buyer sells commodity and quantity is not NULL
	// remember best buyer 
	while (stop == FALSE) {
		if (currBuyer->type == LOCATION_BUYER && strcmp(currBuyer->commodity->name, b->cargo->commodity->name) == 0 && currBuyer->quantity != 0) {
			if (b->cargo->quantity < currBuyer->quantity) { // finds the right profit that can be made depending on what the buyer offers and what the bot can sell
				currProfit = currBuyer->price*b->cargo->quantity;
			} else {
				currProfit = currBuyer->price*currBuyer->quantity;
			}
			if (currProfit > bestProfit) { // find best buyer/ profit
				bestProfit = currProfit;
				bestBuyer = currBuyer;
			}
		}
		currBuyer = currBuyer->next;
		if (currBuyer == start) { // stop when reaches start
			stop = TRUE;
		}
	}
	if (bestProfit > 0) {
		return bestBuyer->name;
	} else {
		return 0; // if no profit making places
	}
}
	// debugging 
	// printf("Best Buyer: %s ", bestBuyer->name);
	/*if (bestProfit > 0) {
		curr = start;
		while (curr != bestBuyer) {
			forwards++;
			curr = curr->next;
		}
		curr = start;
		while (curr != bestBuyer) {
			backwards++;
			curr = curr->previous;
		}
		if (backwards < forwards) {
			distance = -backwards;
		} else {
			distance = forwards;
		}
	} else {
		distance = 0;
	}
	return distance;
}*/

// function accounts for the fact that moving too much is bad as it costs fuel
// if best seller is outside of 2 max moves, dont go there
int moves_profits(struct bot *b, char *sellerName, int localProfit) {
	int maxMove = b->maximum_move;
	if (abs(shortest_distance(b, sellerName)) > 2*maxMove) { // if over movement limit, no profit
		return localProfit = 0;
	} else { 
		return localProfit; // else normal
	}
}
