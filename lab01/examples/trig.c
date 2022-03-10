//Testing Pythagorus identity

#include <stdio.h>
#include <math.h>

int main (void) {
	double theta, identity;
	
	printf ("enter theta: ");
	scanf("%lf", &theta);

	identity = 1- (sin(theta) * sin(theta) + cos(theta) * cos(theta));

	if (identity ==0) {
		printf("Pythagorus was right\n");
	} else {
		printf(" Help pls\n");
	}
	
	return 0;
}


