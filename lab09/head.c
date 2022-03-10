// given a filename as argument prints the first 10 lines of the file
// if the file has less than 10 lines the entire file should be printed
// Dean Hou and Steven Ye week 9
// z5163159 and z5165199
// if input is -n no. filename.filetype, print out the first no. digits

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcmp

int main(int argc, char *argv[]) {
    int count = 0;// loop count
    int c; // character
    FILE *inputStream; // declaring input stream
    if (argc > 4) {
        printf("Too many arguments\n");
        return 1;
    } // error for too many arguments
    if (argc < 1) {
    	printf("Argument less than 1\n");
    } // error for too few arguments (doesn't work tho) :(
    if (strcmp(argv[1], "-n") == 0) { // comapres the first argument (argv[1] to -n, if matches returns 0
        inputStream = fopen(argv[3], "r"); // opens file
        if (inputStream == NULL) { 
            perror(argv[3]);
            return 1;
        } // print error if failed to read
        c = fgetc(inputStream); // gets the contents of the file each character at a time
        while (c != EOF && count < atoi(argv[2])) { // going through the string while it doens't end, and there is less than specified amount (counting \n)
            if (c == '\n') {
                count++;
            }
            fputc(c, stdout); // need to print out first, then find next 
            c = fgetc(inputStream);
        }
// possible error is extra or missing \n, need to be careful about where the count is, before or after printing the character
    } else { // same thing but for 10
        inputStream = fopen(argv[1], "r");
        if (inputStream == NULL) {
            perror(argv[1]);
            return 1;
        }
        c = fgetc(inputStream);
        while (c != EOF && count < 10) {
            if (c == '\n') {
                count++;
            }
            fputc(c, stdout);
            c = fgetc(inputStream);
        }
    }
    return 0;
}
