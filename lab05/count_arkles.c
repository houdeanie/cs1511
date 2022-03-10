//a program that uses the farnarkle.h function to count number of arkles in the guessed numbers, and first check for farnarkles, and check for arkles excluding doubles 
//Dean Hou week 5
//z5163159

#include <stdio.h>
#include "farnarkle.h"

//creating a side function that can copy the original sequences to backups
void copy(int input[N_TILES], int output[N_TILES]) {
	int count = 0;
	while (count < N_TILES) {
		output[count] = input[count];
		count++;
	}
}
//main function that counts arkles
int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]) {
	int arkles, loopCount1, loopCount2, original1[N_TILES], original2[N_TILES]; //original1 is backup for sequence1- hidden, original2 is for sequence2- guess
	//using side function to copy sequence 1 and 2 to backups
    copy(sequence1, original1);
    copy(sequence2, original2);
    
    loopCount1 = 0;
    while (loopCount1 < N_TILES) { //test for if farnarkle, if farnarkle, sequence1 and 2 values set to zero
    	if (sequence1[loopCount1] == sequence2[loopCount1]) {
    		//destroy numbers that are identical i.e set them to zero
    		sequence1[loopCount1] = 0;
    		sequence2[loopCount1] = 0;
    	}
    	loopCount1++;
    }
    
    // test for arkles
    loopCount1 = 0;
    loopCount2 = 0;
    arkles = 0;
    //looping through each hidden tile comparing one hidden tile to each guess tile
    while (loopCount1 < N_TILES) {
    	//cycling through each guess tile
    	while (loopCount2 < N_TILES) {
    		if (sequence1[loopCount1] == sequence2[loopCount2] && sequence1[loopCount1] != 0) { //condition where if guess tile and hidden tile are equal, destroy them, but not counting already 0 value tiles
    			arkles = arkles + 1; 
    			sequence1[loopCount1] = 0;
    			sequence2[loopCount2] = 0;
    		}
    		loopCount2++;
    	}
    	loopCount2 = 0;
    	loopCount1++;
    }
    //return sequences to original values
    copy(original1, sequence1);
    copy(original2, sequence2);
    
    return arkles; 
}

