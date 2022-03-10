//program which decrypts text encrypted by substitution.c
//Dean Hou and Steven Ye week 6 
//z5163159 and z5165199
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 9999
#define ABCD 26

void decode(char in[SIZE], char key[2][ABCD], char out[SIZE]) {
    int counter1 = 0;
    while (counter1 < SIZE) {      //scans through each input character 
        if((in[counter1] >= 'a' && in[counter1] <= 'z') || (in[counter1] >= 'A' && in[counter1] <= 'Z')) {
            int counter2 = 0;
            while(counter2 < ABCD) { 
                //for lower case characters
                if(in[counter1] == key[0][counter2]) { 
                    out[counter1] = key[1][counter2];     
                    //use the array to map the subbed lowercase onto the output array
                    break;
                //checking for uppercase characters using toupper function
                } else if(in[counter1] == toupper(key[0][counter2])) {
                	out[counter1] = toupper(key[1][counter2]);
                    break;
                }
                counter2++;
            }
        //if not part of the alphabet, just directly output character
        } else {
            out[counter1] = in[counter1];
        }
        counter1++;
    }
} 

//main function
int main(int argc, char *argv[]) {
    
    char key[2][ABCD];  //code key       
    char in[SIZE] = {0};		//input and initialising
    char out[SIZE] = {0};		//outputs and initialising
    char argument[ABCD];

    //array argument <--- command line string
    strncpy(argument,argv[1],ABCD); //copying to command line argument string to the "argument" array

    int counter = 0;
    //populating key with normal and substitutional alphabet
    while(counter < ABCD) {
        key[1][counter] = counter + 'a';   //writes a-->z into the first row
        key[0][counter] = argument[counter];  //write the jumbled up alphabet into the second row
        counter++;
    }

    //inputting user sequence
    while(fgets(in, SIZE, stdin) != NULL) {
        //encoding the string
        decode(in,key,out); //calling the decode function which maps the characters
        fputs(out,stdout);     //printing out the decoded output

        //reset
        counter = 0;
        while(counter < SIZE) {
            out[counter] = 0;      //new output      
            counter++;
        }
    }

    return 0;
}
