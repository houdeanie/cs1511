
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(int argc, char *argv[]) {
	int loopCount = 1;
	int array[MAX];
	
	while (loopCount < argc) {
		array[loopCount] = atoi(argv[loopCount]);
		loopCount++;
	}
	
	loopCount = 1;
	printf("Odd numbers were: ");
	while (loopCount < argc) {
		if (array[loopCount]%2 != 0) {
			printf("%d ", array[loopCount]);
		}
		loopCount++;
	}
	
	loopCount = 1;
	printf("\nEven numbers were: ");
	while (loopCount < argc) {
		if (array[loopCount]%2 == 0) {
			printf("%d ", array[loopCount]);
		}
		loopCount++;
	}
	printf("\n");
	return 0;
}
	
	

