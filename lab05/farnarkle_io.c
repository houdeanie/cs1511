//program that reads sequence of tiles with scanning, and a function that prints out the tiles in a sequence 
//Dean Hou week 5
//z5163159

#include <stdio.h>
#include "farnarkle.h"

// read N_TILES tiles into array tiles
// return 1 if successful, 0 otherwise

int read_tiles(int tiles[N_TILES]) {

	int loopCount, value;
	loopCount = 0;
	while (loopCount < N_TILES ) {
		value = scanf("%d", &tiles[loopCount]); //check that there is a value for the scanf and that it is less than MAX_TILE
		if ((value != 1) || ((tiles[loopCount] < 0) && (tiles[loopCount] > MAX_TILE))) { //if there is no value or if the number is out of the bounds
			return 0;
		}
		loopCount++;
	}
    return 1; 
}

// print tiles on a single line or could not read tiles
void print_tiles(int tiles[N_TILES]) {
	
	int loopCount;
	loopCount = 0;
	while (loopCount < N_TILES){
		printf("%d ", tiles[loopCount]);
		loopCount++;
	}
	printf("\n");
}
