// Dean Hou and Steven Ye week 9
// z5163159 and z5165199
// program which reads in a string from standard input and writes out the characters one per line

#include <stdio.h>

#define MAX 4096 // maximum amount of digits

int main (void) {
    char line[MAX];
    int i = 0;

    printf("Enter a string: ");
    if (fgets(line, MAX, stdin) != NULL) { // gets a string of characters and stores them in array (line)
        while (i < MAX && line[i] != '\n') { // printing out each line as a character and stping when new line reached
            printf("%c\n", line[i]);
            i++;
        }
    }
    return 0;
}
