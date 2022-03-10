// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 05/06/15

// bot only carries one commodity at a time and buys and sells at the best places but within a limited distance from profit.c
// main bot get action function where action decisions are made depending on situation, I'll walk you through them

#include "trader_bot.h"
#include "trader_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// return name of bot
char *get_bot_name(void) {
	return "worst trade deal ever"; 
}
// decision making to get actions under certain conditions
void get_action(struct bot *b, int *action, int *n) {
    struct location *currentLocation = b->location;
    int fuel = b->fuel;
    
    // fuel conditions takes priority, stayin alive, stayin alive
    // if fuel is below a certain limit, go to fuel station
    // else continue actions
    // 
    // (b->cargo == NULL && stranded(b, shortest_distance(b, profit_seller(b))) != 1)) || (b->cargo != NULL && stranded(b, shortest_distance(b, profit_buyer(b))) != 1) // previous conditon that needs to be reworked to predict more accurately when refueling is needed
    
    if (fuel > (world_distance(b)/2)) { // if fuel is half of distance of the world
    // CASE 1: cargo == NULL, go to the best seller from function, buy
		if (b->cargo == NULL) { 	// first check if there are sellers and not in last 3 turns
			// printf("%s\n", profit_seller(b));- debugging
			// going to seller
			if (currentLocation->type != LOCATION_SELLER && total_buyers(b) != 0 && total_sellers(b) != 0 && last(b) != 0) { 	
				if (profit_seller(b) != 0) { 	// check for if there are profitable sellers and not in the last few turns
					*action = ACTION_MOVE; 
					*n = shortest_distance(b, profit_seller(b));;
				} else { 	// no profitable sellers, don't buy anything
					*action = ACTION_MOVE;
					*n = 0;
				}
			} else if (currentLocation->type == LOCATION_SELLER && last(b) != 0) { // at a seller, and not in last few turns, buy! 
				if (currentLocation->quantity != 0 && shortest_distance(b, profit_seller(b)) == 0) { 
				// check if location has quantity to sell, and is at the designated location
		   			if (nearest_demand(b) != 0) {
		   				*action = ACTION_BUY; // determine quantity to buy from the buyer of the good
		   				*n = nearest_demand(b); // buy nearest demanded quantity, need to fix this
		   			} else {
		   				*action = ACTION_MOVE; // no more demand for this item, maybe in multiplayer, already sold out-> go to the next profit seller
		   				*n = shortest_distance(b, profit_seller(b));
		   			}
	   			} else { // currentLocation->quantity == 0, or not at designnated best seller-> move again
		   			*action = ACTION_MOVE;
		   			*n = shortest_distance(b, profit_seller(b));
		   		}
	   		} else { // might be in last 3 turns or no buyers/sellers of anything-> dont do anything-> dont buy!
	   			*action = ACTION_MOVE;
	   			*n = 0;
	   		}
		} else {
	   	// CASE 2: cargo != NULL, going to commodity buyer and sell quantity buyer is willing to accept
	   		// printf("%s\n", profit_buyer(b)); - debugging
	   		// going to a buyer
			if (profit_buyer(b) != 0 && currentLocation->name != profit_buyer(b) && stranded(b, shortest_distance(b, profit_buyer(b))) != 1)  {
			// if there are stil profitable buyers, at designnated buyer, and not too far away from fuel station
		   		if (total_buyers(b) != 0) { // check if there are buyers, else go to dump
		   			*action = ACTION_MOVE;
		   			*n = shortest_distance(b, profit_buyer(b)); // move shortest distance to buyer
		   		} else { // if there are no more buyers for the good, and you are carrying that good-> dump is only option
		   			*action = ACTION_MOVE;
		   			*n = nearest_dump(b);
		   		}
		   	} else {
		   		if (currentLocation->type == LOCATION_DUMP) { // if at dump->only aaction is dump, why else would you be there?
		   			*action = ACTION_DUMP;
		   		} else if (currentLocation->type == LOCATION_BUYER && currentLocation->quantity != 0 && currentLocation->commodity == b->cargo->commodity) { 
		   		// at buyer which can buy
		   			*action = ACTION_SELL;
		   			*n = currentLocation->quantity; // sell everything you have and then some!!
		   		} else { // stranded
		   			if (stranded(b, shortest_distance(b,profit_buyer(b))) == 1) { // running low on fuel, refuel of sell last item
		   				if (nearest_fuel(b) != 0) { // check if there fuel stations go to fuel station
		   					*action = ACTION_MOVE;
		   					*n = nearest_fuel(b);
		   				} else if (nearest_fuel(b) == 0 && nearest_buyer(b) != 0) { // no fuel stations, go to nearest buyer and complete transaction
				   			*action = ACTION_MOVE;
				   			*n = nearest_buyer(b); // okay panic and drop off at the nearest buyer before fuel runs out
				   		} else {
				   			*action = ACTION_MOVE; // too late go to a dump
				   			*n = nearest_dump(b);
				   		}
			   		} else {
			   			*action = ACTION_MOVE; // fuel is not an issue, just go to nearest buyerbecause designnated buyer is unavailable somehow
				   		*n = nearest_buyer(b);
				   	}
			   	}
	   		}
	   	}
	} else { // refuelling commands 
		if (nearest_fuel(b) != 0 && currentLocation->type != LOCATION_PETROL_STATION && last(b) != 0) { // if not at petrol station go to one 
	  		*action = ACTION_MOVE;
	  		*n = nearest_fuel(b);
	  	} else {
	  		if (last(b) == 0) { // last few turns and low on fuel, dont move
	  			*action = ACTION_MOVE;
	  			*n = 0;
	  		} else if (currentLocation->quantity != 0 && currentLocation->type == LOCATION_PETROL_STATION) { // at fuel tank, refuel max
	  			*action = ACTION_BUY;
	  			*n = b->fuel_tank_capacity - b->fuel;
	  		} else {
	  			if (nearest_fuel(b) != 0) { // not at fuel station, not last few turns and there are fuel stations
		  			*action = ACTION_MOVE;
			  		*n = nearest_fuel(b);
			  	} else { // no more fuel stations
			  		if (b->cargo != NULL && currentLocation->type != LOCATION_BUYER) { // go to nearest buyer to sell
			  			*action = ACTION_MOVE;
		   				*n = nearest_buyer(b);
			  		} else if (b->cargo != NULL && currentLocation->type == LOCATION_BUYER) { // nearest buyer, sell
			  			*action = ACTION_SELL;
		   				*n = currentLocation->quantity;
		   			} else { // i don't know just move 0
		   				*action = ACTION_MOVE;
		   				*n = 0;
		   			}
		   		}
			}
		}
	}
}
