// program which prints the input image using * and .
// Dean Hou week 7
// z5163159 

#include <stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]){

	int col = 0;
	int row = height - 1;
	
	while (row >= 0) { // loop through rows 
		while (col < width) { // looop through columns
			if (pixels[row][col] == 1) { //replace 0 with . and 1 with *
				printf("*");
			} else if (pixels[row][col] == 0) {
				printf(".");
			}
			col++;
		}
		printf("\n"); //new line after looping
		row = row - 1;
		col = 0;
	}
}
	
	
			
