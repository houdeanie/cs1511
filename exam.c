//exam marks
//Dean Hou 10/03/2017

#include <stdio.h>

int main (void) {

	int mark;

	printf("Enter your mark: ");
	scanf("%d", &mark);
	
	if (mark >= 50 && mark <=100) {
	printf("You PASSED!!!!!!\n");
	} else if (mark <50 && mark >=0) {
	printf("Failure...\n");
	} else if (mark < 0 || mark > 100) {
	printf("ERROR\n");
	}
	return 0;
}

	

