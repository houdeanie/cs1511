// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 29/07/15

// finds the stuff related to sellers

#include "trader_bot.h"
#include "trader_functions.h"

#define TRUE 1
#define FALSE 0

// finds the nearest seller of a good which has a quantity to sell

int nearest_seller(struct bot *b) {
    int nearestSeller;
    struct location * currentLocation = b->location; 
	struct location *startingLocation = b->location; 
    int movesForwards = 0;
	int movesBackwards = 0;
	int stop = FALSE;	
	// going forwards
	while (stop == FALSE) { //cycle undtil seler is found or reaches start
		if (currentLocation->type == LOCATION_SELLER && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			movesForwards++;
			currentLocation = currentLocation->next;
		}
		if (currentLocation == startingLocation) {
			movesForwards = 0;
			break;
		}
	}
	// going backwards
	// reset to starting location, repeat
	stop = FALSE;
	currentLocation = startingLocation; 
	while (stop == FALSE) {
		if (currentLocation->type == LOCATION_SELLER && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			movesBackwards++;
			currentLocation = currentLocation->previous;
		}
		if (currentLocation == startingLocation) {
			movesBackwards = 0;
			break;
		}
	}
	// determine shortest distance
	if (movesBackwards < movesForwards) {
		nearestSeller = -movesBackwards;
	} else {
		nearestSeller = movesForwards;
	}
    return nearestSeller;
}
// find total sllers in the trader bot world, returns int of total sellers in the world
int total_sellers(struct bot *b) {
	struct location *curr = b->location;
	struct location *start = b->location;
	int total = 0;
	
	while (TRUE) { // cycle through finding sellers, stop when reaches start again
		if (curr->type == LOCATION_SELLER && curr->quantity != 0) {
			total++;
		}
		curr = curr->next;
		if (curr == start) {
			break;
		}
	}
	return total;
}
