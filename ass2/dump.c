// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 05/06/15

// program finds distance to nearest dump
#include "trader_bot.h"
#include <stdio.h>
// printf for debugging

int nearest_dump(struct bot *b) {
    int nearestFuel = 0;
	// pointer to the bot position in the location list
    struct location * currentLocation = b->location; 
	// pointer to the starting l position in the location list
	struct location *startingLocation = currentLocation; 
    int movesForwards = 0;
	int movesBackwards = 0;

	// going forwards
	while (currentLocation->type != LOCATION_DUMP) {
		movesForwards++;
		currentLocation = currentLocation->next;
	}
	// going backwards
	// reset to starting location
	currentLocation = startingLocation; 
	while (currentLocation->type != LOCATION_DUMP) {
		movesBackwards++;
		currentLocation = currentLocation->previous;
	}
	if (movesBackwards < movesForwards) { // determine nearest dump
		nearestFuel = -1*movesBackwards;
	} else {
		nearestFuel = movesForwards;
	}
    return nearestFuel;
}
