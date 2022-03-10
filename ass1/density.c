// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 20/04/2017
// function that finds the density of black pixels in bounding box

#include <stdio.h>
#include "captcha.h"

double get_density(int height, int width, int pixels[height][width]) {

	int row = 0;
	int col = 0;
	double n_black_pixels = 0;
	double density;

	while (row < height) {
		while (col < width) {
			if (pixels[row][col] == 1) {
				n_black_pixels++;
			}
			col++;
		}
		col = 0;
		row++;
	}

	density = n_black_pixels/(height*width);
	
	return density; 
}
