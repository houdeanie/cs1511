//program that prints out a chessboard like pattern, prints out n*n pattern of asterisks and dashes
//Dean Hou week 4
//z5163159

#include <stdio.h>

int main (void) {

	int column, row, size;
	
	column=1;
	row=1;
	
	printf("Enter size: ");
	scanf("%d", &size);
	
	while (row <= size) { 
		if (row%2 != 0) {
			while (column <= size) {
				if (column%2 != 0) {
		 			printf("-");
		 		} else {
		 	 		printf("*");
		 		}
		 		column=column+1;
		 	}
		 } else if (row%2 == 0) {
		 	while (column <= size) {
		 		if (column%2 == 0) {
		 			printf("-");
		 		} else {
		 			printf("*");
		 		}
		 		column=column+1;
		 	}
		 }
		 row=row+1;
		 column=1;
		 printf("\n");	
	}
	return 0;
}
