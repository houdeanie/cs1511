//a main function that uses create randon tiles function to create the hidden tiles and then allows user to play farnarkle
//Dean Hou week 5 
//z5163159
#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES];
	//creates a hidden sequence
    create_random_tiles(hidden_sequence);
    int guess[N_TILES];
    //create loop for to play farnarkle
    int guessNo = 1;
	while (guessNo > 0) {
    	printf("Enter guess for turn %d: ", guessNo);
    	//check for valid guess
    	if (read_tiles(guess) != 1) {
        	printf("Could not read guess\n");
        	return 1;
    	}
    	//display farnarkels and arkles reading from count_arkles and count_farnarkles
    	printf("%d farnarkles ", count_farnarkles(hidden_sequence, guess));
    	printf("%d arkles\n", count_arkles(hidden_sequence, guess));
    	//victory condition if all farnarkles found
    	if (count_farnarkles(hidden_sequence, guess) == N_TILES) {
    		printf("You win\n");
    		return 0; //only condition to end function otherwise repeat
    	}
    	guessNo++;
    }
}
