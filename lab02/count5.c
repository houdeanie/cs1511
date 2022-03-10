//program that converts numbers up to five into words
//Dean Hou week 2 lab 
//z5163159

#include <stdio.h>

int main (void) {
	int x;
	printf("Please enter an integer: ");
	scanf("%d", &x);

	
	if (x < 1) {
		printf("You entered a number less than one.\n");
	} else if (x> 5) {
		printf("You entered a number greater than five.\n");
	} else if (x==1 ) {
		printf("You entered one.\n");
	} else if (x==2 ) {
		printf("You entered two.\n");
	} else if (x==3 ) {
		printf("You entered three.\n");
	} else if (x==4 ) {
		printf("You entered four.\n");
	} else if (x==5 ) { 
		printf("You entered five.\n");
	}

	return 0;
}

