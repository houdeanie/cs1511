// program that gives the bot name and also the bot actions
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 10 lab

#include "trader_bot.h"

char *get_bot_name(void) {
    return "Fuel Bot";
}

void get_action(struct bot *b, int *action, int *n) {
    // pointer to bot location
    struct location *current = b->location;
	// pointer to at a location bot fuel 
    int current_fuel = b->fuel;
    // pointer to maximum bot fuel
    int max_fuel = b->fuel_tank_capacity;
    // pointer to maximum bot moves
    int max_moves = b->maximum_move;
	
    if (current->type != LOCATION_PETROL_STATION) {
        *action = ACTION_MOVE;
        if (nearest_fuel(b) <= max_moves) {
        	*n = nearest_fuel(b);
        } else {
        	*n = max_moves;
        }
    }
    if (current->type == LOCATION_PETROL_STATION) {
        if (current_fuel != max_fuel) {
            *action = ACTION_BUY;
            *n = max_fuel - current_fuel; 
        } else {
            *action = ACTION_MOVE;
            *n = max_moves;
        }
    }
}
