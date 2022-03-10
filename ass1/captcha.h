// Dean Hou z5163159
// Tutor: Alexander Rowell
// last edited: 1/05/2017
// header files and function prototypes
// source: week 7 lab 

int read_pbm(char filename[], int height, int width, int pixels[height][width]);

int get_pbm_dimensions(char filename[], int *height, int *width);

void print_image(int height, int width, int pixels[height][width]);

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);

void copy_pixels(int height, int width, int pixels[height][width], int start_row, int start_column, int copy_height, int copy_width, int copy[copy_height][copy_width]);

double get_horizontal_balance(int height, int width, int pixels[height][width]);
// up to here is from lab 07 
// my own additons
double get_vertical_balance(int height, int width, int pixels[height][width]);

double get_tallness(int height, int width);

double get_density(int height, int width, int pixels[height][width]);

int get_holes(int height, int width, int pixels[height][width]);

double get_hole_fraction(int height, int width, int pixels[height][width]);

int get_hole_position(int height, int width, int pixels[height][width]);

int get_bottom_curve(int height, int width, int pixels[height][width]);

int get_top_curve(int height, int width, int pixels[height][width]);

int get_right_up(int height, int width, int pixels[height][width]);

int get_right_down(int height, int width, int pixels[height][width]);

int get_left_up(int height, int width, int pixels[height][width]);

int get_left_down(int height, int width, int pixels[height][width]);

double get_density_top(int height, int width, int pixels[height][width]);

double get_density_bottom(int height, int width, int pixels[height][width]);

