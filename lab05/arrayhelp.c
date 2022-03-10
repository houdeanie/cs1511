#include <stdio.h>

int main () {
	int array[2], i;
	i = 0;
	while (i < 2) {
		printf("enter number: ");
		scanf("%d", &array[i]);
		i++;	
	}
	
	return 0;
}

