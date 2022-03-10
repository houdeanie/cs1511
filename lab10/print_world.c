// print_world.c prints a description of all locations in the bot's world going in a forward direction
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 10 lab

#include <stdio.h>
#include "trader_bot.h"

// starting location is not always LOCATION_START
void print_world(struct bot *b) {
	// pointer to the current bot position in the location list	
	struct location *current = b->location; 
	// pointer to the first current starting position in the location list
	struct location *starting_location = current; 
	// sentinel variable to stop locations going past the starting location
	int repeat = 0; 

	// loop that goes through the struct location list
	while (repeat == 0) { 
		if (current->type == LOCATION_START) {
			printf("%s: start\n", current->name); 
			// points to location name
		}
		if (current->type == LOCATION_SELLER) {
			printf("%s: will sell %d units of %s for $%d\n", current->name, current->quantity, current->commodity->name, current->price);
		}
		if (current->type == LOCATION_DUMP) {
			printf("%s: dump\n", current->name);
		}
		if (current->type == LOCATION_OTHER) {
			printf("%s: other\n", current->name);
		}
		if (current->type == LOCATION_PETROL_STATION) {
			printf("%s: Petrol station %d units of available fuel for $%d\n", current->name, current->quantity, current->price);
		}
		if (current->type == LOCATION_BUYER) {
			printf("%s: will buy %d units of %s for $%d\n", current->name, current->quantity, current->commodity->name, current->price);
		}
		// going to next location found in next column &l[next]
		current = current->next; 
		// if the next location is th starting location, repeat = 1, stop loop
		if (current == starting_location) { 
			repeat = 1;
		}
	}
}
