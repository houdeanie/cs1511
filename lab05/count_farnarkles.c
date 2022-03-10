//program that counts number of farnarkles
//Dean Hou & Steven Ye week 5 
//z5163159 & z5165199
#include <stdio.h>
#include "farnarkle.h"


// return number of farnarkles
int count_farnarkles(int sequence1[N_TILES], int sequence2[N_TILES]) {

	int farnarkles, i;
	i = 0;
	farnarkles = 0;
	while (i < N_TILES) { //see if the array at number i is the same, then add one farnarkle
		if (sequence1[i] == sequence2[i]) {
			farnarkles = farnarkles + 1;
		}
		i++;
	}
	//count_farnarkles(hidden_sequence, guess) = farnarkles
    return farnarkles; 
}

