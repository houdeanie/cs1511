// program that reads ten

#include <stdio.h>

int main (void) {
	
	int array[10];
	int count = 0;
	
	while (count < 10 && (scanf("%d\n", &array[count]) != 0)) {
		count = count + 1;
	}
	
	count = 0;
	printf("Numbers were: ");
	while (count < 10) {
		printf("%d ", array[count]);
		count = count + 1;
	}
	printf("\n");
	
	return 0;
}
