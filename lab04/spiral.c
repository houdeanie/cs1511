//program that reads an integer n and prints an nxn pattern of asterisks and dashes in the shape of a spiral
//Dean Hou week 4
//z5163159

#include <stdio.h>

int main (void) {

	int n, loopCount, rows, columns;
	
	printf("Enter size: ");
	scanf("%d", &n);
	
	loopCount = 1
	
	while (loopCount <= n) {
		if (n%loopCount != 0) {
			printf("*");
		} else {
			printf("-");
	}
	return 0;
}
