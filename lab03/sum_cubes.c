//sum of cubes from 1 to n integers
//Dean Hou week 3 
//z5163159

#include <stdio.h>
#include <math.h>

int main (void) {
	int numberCubes, n, x, sum;

	printf("Sum how many cubes? ");
	scanf("%d", &numberCubes);
	
	n=1;
	sum=0;
	while (n <= numberCubes) 
	{
		if (n<numberCubes)
		{
			printf("%d^3 + ", n);		
		} 
		else
		{
			printf("%d^3 ", n);
		}
		x=n*n*n;
		sum=sum + x;
		n=n+1;
	}	
		
	printf("= %d\n", sum);
	
	return 0;
}

