// takes 3 arguments which creates a file containing specified integers, one per line
// Dean Hou and Steven Ye week 9
// z5163159 and z5165199
// first & second arguments will specify a range of integers
// third argument will specify the file to be created

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *outputStream; // declaring output strean
    int number;
    if (argc < 4) { // error if there is too much input in command line
        fprintf(stderr, "Usage: %s <number-start> <number-end> <file-name.file-type>\n", argv[0]);
        return EXIT_FAILURE; // failed to run
    }

    outputStream = fopen(argv[3], "w"); // else opens a file with name specified in argv[3], sets its contents as a string to the output stream
    number = atoi(argv[1]); // first number to start printing out
    while (number <= atoi(argv[2])) { // print out each number in new line until and including number in argv[2]
        fprintf(outputStream, "%d\n", number);
        number++;
    }
    fclose(outputStream); // close file
    return EXIT_SUCCESS; // successful run
}
