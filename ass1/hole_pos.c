// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// program that finds hole position 

// largely copied from holes.c
#include <stdio.h>
#include "captcha.h"
#define MIDDLE 0
#define BOTTOM 1
#define TOP 2

int get_hole_position(int height, int width, int pixels[height][width]) {
    int row = height - 1, col = 0;
	int remcol1, remcol2; // remember column number of beginning and end of hole sides 1000001
	int remrow1, remrow2; // remember row number of top and bottom
	int BWW = 0, WWB = 0, BWB = 0, upper = 0, lower = 0, upcheck = 0, lowcheck = 0;
	int holes = 0;
	// hole must be at least layered in 2 black pixels
    // printf("%d %d ", height, width);
	while (row >= 0) { // finds the places of the first and last 0 in a possible hole
		while (col < width) {
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
			if (upper != 1 && row != height - 1) {
				col = remcol1;
				upcheck = 0;
				while (col <= remcol2) {
					if (pixels[row + 1][col] == 1) {
						upcheck++;
					}
					if (upcheck == (remcol2 - remcol1 + 1)) {
						upper = 1;
						remrow1 = row;
					}
					col++;
				}	
			} else if (upper == 1 && lower != 1 && row != 0) {
				lowcheck = 0;
				col = remcol1;
				while (col <= remcol2) {
					if (pixels[row - 1][col] == 1) {
						lowcheck++;
					}
					if (lowcheck == (remcol2 - remcol1 + 1)) {
						lower = 1;
						remrow2 = row;
					}
					col++;
				}
			}
			if (upper == 1 && lower == 1 && remrow1 != remrow2) { // hole confirmed, upper and lower bounds and sides found
				holes++;
				lower = 0;
				upper = 0;
                // hole found, now determine where the hole is based on remrow1 and remrow2
                // printf("%d %d ", remrow1, remrow2);
                if (remrow1 >= 2*height/3) {
                    if (remrow2 < height/3) {
                        return MIDDLE; // i.e. 0
                    }
                    if (remrow2 >= height/3) {
                        return TOP; // i.e. 4 or 9
                    }
                } else if (remrow1 <= 2*height/3 && remrow2 > 0) {
                    return BOTTOM; // 6
                }
			}
		} else {
			upper = 0;
			lower = 0;
        }
		row = row - 1;
		col = 0;
		BWW = 0;
		BWB = 0;
		WWB = 0;
	}
	return 0;
}
