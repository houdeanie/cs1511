//program that can read an positive integer then print out the cubes from 1 to n
//Dean Hou week3
//z5163159

#include <stdio.h>

int main (void) {
	
	int value, n, sum;
	
	n=1;
	printf("Enter how many cubes: ");
	scanf("%d", &value);
	
	while (n <= value) {
		sum=n*n*n;
		printf("%d^3 = %d\n", n, sum);
		n=n+1;
	
	}
	
	return 0;
}
