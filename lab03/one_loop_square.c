//read an integer and prints a square of asterisks the size of the integer
//Dean Hou week3 
//z5163159

#include <stdio.h>
#include <math.h>

int main (void) {

	int squareSize, loopCount;
	
	printf("Square size: ");
	scanf("%d", &squareSize);
	
	loopCount=1;
	while (loopCount<= (squareSize*squareSize))
	{
		printf("* ");
		if (loopCount%squareSize == 0) 
		{
			printf("\n");
		}	
		loopCount=loopCount +1;
		
	}
			
	return 0;
}
