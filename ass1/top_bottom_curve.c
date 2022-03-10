// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// function that separates into top down left and right in bounding box and finds curves
#include <stdio.h>
#include "captcha.h"

// finding curves such as these:
// 1000001 
// 1111111

// largely copied from holes.c 
int get_bottom_curve(int height, int width, int pixels[height][width]) {
    // printf("%d %d\n", height, width);
    int row = height/4;
    int col = 0;
    int remcol1, remcol2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
    int lower = 0;
	int lowcheck = 0; // to check if there is a base
    
    // looking bottom curve, mainly to differentiate 3 from 2 and 7 and 9 from 4
    while (row >= 0) {
        while (col < width) {
            // printf("%d", pixels[row][col]);
            if (row != 0 && row != height - 1 && col != 0 && col != width - 1) {
				if (pixels[row][col] == 1 && pixels[row][col - 1] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 000110
					BWB = 1;
					remcol1 = col;
				} else if (pixels[row][col] == 1 && pixels[row][col + 1] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 00011000011
					WWB = 1;
					remcol2 = col - 1;
				}
			}
			col++;
        }
        if (BWW == 1 && WWB == 1 && BWB == 1 && remcol1 != remcol2) {// must be an enclosed area 1100000011, check for 111111111 below it
            if (lower != 1 && row != 0) {
				lowcheck = 0;
				col = remcol1;
				while (col <= remcol2) {
					// printf("%d", pixels[row - 1][col]);
					if (pixels[row - 1][col] == 1) {
						lowcheck++;
                    }
					if (lowcheck == (remcol2 - remcol1 + 1)) {
						lower = 1;
						// printf(" %d ", lowcheck);
					}
					col++;
				}  
			}
            if (lower == 1) {
                return lower;
            }
        } else {
            lower = 0;
        }
        // printf("\n");
        row= row - 1;
        col = 0;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
	if (lower != 1) {
		return 0;
	}
	return 0;
}
// 1111111
// 1000001
// top curve
int get_top_curve(int height, int width, int pixels[height][width]) {
    int row = height - 1;
    int col = 0;
    int remcol1, remcol2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
    int upper = 0;
	int upcheck = 0; // to check if there is a cap
    
    // looking bottom curve, mainly to differentiate 3 from 2 and 7 and 9 from 4
    while (row >= 3*height/4) {
        while (col < width) {
            // printf("%d", pixels[row][col]);
            if (row != 0 && row != height - 1 && col != 0 && col != width - 1) {
				if (pixels[row][col] == 1 && pixels[row][col - 1] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 000110
					BWB = 1;
					remcol1 = col;
				} else if (pixels[row][col] == 1 && pixels[row][col + 1] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 00011000011
					WWB = 1;
					remcol2 = col - 1;
				}
			}
			col++;
        }
        if (BWW == 1 && WWB == 1 && BWB == 1 && remcol1 != remcol2) {// must be an enclosed area 1100000011, check for 111111111 below it
            if (upper != 1 && row != 0) {
				upcheck = 0;
				col = remcol1;
				while (col <= remcol2) {
					// printf("%d", pixels[row - 1][col]);
					if (pixels[row + 1][col] == 1) {
						upcheck++;
                    }
					if (upcheck == (remcol2 - remcol1 + 1)) {
						upper = 1;
						// printf(" %d ", lowcheck);
					}
					col++;
				}  
			}
            if (upper == 1) {
                return upper;
            }
        } else {
            upper = 0;
        }
        // printf("\n");
        row= row - 1;
        col = 0;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
	if (upper != 1) {
		return 0;
	}
	return 0;
}
