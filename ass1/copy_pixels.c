// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 22/04/2017
// credit: lab partner steven ye and me
// function that copies bounding box array into pixels array, easier to call

#include <stdio.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width], int start_row, int start_column, int copy_height, int copy_width, int copy[copy_height][copy_width]) {
	// copy_height and copy_width is width and height of bounding box
	int pixels_row = start_row;
	int pixels_col = start_column;
	int copy_row = 0;
	int copy_col = 0;
	
	while (pixels_row < (start_row + copy_height) && copy_row < copy_height) { // making sure arrays are inside their bounds
		while (pixels_col < (start_column + copy_width) && copy_col < copy_width) {
			copy[copy_row][copy_col] = pixels[pixels_row][pixels_col]; // output = input
			pixels_col = pixels_col + 1; //increment both cols by one
			copy_col = copy_col + 1;
		}
		pixels_row = pixels_row + 1; // increment both rows by one
		copy_row = copy_row + 1;
		pixels_col = start_column; // pixels must be at start of bounding both column i.e. start_column
		copy_col = 0; // reset
	}
}
