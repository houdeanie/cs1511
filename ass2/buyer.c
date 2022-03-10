// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 30/07/15

// functions that relate to the buyer

#include "trader_bot.h"
#include "trader_functions.h"
#include <string.h>

#define TRUE 1
#define FALSE 0
// finds the nearest buyer of same commodity as in cargo as in bot
int nearest_buyer(struct bot *b) {
    int nearestBuyer;
    struct location *currentLocation = b->location; 
	struct location *startingLocation = b->location; 
    int movesForwards = 0;
	int movesBackwards = 0;
	int stop  = FALSE;

	// going forwards
	while (stop == FALSE) {
		// if not at starting location again keep going until nearest buyer with same commodity is found
		if (currentLocation->type == LOCATION_BUYER && strcmp(b->cargo->commodity->name, currentLocation->commodity->name) == 0 && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			movesForwards++;
			currentLocation = currentLocation->next;
		}
		if (currentLocation == startingLocation) { // stop if at starting location again
			movesForwards == 0;
			break;
		}
	}
	
	// going backwards
	// reset to starting location
	currentLocation = startingLocation;
	stop = FALSE; 
	while (stop == FALSE) {
		// if not at starting location again keep going until nearest buyer with same commodity is found
		if (currentLocation->type == LOCATION_BUYER && strcmp(b->cargo->commodity->name, currentLocation->commodity->name) == 0 && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			movesBackwards++;
			currentLocation = currentLocation->previous;
		}
		if (currentLocation == startingLocation) { // stop if at starting location again
			movesBackwards = 0;
			break;
		}
	}
	if (movesBackwards < movesForwards) { // determine shortest distance to buyer
		nearestBuyer = -movesBackwards;
	} else {
		nearestBuyer = movesForwards;
	}
    return nearestBuyer;
}
// find total buyers in the trader bot world, returns int of total buyers in the world
int total_buyers(struct bot *b) {
	struct location *curr = b->location;
	struct location *start = b->location;
	int total = 0;
	
	while (TRUE) { // cycle through world and count++ each time finds a buyer
		if (curr->type == LOCATION_BUYER && curr->quantity != 0) {
			total++;
		} 
		curr = curr->next;
		if (curr == start) { // stop when at start
			break;
		}
	}
	return total;
}

