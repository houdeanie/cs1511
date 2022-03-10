//program which reads characters from its input and whrites characters in encrypted substitution output
//Dean Hou and Steven Ye week 6
//z5163159 and z5165199
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 9999
#define ABCD 26

void encode(char in[SIZE], char key[2][ABCD], char out[SIZE]) {
    int in_counter = 0;
    while (in_counter < SIZE) {                   //scans input character
        if (('a' <= in[in_counter] && in[in_counter] <= 'z') || ('A' <= in[in_counter] && in[in_counter] <= 'Z')) {  //Determines whether input is a character or not
            int comCount = 0;
            while (comCount < ABCD) {       //scans through alphabet
                if (in[in_counter] == key[0][comCount]) {        //see if input = alphabet
                    out[in_counter] = key[1][comCount];          //input matches command line alphabet and convert to output
                } else if (in[in_counter] == toupper(key[0][comCount])) {     //change to uppercase
                    out[in_counter] = toupper(key[1][comCount]);              
                }
                comCount++;
            }
        } else {
            out[in_counter] = in[in_counter];     //anything not a character remains unchange
        }
        in_counter++;
    }
}

int main(int argc, char *argv[]) {                  
    char in[SIZE] = {0};           //input array stores original
    char out[SIZE];                //output array stores encoded string
    char argument[ABCD];           //argument to store key
    char key[2][ABCD];             //declare an array of 2 rows, 26 columns
    
    strncpy(argument, argv[1], ABCD);      //copies the key from command line argument into argument
  	
  	int counter = 0;
    while (counter < ABCD) {
        key[0][counter] = counter + 'a';  //initialises alphabet array in alphabetical order in key [0]
        key[1][counter] = argument[counter];  //initialises command line argument in key [1]
    	counter++;
    }
    while (fgets(in, SIZE, stdin) != NULL) {
        encode(in, key, out);              //input changed to key and then create output using side function
        fputs(out, stdout);                //prints the encoded string
        
        //reset
        counter = 0;
        while (counter < SIZE) { //clear output
            out[counter] = 0; 
            counter++;
        }
    }
    return 0;
}*/

/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 9999
#define ABCD 26

int main (int argc, char *argv[]) { // allows program to read in a command line
	
	if (argc > 2 || argc < 1) {
		fprintf(stderr, "Not a valid enryption code\n");
	}
	char keyLower[ABCD + 1], keyUpper[ABCD + 1]; 
	char abc[] = {"abcdefghijklmnopqrstuvwxyz"}; // original sequence
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // original upper sequence
	// storing encryption
	int loop = 0;
	while (loop < ABCD) {
		keyLower[loop] = argv[1][loop];
		loop++;
	}
	// getting the upper case of the encryption
	loop = 0;
	while (loop < ABCD) {
		keyUpper[loop] = toupper(argv[1][loop]);
		loop++;
	}
	// check
	/*loop = 0;
	while (loop < ABCD) {
		printf("%c%c ", keyLower[loop], keyUpper[loop]);
		loop++;
	}
	printf("\n");
	loop = 0;
	while (loop < ABCD) {
		printf("%c%c ", abc[loop], ABC[loop]);
		loop++;
	}
	printf("\n");*/
	char c;
	int counter = 0;
	c = getchar();
	// encryption
	while (c != EOF) {
		if (c >= 'a' && c <= 'z') {
			while (counter < ABCD) {
				if (c == abc[counter]) {
					c = keyLower[counter];
					break;
				}
				counter++;
			}
		} else if (c >= 'A' && c <= 'Z') {
			while (counter < ABCD) {
				if (c == ABC[counter]) {
					c = keyUpper[counter];
					break;
				}
				counter++;
			}
		}
		putchar(c);
		c = getchar();
		counter = 0;
	}
	return 0;
}
