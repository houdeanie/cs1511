//program that reads characters from its input and print out the frequency of each of the 26 alphabet letters in input in decimal value, and in absolute numbers, with upper and lower cases counted together
//Dean hou and Steven Ye week 6
//z5163159 and z5165199
#include <stdio.h>

#define ABCD 26

int main(void) {
    //add counts the amount of times the chraacter appears, count is a reused loop
    int count = 0, add[ABCD] = {0};
    //percent is the middle thing, total is the total amount of letters
    double percent[ABCD] = {0}, total = 0;
    //arrays containing the alphabet both upper and lower
    char c, abc[] = {"abcdefghijklmnopqrstuvwxyz"}, ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    c = getchar();
    while (c != EOF) {
    	while (count < ABCD) { //as there are only 26 letters in alphabet
    		if ((c == abc[count]) || (c == ABC[count])) { //if c is in the alphabet
    			add[count] = add[count] + 1; //when count is a number, abc[1] is b, then add corresponding to that in add[1]
    			total++; //adds to total amount of letters, only counts letters
    		}
    		count++; //loop through alphabet, then letter must be found
    	}
    	c = getchar();
    	count = 0;
    	//reset
    }
	//counting percentage
	count = 0;
    while (count < ABCD) {
    	percent[count] = percent[count] + (add[count]/total);
    	count++;
    }
    //finally printing out the results
    count = 0;
    while (count < ABCD) {
    	printf("'%c' %f %d\n", abc[count], percent[count], add[count]);
    	count++;
    }
    return 0;
}

    
