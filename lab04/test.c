#include <stdio.h>

int main (void) {

	int x, y, size;
	
	x=1;
	y=1;
	
	printf("Enter size: ");
	scanf("%d", &size);

	while (y <= size) {
		if (y%2 != 0) {
			while (x <= size) {
				if (x%2 != 0) {
		 			printf("-");
		 		} else {
		 	 		printf("*");
		 		}
		 		x=x+1;
		 	}
		 y=y+1;
		 x=1;
		 printf("\n");	
		 }
	}
	return 0;
}
