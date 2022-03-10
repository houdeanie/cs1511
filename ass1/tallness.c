// Dean Hou z5163159
// Tutor: Alexander Rowell
// written 20/04/2017
// function that finds the tallness of a digit in bounding box

#include <stdio.h>
#include "captcha.h"

double get_tallness(int height, int width) {
	double tallness;

	tallness = (double)height/width;

	return tallness;
}
