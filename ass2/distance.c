// Dean Hou z5163159
// z5163159@student.unsw.edu.au
// Tutor: Alexander Rowell
// last edited 31/07/15

// functions that find various distances of locations

#include "trader_bot.h"
#include "trader_functions.h"
#include <stdio.h>
#include <string.h>
// sentinel variable values
#define TRUE 1
#define FALSE 0
// total min turns to buy, move, sell
#define TURNS_TO_MAKE_PROFIT 3
// find distance of the world of the trader bot
// starting location is not always LOCATION_START
int world_distance(struct bot *b) {
	struct location *current = b->location; 
	struct location *start = b->location; 
	int repeat = FALSE;
	int distance = 0; 

	// loop that goes through the struct location list
	while (repeat == FALSE) { 
		distance++;
		current = current->next; 
		if (current == start) { 
			repeat = TRUE;
		}
	}
	return distance;
}

//function compares amount of turns needed to buy and sell to the amount of turns left in the game
// takes three turns to buy, move then sell, assuming at seller, otherwise more turns
// only if cargo is NULL
int last(struct bot *b) {
	int turnsLeft = b->turns_left;
	if (turnsLeft < TURNS_TO_MAKE_PROFIT && b->location->type != LOCATION_BUYER) {
		// do not buy anything
		return FALSE;
	} else {
		return TRUE;
	}
}

// finds the amount of moves to go to the location with the name given
int shortest_distance(struct bot *b, char *locationName) {
	struct location *currentLocation = b->location; 
	struct location *startingLocation = b->location; 
    int movesForwards = 0, movesBackwards = 0, shortestDistance;
	int stop = FALSE;
	if (locationName != 0) {
		// going forwards
		while (stop == FALSE) { // while not at the location with locationName name, keep moving forwards
			if (strcmp(currentLocation->name, locationName) == 0) {
				stop = TRUE;
			} else {
				movesForwards++;
				currentLocation = currentLocation->next;
			}
			if (currentLocation == startingLocation) { // if cycled through whole world and still not found 
				movesForwards = 0;
				break;
			}
		}
		// going backwards, reset current location and stop
		currentLocation = startingLocation; 
		stop = FALSE;
		while (stop == FALSE) { // while not at the location with locationName name, keep moving backwards
			if (strcmp(currentLocation->name, locationName) == 0) {
				stop = TRUE;
			} else {
				movesBackwards++;
				currentLocation = currentLocation->previous;
			}
			if (currentLocation == startingLocation) { // if cycled through whole world and still not found 
				movesBackwards = 0;
				break;
			}
		}
		if (movesBackwards < movesForwards) { // determine the shortest distance
			shortestDistance = -movesBackwards;
		} else {
			shortestDistance = movesForwards;
		}
		return shortestDistance;
	} else {
		return FALSE;
	}
}



