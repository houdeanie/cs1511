// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// function that finds top and bottom left curves in bounding box
#include <stdio.h>
#include "captcha.h"
// 11 
// 10 
// 10 
// 11 

//basically finding holes except sideways
int get_left_up(int height, int width, int pixels[height][width]) {
    int row = height - 1;
    int col = 0;
    int remrow1, remrow2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
    int leftUp = 0;
	int leftcheck = 0; // to check if there is curve on the left upper and down
    // upper
    while (col <= width/2) {
        while (row >= height/2) {
            // printf("%d", pixels[row][col]);
            if (row != 0 && row != height - 1 && col != 0 && col != width - 1) { // creating a safety net
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
        if (BWW == 1 && WWB == 1 && BWB == 1) {// must be an enclosed area 1100000011, check for 111111111 below it
            if (col != 0) {
                // printf ("%d", (remrow1 - remrow2 + 1));
				leftcheck = 0;
				row = remrow1;
				while (row >= remrow2) {
					// printf(" %d ", pixels[row][col + 1]);
					if (pixels[row][col - 1] == 1) {
						leftcheck++;
					/*} else if (pixels[row - 1][col] == 0) {
						lowcheck = 0;*/
					}
					if (leftcheck == (remrow1 - remrow2 + 1)) {
						leftUp++;
					}
					row = row - 1;
				}  
			}
        } 
        // printf("\n");
        col++;
        row = height - 1;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
    return leftUp;
}
int get_left_down(int height, int width, int pixels[height][width]) {
    int row = height/2;
    int col = 0;
    int remrow1, remrow2; // remember column number of beginning and end of hole sides 1000001
    int BWW = 0, BWB = 0, WWB = 0;
	int leftcheck = 0; // to check if there is curve on the left upper and down
    int leftDown= 0;
    // lower
    while (col <= width/2) {
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
				leftcheck = 0;
				row = remrow1;
				while (row >= remrow2) {
					// printf(" %d ", pixels[row][col + 1]);
					if (pixels[row][col + 1] == 1) {
						leftcheck++;
					/*} else if (pixels[row - 1][col] == 0) {
						lowcheck = 0;*/
					}
					if (leftcheck == (remrow1 - remrow2 + 1)) {
						leftDown++;
					}
					row = row - 1;
				}  
			}
        } 
        // printf("\n");
        col++;
        row = height/2;
        BWW = 0;
		BWB = 0;
		WWB = 0;
    }
    return leftDown;
}
