//program which prints out years that are leap years between an interval of years
//Dean Hou week 3
//z5163159

#include <stdio.h>
#include <math.h>

int main (void) {

	int year1, year2, i;
	
	printf("Enter start year: ");
	scanf("%d", &year1);
	
	printf("Enter finish year: ");
	scanf("%d", &year2);
	i= year1;
	printf("The leap years between %d and %d are: ", year1, year2);
	
	while (i >= year1 && i <= year2) {
	
		if (i%4 !=0) {
			//not leap year
		} else if (i%100 !=0) {
			printf("%d ", i);
		} else if (i%400 !=0) {
			printf("");
		} else { 
			printf("%d ", i);
		}
		i=i+1;
	}
	printf("\n");

	return 0;
}

