//Testing code for division

#include <stdio.h>

int main (void) {
	double x, y;

	printf("Enter x: ");
	scanf("%lf", &x);
	printf("Enter y: ");
	scanf("%lf", &y);

	if (y != 0) {
		printf("%f/%f=%f\n", x, y, x/y);
	} else {
		printf("Can't divide by zero sorry\n");
	}
	return 0;
}
