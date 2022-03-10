//program which calculates the range of ages that a person should be dating
//Dean Hou week 2 lab
//z5163159


#include <stdio.h>

int main (void){
	int age, lower, upper;
	
	printf("Enter your age: ");
	scanf("%d", &age);
	
	lower = (age/2) + 7;
	upper = 2*(age - 7); 
	
	if (lower > upper) {
		printf("You are too young to be dating.\n");
	} else {
		printf("Your dating range is %d to %d years old.\n", lower, upper);
	}
	
	return 0;
}
	
