// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 03/06/15

// functions realted to fuel
// printf for debugging
#include "trader_bot.h"
#include "trader_functions.h"
#include <stdio.h>
#include <stdlib.h>
// for sentinel variable values
#define TRUE 1 
#define FALSE 0 
// program finds distance to nearest fuel station which doens't have no fuel
// from lab10- credit to Isheeta Sinha- lab partner
int nearest_fuel(struct bot *b) {
    struct location *currentLocation = b->location; // pointer to  current location 
	struct location *startingLocation = b->location; // pointer to start
    int movesForwards = 0, movesBackwards = 0, nearestFuel;
	int stop = FALSE;
	// going forwards
	while (stop == FALSE) { // while not fuel station
		if (currentLocation->type == LOCATION_PETROL_STATION && currentLocation->quantity != 0) { // check where petrol station with fuel to sell
			stop = TRUE;
		} else {
			movesForwards++;
			currentLocation = currentLocation->next; // continue cycling forwards through world
		}
		if (currentLocation == startingLocation) { // if cycled through and no fuel stations return movements forwards == 0
			movesForwards = 0;
			break;
		}
	}
	// going backwards, reset current location and sentinel variable
	currentLocation = startingLocation; 
	stop = FALSE;
	while (stop == FALSE) { // while not at fuel station with quantity of fuel to sell
		if (currentLocation->type == LOCATION_PETROL_STATION && currentLocation->quantity != 0) {
			stop = TRUE; // stop loop if found
		} else {
			movesBackwards++;
			currentLocation = currentLocation->previous; // cycling backwards through world
		}
		if (currentLocation == startingLocation) { // stop if reached start again
			movesBackwards = 0;
			break;
		}
	}
	if (movesBackwards < movesForwards) { // determine the nearest fuel station with fuel
		nearestFuel = -movesBackwards;
	} else {
		nearestFuel = movesForwards;
	}
    return nearestFuel;
}

// function that returns whether the nearest PETROL_STATION_LOCATION is within range of the next move
// see if the next move will leave the bot stranded away from a fuel station
// returns true or false 
int stranded(struct bot *b, int nextMove) {
	struct location *curr = b->location;
	int fuel = b->fuel;
	int nearestFuelStation = nearest_fuel(b); // find nearest fuel station
	/*if (abs(nextMove) > b->maximum_move) {
		nextMove = b->maximum_move;
	}*/
	if (fuel - abs(nextMove) >= abs(nearestFuelStation)) { // if next move will move it away so nearest fuel station is still in reach
		return FALSE;
	} else {
		return TRUE;
	}
}
