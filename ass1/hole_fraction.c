// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 30/04/2017
// a function that finds area of white pixels in holes as a fraction of bounding box

// first find hole, remember start and end column and rows
#include <stdio.h>
#include "captcha.h"

// largely copied from holes.c 
double get_hole_fraction(int height, int width, int pixels[height][width]) {
	int n_white_pixels = 0;
	int row = (height - 1), col = 0;
	int remcol1, remcol2; // remember column number of beginning and end of hole sides 1000001
	int remrow1 = 0, remrow2 = 0; // remember the row at which the hole stats and ends
	int white[2] = {0, 0}; // storing n_white pixels to check for hole, max two holes in a digit, hence [2]
	int loopCount = 0; // loopcount for white[2]
	int BWW = 0, WWB = 0, BWB = 0, upper = 0, lower = 0, upcheck = 0, lowcheck = 0, holes = 0;
	// printf("%d %d \n", height, width);
    while (row >= 0) {
	    while (col < width) {
			// printf("%d", pixels[row][col]);
			if (row != 0 && row != height - 1 && col != 0 && col != width -1) {
				if (pixels[row][col] == 1 && pixels[row][col - 1] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 110
					BWB = 1;
					remcol1 = col;
				} else if (pixels[row][col] == 1 && pixels[row][col + 1] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 11000011
					WWB = 1;
					remcol2 = col - 1;
				}
			}
			col++;
		}
        if (BWW == 1 && WWB == 1 && BWB == 1) {// checking for BBB pattern above and below, hence enclosed white region
			n_white_pixels = white[loopCount];
			// printf(" A: %d ", white[loopCount]);
			if (upper != 1 && row != height - 1) {
				col = remcol1;
				upcheck = 0;
				while (col <= remcol2) {
					if (pixels[row + 1][col] == 1) {
						upcheck++;
					}
					if (upcheck == (remcol2 - remcol1 + 1)) {// add  white pixels in start row
						upper = 1;
						remrow1 = row;
						col = remcol1;
						while (col <= remcol2) {
							if (pixels[row][col] == 0) {
								n_white_pixels++;
							}
							col++;
						}
					}
					col++;
				}	
			}
			// printf("| %d |", n_white_pixels);
			if (upper == 1 && lower != 1 && row != 0) { // if not a hole but still checking
				lowcheck = 0;
				col = remcol1;
				while (col <= remcol2) {
					if (pixels[row - 1][col] == 1) {
						lowcheck++;
					}
					if (lowcheck == (remcol2 - remcol1 + 1)) {
						lower = 1;
						remrow2 = row;
						col = remcol1;
						while (col <= remcol2) {
							if (pixels[row][col] == 0) {
								n_white_pixels++;
							}
							col++;
						}
					}
					col++;
				}
			}
			if (upper == 1 && lower != 1 && row != remrow1 && row != remrow2) {// not including upper and lower as already accounted for
				col = remcol1; // for white pixels in between upper and lower columns
				while (col <= remcol2) {
					if (pixels[row][col] == 0) {
						n_white_pixels++;
					}
					col++;
				}
			}
			white[loopCount] = n_white_pixels; // store in white
			// printf("| %d |", n_white_pixels);
			// printf(" %d %d ", upper, lower);
			if (upper == 1 && lower == 1 && remrow1 != remrow2) { // hole confirmed
				holes++;
				loopCount++;// go to next white array to store
				lower = 0;
				upper = 0;
			}
		} else if (WWB != 1 || BWB != 1) {
			// printf(" WBW ");
			upper = 0;
			lower = 0;
			white[loopCount] = 0; // if not a hole, get rid of accumulated n_white_pixels
		}
		// printf("A: %d ", white[loopCount]);
		// printf("\n");
		row = row - 1;
		col = 0;
		BWW = 0;
		BWB = 0;
		WWB = 0;
	}
	if (holes == 0) { // no holes, not white pixels in hole
		n_white_pixels = 0;
	}
	loopCount = 0;
	while (loopCount < 2) { // total white pixels
		n_white_pixels = n_white_pixels + white[loopCount];
		loopCount++;
	}
	// printf(" %d ", n_white_pixels);
	// printf("\n");
	double hole_fraction;
    hole_fraction = (double)n_white_pixels/(height*width);
    return hole_fraction;
} 
	
	
	
	
