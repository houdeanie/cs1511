// Dean Hou and Steven Ye week 9
// z5163159 and z5165199
// palindrome checks if string is palindromic

#include <stdio.h>

#define MAX_LINE_INPUT 4069
int main (void) {
    char line[MAX_LINE_INPUT];
    int loopCount = 0;
    int length = 0;

    printf("Enter a string: ");
    fgets(line, MAX_LINE_INPUT, stdin);
        // find length of string
    while (line[loopCount] != '\n') {
        length++;
        loopCount++;
    }
    
    loopCount = 0;
    while (loopCount < length) { // check for palindromicity or wutever, going backwards from last char and forwards from first char, compare
        if (line[loopCount] != line[length - loopCount - 1]) { // if not equal then not palindrome
            printf("String is not a palindrome\n");
            return 0;
        }
        loopCount++;
    }
    printf("String is a palindrome\n"); // else palindrome (assuming)
    return 0;
}
