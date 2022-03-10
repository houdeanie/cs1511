// program that finds the smallest box containing the number
// Dean Hou week 7
// z5163159

#include <stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width], int *start_row, int *start_column, int *box_height, int *box_width) {
	int row = height - 1;
	int col = 0;
	// to find the box_height and box_width
	int last_row = 0;
	int last_column = 0;
	
	// initially set start_column and start_row to maximum, hence can only get lower
	*start_column = width;
	*start_row = height;
	
	while (row >= 0) { //going from top to bottom
		while (col < width) { // going from left to right
			if (pixels[row][col] == 1) {
				if (col < *start_column) { // if the pixels is 1 and is smaller than previous start_column
					*start_column = col;
				}
				if (col > last_column) { // largest column wth pixels still 1
					last_column = col;
				}
				if (row < *start_row) { // if pixels is 1 and smaller than previous row, should find final row going top to bottom
					*start_row = row;
				}
				if (row > last_row) { // largest row with pixels still 1
					last_row = row;
				}
			}
			col = col + 1;
		}
		row = row - 1;
		col = 0;
	}
	// accounting for extra one not counted
	*box_height = last_row - *start_row + 1;
	*box_width = last_column - *start_column + 1;
}
	
	
	
