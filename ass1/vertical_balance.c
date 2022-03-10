// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 20/04/2017
// function that finds the vertical balance of a single digit

#include <stdio.h>
#include "captcha.h"

double get_vertical_balance(int height, int width, int pixels[height][width]) {

	double row_sum = 0; // sum of the row indices of all black pixels
	int n_black_pixels = 0; // number of black pixels
	int row = 0;
	int col = 0;
	double vertical_balance;

	while (row < height) {
		while (col < width) {
			if (pixels[row][col] == 1) {
				n_black_pixels++;
				row_sum = row_sum + row;
			}
			col++;
		}
		col = 0;
		row++;
	}
	
	vertical_balance = (row_sum/n_black_pixels + 0.5)/height;

	return vertical_balance;
}
