//program to find the area of rectangle
//Dean hou 10/03/2017

#include <stdio.h>

int main (void) {

	int length, width, area;
	printf("Please enter rectangle length: ");
	scanf("%d", &length);
	printf("Please enter rectangle width: ");
	scanf("%d", &width);
	
	area = length*width;

	printf("Area = %d\n", area);

	return 0;
}
