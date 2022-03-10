// program finds distance to nearest fuel station
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 10 lab

#include "trader_bot.h"
#include <stdio.h>
// printf for debugging

int nearest_fuel(struct bot *b) {
    int nearest = 0;
	// pointer to the bot position in the location list
    struct location * current = b->location; 
	// pointer to the starting l position in the location list
	struct location *starting_location = current; 
    int movesForwards = 0;
	int movesBackwards = 0;

	// going forwards
	while (current->type != LOCATION_PETROL_STATION) {
		movesForwards++;
		current = current->next;
	}
	// printf("%d\n", movesForwards);
	// going backwards
	// reset to starting location
	current = starting_location; 
	while (current->type != LOCATION_PETROL_STATION) {
		movesBackwards++;
		current = current->previous;
	}
	// printf("%d\n", movesBackwards);
	if (movesBackwards < movesForwards) {
		nearest = -movesBackwards;
	} else {
		nearest = movesForwards;
	}
    return nearest;
}
