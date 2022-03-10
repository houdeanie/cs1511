//addition code

#include <stdio.h>

int main (void) {
	double x, y;

	printf("enter x: ");
	scanf("%lf", &x);
	printf("enter y: ");
	scanf("%lf", &y);

	printf("%lf + %lf= %lf\n", x, y, x + y);
	return 0;
}
