#include <stdio.h>
int main(void) {
	
	int size;
	int x = 1;
	int y = 1;

	printf("Enter size:");
	scanf("%d", &size);

	while (y <= size) {
		while (x <= size) {
		 if (x == y || x == size + 1 - y) {
		 	printf("*");
		 } else {
		 	printf("-");
		 }
		 	x=x+1;
		 }
		 
		 y=y+1;
		 x=1;
		 printf("\n");
		
	}
		
	return 0;

}
