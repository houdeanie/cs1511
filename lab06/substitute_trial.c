#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 8000
#define ALPHABET_SIZE 26

void encode(char input[SIZE], char cipher[2][ALPHABET_SIZE], char output[SIZE]) {
    for (int in_counter = 0; in_counter < SIZE; in_counter++) {                   //Scans through each input character, one at a time
        if (('a' <= input[in_counter] && input[in_counter] <= 'z') || ('A' <= input[in_counter] && input[in_counter] <= 'Z')) {  //Determines whether input is a character or not
            for (int cla_counter = 0; cla_counter < ALPHABET_SIZE; cla_counter++) {       //Scans through alphabet array ('a' to 'z').
                if (input[in_counter] == cipher[0][cla_counter]) {                        //Matches current input character with same character in alphabet array.
                    output[in_counter] = cipher[1][cla_counter];                          //Then matches alphabet character to CLA character in the same array column, and thus assigns to an encoded output.
                } else if (input[in_counter] == toupper(cipher[0][cla_counter])) {        //If input is uppercase, this converts alphabet array to uppercase.
                    output[in_counter] = toupper(cipher[1][cla_counter]);                 //Matches accordingly (line 13).
                }
            }
        } else {
            output[in_counter] = input[in_counter];                                       //Anything not a character remains unchanged.
        }
    }
}

int main(int argc, char *argv[]) {                                 //Prepare for cipher to be entered into CLA.
    char input[SIZE];                                              //Input array stores my original string.
    char output[SIZE];                                             //Output array stores my encoded string.
    char cla[ALPHABET_SIZE];                                       //Prepare CLA array to store my cipher.
    char cipher[2][ALPHABET_SIZE];                                 //Declare an array of 2 rows, 26 columns.
    strncpy(cla, argv[1], ALPHABET_SIZE);                          //Copies the cipher from command line argument into my CLA array.
    
    for(int counter = 0; counter < SIZE; counter++) {              //Initialises all input elements to 0.
        input[counter] = 0;
    }
    for(int counter = 0; counter < ALPHABET_SIZE; counter++) {
        cipher[0][counter] = counter + 'a';                        //Initialises alphabet array in alphabetical order: {a, b, c, ... y, z}
        cipher[1][counter] = cla[counter];                         //Initialises CLA array in desired user order:      {y, d, e, ... w, j}
    }
    while (fgets(input, SIZE, stdin) != NULL) {
        encode(input, cipher, output);                             //Input + cipher >>> output
        fputs(output, stdout);                                     //Prints the encoded string.
        for (int counter = 0; counter < SIZE; counter++) {
            output[counter] = 0;                                   //Reset all output elements to 0 to prepare for next encoded output.
        }
    }
    return 0;
}
        
