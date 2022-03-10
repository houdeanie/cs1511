#include <stdlib.h>
#include <stdio.h>

int is_monochrome(int height, int width, int pixels[height][width]) {
	//make sure everything in the pixels is 1 or 0
	int row, col;

	while  (col < width) {
		while (row < height) {
			if (pixels[row][col] != 0 && [pixels[rows][col] != 1) {
				return 0;
			}
			row = row + 1;
		}
		col = col + 1;
	}
	return 1;
}

	
