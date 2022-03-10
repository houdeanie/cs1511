
#include <stdio.h>

#define MAX 1000

int main (void) {
	int limit;
	int loopCount = 0;
	int stopLoop = 1;
	int array[MAX];
	
	while (loopCount < MAX && stopLoop != 0) {
		scanf("%d", &array[loopCount]);
		if (array[loopCount] < 0) {
			stopLoop = 0;
			limit = loopCount;
		}
		loopCount++;
	}
	
	loopCount = 0;
	printf("Odd numbers were: ");
	while (loopCount < limit) {
		if (array[loopCount]%2 != 0) {
			printf("%d ", array[loopCount]);
		}
		loopCount++;
	}
	
	loopCount = 0;
	printf("\nEven numbers were: ");
	while (loopCount < limit) {
		if (array[loopCount]%2 == 0) {
			printf("%d ", array[loopCount]);
		}
		loopCount++;
	}
	printf("\n");
	return 0;
}
