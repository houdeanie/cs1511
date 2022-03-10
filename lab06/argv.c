// sum integers supplied as command line arguments
// no check that aguments are integers
// Andrew Taylor - andrewt@unsw.edu.au
// 24/4/13

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, sum;
    sum = 0;
    i = 1;
    while (i < argc) {
       sum = sum + atoi(argv[i][);
       i = i + 1;
    }
    printf("sum of command-line arguments = %d\n", sum);
    return 0;
}
