// program that calculates the horizontal balance
// Dean Hou week 7
//z5163159

#include <stdio.h>
#include "captcha.h"

double get_horizontal_balance(int height, int width, int pixels[height][width]) {

	double column_sum = 0; // sum of the column indices of all black pixels
	int n_black_pixels = 0; // number of black pixels
	int row = 0;
	int col = 0;
	double horizontal_balance;

	while (row < height) {
		while (col < width) {
			if (pixels[row][col] == 1) {
				n_black_pixels++;
				column_sum = column_sum + col;
			}
			col++;
		}
		col = 0;
		row++;
	}
	
	horizontal_balance = (column_sum/n_black_pixels + 0.5)/width; // calculate balance

	return horizontal_balance;
}
