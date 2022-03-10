// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 03/06/15

// functions here generally find the quantity at the buyer to determine how much to buy at the seller

#include "trader_bot.h"
#include "trader_functions.h"
#include <string.h>

// values for sentinel variables 
#define TRUE 1 
#define FALSE 0
// function that calulates how much to buy, depending on the nearest buyer
// return quantity nearest buyer is willing the buy
int nearest_demand(struct bot *b) {
	int buy;
    struct location *currentLocation = b->location; 
	struct location *start = b->location;
	struct location *temp1 = NULL;
	struct location *temp2 = NULL;
	int forwards = 0;
	int backwards = 0; 
    int stop  = FALSE;
	
	// going forwards, find nearest buyer with right commodity and has quantity demanded, copied from nearest buyer function
	while (stop == FALSE) {
		if (currentLocation->type == LOCATION_BUYER && strcmp(b->location->commodity->name, currentLocation->commodity->name) == 0 && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			forwards++;
			currentLocation = currentLocation->next;
		}
		if (currentLocation == start) {
			backwards = 0;
			break;
		}
	}
	temp1 = currentLocation;
	// going backwards, find nearest buyer with right commodity and has quantity demanded, copied from nearest buyer function
	// reset to starting location
	currentLocation = start;
	stop = FALSE; 
	while (stop == FALSE) {
		if (currentLocation->type == LOCATION_BUYER && strcmp(b->location->commodity->name, currentLocation->commodity->name) == 0 && currentLocation->quantity != 0) {
			stop = TRUE;
		} else {
			backwards++;
			currentLocation = currentLocation->previous;
		}
		if (currentLocation == start) {
			backwards = 0;
			break;
		}
	}
	temp2 = currentLocation;
	if (backwards < forwards) { // find the nearest quantity demanded, return nearest buyer quantity
		buy = temp2->quantity;
	} else {
		buy = temp1->quantity; 
	}
	return buy;
}
