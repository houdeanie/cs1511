//program that reads a year then prints out whether or not it is a leap year
//Dean Hou week 3
//z5163159

#include <stdio.h> 
#include <math.h>

int main (void) {
	
	int year;
	
	printf("Enter year: ");
	scanf("%d", &year);

	if (year%4 !=0 || ) {
		printf("%d is not a leap year.\n", year);
	} else if (year%100 !=0) {
		printf("%d is a leap year.\n", year);
	} else if (year%400 !=0) {
		printf("%d is not a leap year.\n", year);
	} else { 
		printf("%d is a leap year.\n", year);
	}
	
	return 0;
}

	
