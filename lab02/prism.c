// C program that calculates volume, surface area and total edge length of a rectangle prism
// Written week 2 lab
// by Dean Hou (z5163159@cse.unsw.edu.au)
// for COMP1511 Lab 02 Exercise 1


#include <stdio.h>

int main (void) {
	int length, width, height, volume, area, edgeLength;
	printf("Please enter prism length: ");
	scanf("%d", &length);
	printf("Please enter prism width: ");
	scanf("%d", &width);	
	printf("Please enter prism height: ");
	scanf("%d", &height);

	printf("A prism with sides %d %d %d has:\n", length, width, height);
	volume = length*width*height;
	printf("Volume      = %d \n", volume);

	area = (length*width + length*height +width*height)*2;
	printf("Area        = %d\n", area);

	edgeLength = (length + height + width)*4;
	printf("Edge length = %d\n", edgeLength);

	return 0;
}
