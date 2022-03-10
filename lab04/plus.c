//making a plus sign out of asterisks of n size
//Dean Hou week 4
//z5163159

#include <stdio.h>

int main(void) {
	
	int size, column, row;
	column = 1;
	row = 1;

	printf("Enter size:");
	scanf("%d", &size);

	while (row <= size) {
		while (column <= size) {
		 if (column == (size+1)/2) {
		 	printf("*");
		 } else if (row == (size+1)/2) {
		 	printf("*");
		 } else {
		 	printf("-");
		 }
		 	column=column+1;
		 }
		 		 
		 row=row+1;
		 column=1;
		 printf("\n");
	}
		
	return 0;
}
