//program to test the output of print_image.c 
//code given by comp1511 week 7 lab

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]); //image not read- stderr eror message
        return 1;
    }

    // first get image dimensions
    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;  // if get image dimensions is false print error, otherwise continue
    }

    // now declare appropriate array
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) { // read_pbm is given file
        print_image(height, width, pixels); //read from print_image.c
    }
    return 0;
}

