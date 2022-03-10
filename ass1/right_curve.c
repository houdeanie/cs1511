// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// function that finds top and bottom right curves in bounding box
#include <stdio.h>
#include "captcha.h"
// 11 
// 01 
// 01 
// 11 

//basically finding holes except sideways
int get_right_up(int height, int width, int pixels[height][width]) {
    int row = height - 1;
    int col = width - 1;
    int remrow1, remrow2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
    int rightUp = 0;
	int rightcheck = 0; // to check if there is curve on the right upper and down
    // upper
    while (col >= width/2) {
        while (row >= height/2) {
            // printf("%d", pixels[row][col]);
            if (row != 0 && row != height - 1 && col != 0 && col != width - 1) {
				if (pixels[row][col] == 1 && pixels[row + 1][col] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 000110
					BWB = 1;
					remrow1 = row;
				} else if (pixels[row][col] == 1 && pixels[row - 1][col] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 00011000011
					WWB = 1;
					remrow2 = row + 1;
				}
			}
			row = row - 1;
        }
        if (BWW == 1 && WWB == 1 && BWB == 1 && remrow1 != remrow2) {// must be an enclosed area 1100000011, check for 111111111 below it
            if (col != width) {
                // printf ("%d", (remrow1 - remrow2 + 1));
				rightcheck = 0;
				row = remrow1;
				while (row >= remrow2) {
					// printf(" %d ", pixels[row][col + 1]);
					if (pixels[row][col + 1] == 1) {
						rightcheck++;
					/*} else if (pixels[row - 1][col] == 0) {
						lowcheck = 0;*/
					}
					if (rightcheck == (remrow1 - remrow2 + 1)) {
						rightUp++;
					}
					row = row - 1;
				}  
			}
        } 
        // printf("\n");
        col = col - 1;
        row = height - 1;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
    return rightUp;
}
int get_right_down(int height, int width, int pixels[height][width]) {
    int row = height/2;
    int col = width - 1;
    int remrow1, remrow2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
	int rightcheck = 0; // to check if there is curve on the right upper and down
    int rightDown= 0;
    // lower
    while (col >= width/2) {
        while (row >= 0) {
            // printf("%d", pixels[row][col]);
            if (row != 0 && row != height - 1 && col != 0 && col != width - 1) {
				if (pixels[row][col] == 1 && pixels[row + 1][col] == 1 && BWW == 0) { // 00000011
					BWW = 1;
				} else if (pixels[row][col] == 0 && BWW == 1 && BWB == 0) { // 000110
					BWB = 1;
					remrow1 = row;
				} else if (pixels[row][col] == 1 && pixels[row - 1][col] == 1 && BWW == 1 && BWB == 1 && WWB == 0) { // 00011000011
					WWB = 1;
					remrow2 = row + 1;
				}
			}
			row = row - 1;
        }
        if (BWW == 1 && WWB == 1 && BWB == 1 && remrow1 != remrow2) {// must be an enclosed area 1100000011, check for 111111111 below it
            if (col != width) {
                // printf ("%d", (remrow1 - remrow2 + 1));
				rightcheck = 0;
				row = remrow1;
				while (row >= remrow2) {
					// printf(" %d ", pixels[row][col + 1]);
					if (pixels[row][col + 1] == 1) {
						rightcheck++;
					/*} else if (pixels[row - 1][col] == 0) {
						lowcheck = 0;*/
					}
					if (rightcheck == (remrow1 - remrow2 + 1)) {
						rightDown++;
					}
					row = row - 1;
				}  
			}
        } 
        // printf("\n");
        col = col - 1;
        row = height/2;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
    return rightDown;
}

