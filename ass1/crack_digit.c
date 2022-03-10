// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// test program that finds the single digit number through horizontal and vertical balance, density, holes, tallness

#include <stdio.h>
#include "captcha.h"
int main(int argc, char *argv[]) {
 
    int height, width, start_row, start_column, box_width, box_height, holes;
    double vertBalance, horizBalance, density, tallness, holeFraction, holePosition;
    double denseTop, denseBottom;
    int bottomCurve = 0, topCurve = 0, rightUp = 0, rightDown = 0, leftUp = 0, leftDown = 0;
       
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
        holes = get_holes(box_height, box_width, box_pixels); // getting attributes
        vertBalance = get_vertical_balance(box_height, box_width, box_pixels);
        horizBalance = get_horizontal_balance(box_height, box_width, box_pixels);
        tallness = get_tallness(box_height, box_width);
        density = get_density(box_height, box_width, box_pixels);
        bottomCurve = get_bottom_curve(box_height, box_width, box_pixels);
        topCurve = get_top_curve(box_height, box_width, box_pixels);
        rightUp = get_right_up(box_height, box_width, box_pixels);
        rightDown = get_right_down(box_height, box_width, box_pixels);
        leftUp = get_left_up(box_height, box_width, box_pixels);
        leftDown = get_left_down(box_height, box_width, box_pixels);
        denseBottom = get_density_bottom(box_height, box_width, box_pixels);
        denseTop = get_density_top(box_height, box_width, box_pixels);

        if (holes == 2) { // must be 8
            printf("8\n");                 
        } else if (holes == 1) { // 0, 4, 6, 9 
            holeFraction = get_hole_fraction(box_height, box_width, box_pixels);
            holePosition = get_hole_position(box_height, box_width, box_pixels);
            if (holeFraction != 0) {
                if (holePosition == 0) { // 0
                    printf("0\n");
                }
                if (holePosition == 1) { // 6
                    printf("6\n");
                }
                if (holePosition == 2) { // 4 or 9
                    if (bottomCurve == 1) {
                        printf("9\n");
                    } else {
                        printf("4\n");       
                    }
                }
            }
        } else if (holes == 0) { // 1, 2, 3, 5, 7
            if (rightDown == 0) {
            	if (rightUp == 1) {
                	printf("2\n");
                }
                if (bottomCurve == 0) {
                    printf("7\n");
                }
                if (leftUp == 0) {
                    printf("1\n");
                } 
            } else if (rightDown == 1) {
                if (rightUp == 1 || (topCurve == 1 && bottomCurve == 1)) {
                    printf("3\n");
                } else {
                    printf("5\n");
                }
            }
        }
    }         
    return 0;
}


