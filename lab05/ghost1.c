#include <stdio.h> 
#include "farnarkle.h"
//Reading the tiles and determining whether they are valid// 
int read_tiles(int tiles[N_TILES]) {
    int number; //Using this for testing whether array element is valid
    for(int counter=0;counter<N_TILES;counter++) { //This loop uses counter to go through each number in the array
        for(number=1;number<10;number++) { //This loop uses "number" to check if the array contains a number between 1 and 9
            if(tiles[counter] == number) { //If the array possesses a number between 1 and 9, it will break the for loop early
                break; //If it breaks early, number!=10, otherwise it will increment to number==10, meaning tile cannot be read
            }
        }
        if(number==10) { //If "number" reaches 10, then it has read an invalid tile
            return 0; //Returns read_tiles as 0 and terminates the function
        }
    }
    return 1; //If the loops have been passed successfully, it means all tiles are valid, thus return 1
}
//Printing out the tiles// 
void print_tiles(int tiles[N_TILES]) { //Runs if read_tiles returns 1
    for(int counter=0;counter<N_TILES;counter++) { //Goes through each part of the array and prints them out
        printf("%d ",tiles[counter]);
    }
    printf("\n");
}
