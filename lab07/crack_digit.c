// program that reads a pbm, determines horizontal balance and uses that to determine the number (3 or 6)
// Dean Hou week 7
// z5163159

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double balance;
	
	// check for errors 
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }
	// if false return 1 and error, else get pbm dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) { // from pbm file get dimensions
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width); // get bounding box dimensions from bounding_box.c

        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels); // copy bounding box dimensions into copy_pixles

        balance = get_horizontal_balance(box_height, box_width, box_pixels); // find horizontal balance

        if (balance >= 0.5 && balance < 0.65) { // parameters of horizontal balance for 3 (estimate)
        	printf("3\n");
        }
        if (balance >= 0.4 && balance <0.5 ) { // parameters of horizontal balance for 6 (estimate)
        	printf("6\n");
        }
    }
    return 0;
}

