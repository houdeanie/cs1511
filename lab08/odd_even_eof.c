#include <stdio.h>
#define MAX 1000
int main (void) {

	int loopCount = 0;
	int array[MAX];
	int limit;
	
	while (loopCount < MAX && (scanf("%d", &array[loopCount]) != EOF)) {
		loopCount++;
	}
	limit = loopCount;
	
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
