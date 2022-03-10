
#include <stdio.h>

int main (void) {
	int array[10];
	int i =0;
	
	while (i < 10 && (scanf("%d", &array[i]) != 0)) {
		i++;
	}
	i = 0;
	printf("Odd numbers were: ");
	while (i < 10) {
		if (array[i]%2 != 0) {
			printf("%d ", array[i]);
		}
		i++;
	}
	i = 0;
	printf("\nEven numbers were: ");
	while (i < 10) {
		if (array[i]%2 == 0) {
			printf("%d ", array[i]);
		}
		i++;
	}
	printf("\n");
	return 0;
}
