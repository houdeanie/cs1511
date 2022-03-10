#include <stdio.h>
#include <math.h>
#define MAX 1000

int main (void) {
    int array[MAX]; // storage array
    int loop1 = 0; // loop counter part 1
    int loop2 = 0; // loop counter part 2
    int limit; // largest value at which input is stopped
    int sentinelVariable = 1; // loop breaker
    int indiNum = 1;

    // store input
    while ((scanf("%d", &array[loop1]) != EOF) && (loop1 < MAX)) {
        loop1++;
    }
    limit = loop1;
    //printf("%d \n", limit);

    // test input for divisibility
    printf("Indivisible numbers: ");
    loop1 = 0;
    while (loop1 < limit) {
        while (loop2 < limit && sentinelVariable != 0) {
        	sentinelVariable = 1;
        	if (loop1 != loop2 && array[loop1] == array[loop2]) {
            	sentinelVariable = 0;
            	indiNum = 0;
            }
            if (array[loop1] != array[loop2]) {
               	if (array[loop1] > array[loop2] && (array[loop1]%array[loop2]) == 0) {
                   	sentinelVariable = 0;
               	} else {
                   	indiNum++;
               	}
            }
            loop2++;
            //printf("%d \n", indiNum);
        }
        //printf("%d\n", indiNum);
        if (indiNum >= limit - 1)  {
            printf("%d ", array[loop1]);
        }
        loop1++;
        loop2 = 0;
        indiNum = 0;
        sentinelVariable = 1;
    }
    printf("\n");
    return 0;
}
