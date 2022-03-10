#include <stdio.h>
#include "farnarkle.h"

int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]) {
	
    int arkles, i, j, array[N_TILES];
    //checking for all arkles including farnarkles, but need to implement remove double measure
    i = 0;
    j = 0;
    arkles = 0;
    while (i < N_TILES) {
    	while (j < N_TILES) {
    		if (sequence1[i] == sequence2[j]) {
    			arkles++;
    			break;
    		}
    		j++;
    	}
    	i++;
    	j = 0;
    }
	//farnarkles
	int farnarkles;
	i = 0;
	farnarkles = 0;
	while (i < N_TILES) { 
		if (sequence1[i] == sequence2[i]) {
			farnarkles = farnarkles + 1;
		}
		i++;
	}
	
   	arkles = (arkles - farnarkles);
    return arkles;
}
