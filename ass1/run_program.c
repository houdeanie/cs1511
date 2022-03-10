// program written for debugging and finding trends

#include <stdio.h>
#include "captcha.h"
int main(int argc, char *argv[]) {
    int digit_num = 9;
    int digit_version = 0;  
    int height, width, start_row, start_column, box_width, box_height;
    double vertBalance, horizBalance, density, tallness, holeFraction;
    int holes;
    // info
    double accuracy;
    double hiHB = 0, lowHB = 1, avHB = 0;
    double hiVB = 0, lowVB = 1, avVB = 0;
    double hiT = 0, lowT = 0, avT = 0;
    double hiDens = 0, lowDens = 1, avDens = 0;
    double hiHF = 0, lowHf = 1, avHF = 0;

    while (digit_version < 100) {       // For versions [0-99]
        char filename[15];
        sprintf(filename, "digit/%d_%02d.pbm", digit_num, digit_version); // 
        
        if (argc < 2) {
            fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
            return 1;
        }
        if (get_pbm_dimensions(filename, &height, &width) != 1) {
            return 1;
        }
        int pixels[height][width];
        printf("digit/%d_%02d.pbm ", digit_num, digit_version);
        if (read_pbm(filename, height, width, pixels)) {
            get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

            int box_pixels[box_height][box_width];
            copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);
            //up to here mostly copied from week 7 lab test_horizontal_balance.c and crack_digit.c in lab- credit author or lab07 and lab partner Steven Ye

            vertBalance = get_vertical_balance(box_height, box_width, box_pixels);
            printf("Vertical Balance: %lf ", vertBalance);
            if (vertBalance > hiVB) {
                hiVB = vertBalance;
            }
            if (vertBalance < lowVB) {
                lowVB = vertBalance;
            }
            avVB = avVB + vertBalance;
            horizBalance = get_horizontal_balance(box_height, box_width, box_pixels);
            printf("Horizontal Balance: %lf ", horizBalance);
        
            tallness = get_tallness(box_height, box_width);
            printf("Tallness: %lf ", tallness);
        
            density = get_density(box_height, box_width, box_pixels);
            printf("Density: %lf ", density);

            holes = get_holes(box_height, box_width, box_pixels);
            printf("Holes: %d ", holes);

            // holeFraction = get_hole_fraction(box_height, box_width, box_pixels, holes);
            // printf("Hole Fraction: %lf \n", holeFraction);
            //if (holes == 2) {
                // accuracy++;
            // }
        }
        printf("\n");
        digit_version++;
    }
   //  av
    // printf("Accuracy: %lf\n", accuracy);
    /*printf("Highest VB: %lf Lowest VB: %lf Average: %lf\n", hiVB, lowVB, avVB);
    printf("Highest HB: Lowest HB: %lf Average HB: %lf \n", hiHB, lowHB, avHB);
    printf("Highest Tallness: Lowest T: %lf Average T: %lf\n", hiT, lowT, avT);
    printf("Highest Density: Lowest D: %lf Average D: %lf\n", hiD, lowD, avD);
    printf("Highest HF: Lowest HF: %lf Average HF: %lf\n", hiHF, lowHF, avHF);*/
    return 0;
}

