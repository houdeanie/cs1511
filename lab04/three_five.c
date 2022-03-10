//program that reads a positive integer n and prints all the positive integers <n divisible by 3 or 5
//Dean Hou week4
//z5163159

#include <stdio.h>
#include <math.h>

int main (void) {

	int n, loop;
	
	printf("Enter number: ");
	scanf("%d", &n);

	loop=1;
	
	while (loop<n)
    {
        if (loop%3 == 0) {
            printf("%d\n", loop);
        } else if (loop%5 == 0) {
			printf("%d\n", loop);
		}
		loop = loop+1;
	}
	
	return 0;
}
        
