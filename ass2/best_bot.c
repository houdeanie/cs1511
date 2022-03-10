// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 03/06/15

// bot only carries one commodity at a time and buys and sells at the best places
// main bot get action function where action decisions are made, I'll walk you through them

#include "trader_bot.h"
#include "trader_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// return name of bot
char *get_bot_name(void) {
    return "houdeanie";
}
// decision making to get actions under certain conditions
void get_action(struct bot *b, int *action, int *n) {
    struct location *currentLocation = b->location;
    int turnsLeft = b->turns_left;
    
    printf("%s\n", profit_seller(b));
    // fuel conditions takes priority, stayin alive
    // if fuel is below a certain limit- cannot reach a fuel station with current fuel after the next move
    // go to fuel station, else continue actions
    if ((b->cargo == NULL && stranded(b, nearest_seller(b)) != 1) || (b->cargo != NULL && stranded(b, nearest_buyer(b)) != 1)) {
    // CASE 1: cargo == NULL, go to the best seller from function, buy
		if (b->cargo == NULL) { 	// first check if there are sellers and not in last 3 turns
			if (currentLocation->type != LOCATION_SELLER && total_buyers(b) != 0 && total_sellers(b) != 0 && last(b) != 0) { 	// going to seller
				if (nearest_seller(b) != 0) { 	// check for if there are profitable sellers and not in the last few turns
					*action = ACTION_MOVE; 
					*n = nearest_seller(b);
				} else { 	// no profitable sellers, don't buy anything
					*action = ACTION_MOVE;
					*n = 0;
				}
			} else if (currentLocation->type == LOCATION_SELLER && last(b) != 0) { // at a seller, and not in last few turns, buy! 
				if (currentLocation->quantity != 0) { // check if location has quantity to sell, should check in profit_seller function too
		   			if (nearest_demand(b) != 0) {
		   				*action = ACTION_BUY; // determine quantity to buy from the buyer of the good
		   				*n = nearest_demand(b);
		   			} else {
		   				*action = ACTION_MOVE; // no more demand for this item, maybe in multiplayer, already sold out, go to the next profit seller
		   				*n = nearest_seller(b);
		   			}
	   			} else { // currentLocation->quantity == 0, cannot buy, go to next best seller
		   			*action = ACTION_MOVE;
		   			*n = nearest_seller(b);
		   		}
	   		} else { // might be in last 3 turns or no buyers/sellers of anything, dont do anything, dont buy!
	   			*action = ACTION_MOVE;
	   			*n = 0;
	   		}
		} else {
	   	// CASE 2: cargo != NULL, going to commodity buyer and sell quantity buyer is willing to accept
			if (stranded(b, nearest_buyer(b)) != 1 && nearest_buyer(b) != 0)  { // going to buyer
		   		if (total_buyers(b) != 0) { // check if there are buyers, else go to dump
		   			*action = ACTION_MOVE;
		   			*n = nearest_buyer(b);
		   		} else {
		   			*action = ACTION_MOVE;
		   			*n = nearest_dump(b);
		   		}
		   	} else {
		   		if (currentLocation->type == LOCATION_DUMP) { // if at dump
		   			*action = ACTION_DUMP;
		   		} else if (currentLocation->type == LOCATION_BUYER && currentLocation->quantity != 0 && currentLocation->commodity == b->cargo->commodity) { // at buyer which can buy
		   			*action = ACTION_SELL;
		   			*n = currentLocation->quantity;
		   		} else { // stranded
		   			if (stranded(b, profit_buyer(b)) == 1) { // running low on fuel, prioritise fuel
		   				if (nearest_fuel(b) != 0) { // check if there fuel stations go to fuel station
		   					*action = ACTION_MOVE;
		   					*n = nearest_fuel(b);
		   				} else if (nearest_fuel(b) == 0 && nearest_buyer(b) != 0) { // no fuel stations, go to nearest buyer and complete transaction
				   			*action = ACTION_MOVE;
				   			*n = nearest_buyer(b);
				   		} else {
				   			*action = ACTION_MOVE;
				   			*n = nearest_dump(b);
				   		}
			   		} else {
			   			*action = ACTION_MOVE;
				   		*n = nearest_buyer(b);
				   	}
			   	}
	   		}
	   	}
	} else { // refuel 
		if (nearest_fuel(b) != 0 && currentLocation->type != LOCATION_PETROL_STATION && last(b) != 0) {
	  		*action = ACTION_MOVE;
	  		*n = nearest_fuel(b);
	  	} else {
	  		if (last(b) == 0) {
	  			*action = ACTION_MOVE;
	  			*n = 0;
	  		} else if (currentLocation->quantity != 0 && currentLocation->type == LOCATION_PETROL_STATION) {
	  			*action = ACTION_BUY;
	  			*n = b->fuel_tank_capacity - b->fuel;
	  		} else {
	  			if (nearest_fuel(b) != 0) {
		  			*action = ACTION_MOVE;
			  		*n = nearest_fuel(b);
			  	} else {
			  		if (b->cargo != NULL && currentLocation->type != LOCATION_BUYER) {
			  			*action = ACTION_MOVE;
		   				*n = nearest_buyer(b);
			  		} else if (b->cargo != NULL && currentLocation->type == LOCATION_BUYER) {
			  			*action = ACTION_SELL;
		   				*n = currentLocation->quantity;
		   			} else {
		   				*action = ACTION_MOVE;
		   				*n = 0;
		   			}
		   		}
			}
		}
	}
}
