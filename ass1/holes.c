// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 30/04/2017
// function that finds amount of holes in a digit

// printfs for debugging
// idea: go row from row, from top to bottom, check sides of a hole
// possible hole, check for upper and lower bounds, then comfirm or not 
#include <stdio.h>
#include "captcha.h"

int get_holes(int height, int width, int pixels[height][width]) {
	int row = height - 1;
	int col = 0;
	int remcol1, remcol2; // remember column number of beginning and end of hole sides 1000001
	int remrow1, remrow2; // remember row number of top and bottom
	int BWW = 0, WWB = 0, BWB = 0;
	int upper = 0, lower = 0;
	int upcheck = 0, lowcheck = 0; // to check if there is a cap and a base
	int holes = 0;
	
	// hole must be at least layered in 2 black pixels
	while (row >= 0) { // finds the places of the first and last 0 in a possible hole
		while (col < width) {
			// printf("%d", pixels[row][col]);
			if (row != 0 && row != height - 1 && col != 0 && col != width - 1) {
				if (pixels[row][col] == 1 && pixels[row][col - 1] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 00010
					BWB = 1;
					remcol1 = col;
				} else if (pixels[row][col] == 1 && pixels[row][col + 1] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 00011000011
					WWB = 1;
					remcol2 = col - 1;
				}
			}
			col++;
		}
		if (BWW == 1 && WWB == 1 && BWB == 1) {// checking for BBB pattern above and below, hence enclosed white region
			// printf(" BWB "); 
			// printf(" %d %d %d ", BWW, BWB, WWB);
			// printf(" remcol1 %d remcol2 %d ", remcol1, remcol2);
			// printf("row: %d ", row);
			// printf("check: %d ", remcol2 - remcol1 + 1);
			if (upper != 1 && row != height - 1) { // checking upper bounds
				col = remcol1;
				upcheck = 0;
				while (col <= remcol2) {
					// printf("%d", pixels[row + 1][col]);
					if (pixels[row + 1][col] == 1) {
						upcheck++;
					/*} else if (pixels[row + 1][col] == 0) {
						upcheck = 0; */
					}
					if (upcheck == (remcol2 - remcol1 + 1)) {
						upper = 1;
						remrow1 = row;
						// printf(" %d ", upcheck);
					}
					col++;
					// printf(" %d ", col);
				}	
			} else if (upper == 1 && lower != 1 && row != 0) {// checking lower bounds
				lowcheck = 0;
				col = remcol1;
				while (col <= remcol2) {
					//printf("%d", pixels[row - 1][col]);
					if (pixels[row - 1][col] == 1) {
						lowcheck++;
					/*} else if (pixels[row - 1][col] == 0) {
						lowcheck = 0;*/
					}
					if (lowcheck == (remcol2 - remcol1 + 1)) {
						lower = 1;
						remrow2 = row;
						// printf(" %d ", lowcheck);
					}
					col++;
				}
			}
			// printf(" [%d] [%d] ", upper, lower);
			if (upper == 1 && lower == 1 && remrow1 != remrow2) { // hole confirmed, upper and lower bounds and sides found
				holes++;
				lower = 0;
				upper = 0;
			}
		} else {
			// printf(" WBW ");
			upper = 0;
			lower = 0;
		}
		// printf("\n");
		row = row - 1;
		col = 0;
		BWW = 0;
		BWB = 0;
		WWB = 0;
	}
	return holes;
}
