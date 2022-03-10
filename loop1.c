//print a square of 10x10 asterisks

#include <stdio.h>

int main (void) {
	int i, j;

	i=0;
	while (i < 10)  {
	j=0;
	
	while (j<10) {
		printf("* ");
		j=j+1;
	}
	
	printf("\n");
	i=i+1;
	}

	return 0;
}
