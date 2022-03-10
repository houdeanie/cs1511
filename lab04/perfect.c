//reads positive integer n from standard input and prints all the factors of n and their sum and if n is a perfect number
//Dean Hou week4
//z5163159

#include <stdio.h>
#include <math.h>
	
int main (void) {

	int n, loopCount, sum;

	printf("Enter number: ");
	scanf("%d", &n);
	
	loopCount=1;
	sum=0;
	
	printf("The factors of %d are: \n", n);
	while (loopCount<=n) {
		if (n%loopCount == 0) {
			printf("%d\n", loopCount);
			sum = sum + loopCount;
		}
		loopCount = loopCount + 1;
	}
	
	printf("Sum of factors = %d\n", sum);
	if (sum == 2*n) {
		printf("%d is a perfect number\n", n);
	} else {
		printf("%d is not a perfect number\n", n);
	}
	return 0;
}
