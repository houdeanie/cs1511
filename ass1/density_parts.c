// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 1/05/2017
// function for density in each section, split into thirds vertically

#include <stdio.h>
#include "captcha.h"

/*#define TOP 0
#define BOTTOM 1
#define BOTH 2*/

double get_density_top(int height, int width, int pixels[height][width]) {
    int row = height - 1;
    int col = 0;
    int black = 0;
    double denseTop, denseBottom;
    // finding if there is a large black region at the top
    while (row > 2*height/3) {
        while (col < width) {
            if (pixels[row][col] == 1) {
                black++;
            }
            col++;
        }
        row = row - 1;
        col = 0;
    }
    // printf("%d ", black);
    denseTop = (double)black/(width*height/3);
    // printf("%lf ", denseTop);
    return denseTop;
}
double get_density_bottom(int height, int width, int pixels[height][width]) {
    int row = row = height/4;
    int col = 0;
    int black = 0;
    double denseBottom;
    // finding if there is a large black region at the bottom
    while (row >= 0) {
        while (col < width) {
            if (pixels[row][col] == 1) {
                black++;
            }
            col++;
        }
        row = row - 1;
        col = 0;
    }
    denseBottom = (double)black/(width*height/4);
    return denseBottom;
}
