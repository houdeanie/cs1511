// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 22/04/2017
// program that finds the tallness, horizontal balance, vertical balance and density of a pbm file

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double vertBalance, horizBalance, density, tallness;
	int holes;
	
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);
        //up to here mostly copied from week 7 lab test_horizontal_balance.c and crack_digit.c in lab- credit author or lab07 and lab partner Steven Ye

        /*vertBalance = get_vertical_balance(box_height, box_width, box_pixels);
        printf("Vertical Balance: %lf\n", vertBalance);
        
        horizBalance = get_horizontal_balance(box_height, box_width, box_pixels);
        printf("Horizontal Balance: %lf\n", horizBalance);
        
        tallness = get_tallness(box_height, box_width);
        printf("Tallness: %lf\n", tallness);
        
        density = get_density(box_height, box_width, box_pixels);
        printf("Density: %lf\n", density);*/
        
        holes = get_holes(box_height, box_width, box_pixels);
        printf("Holes: %d\n", holes);
        
    }
    return 0;
}
