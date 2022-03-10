//program that orders three numbers from lowest on the left to the highest on the right
//Dean Hou Week 3
//z5163159

#include <stdio.h>

int main (void) {

	int x, y, z;
	
	printf("Enter integer: ");
	scanf("%d", &x);
	printf("Enter integer: ");
	scanf("%d", &y);
	printf("Enter integer: ");
	scanf("%d", &z);
	
	if (z<=y && y<=x) {
		printf("The integers in order are: %d %d %d\n", z, y, x);
	} else if (z<=x && x<=y) {
		printf("the integers in order are: %d %d %d\n", z, x, y);
	} else if (y<=z && z<=x) {
		printf("The integers in order are: %d %d %d\n", y, z, x);
	} else if (y<=x && x<=z) {
		printf("The integers in order are: %d %d %d\n", y, x, z);
	} else if (x<=y && y<=z) {
		printf("The integers in order are: %d %d %d\n", x, y, z);
	} else if (x<=z && z<=y) {
		printf("The integers in order are: %d %d %d\n", x, z, y);
	}
		
	return 0;
}
