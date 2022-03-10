//program that reads an integer n from standard input and prints out an nxn pattern of asterisks and dashes in the shape of an "x" assume that n is odd and >=5
//Dean Hou	week4
//z5163159
 
#include <stdio.h>

int main(void) {
	
	int size, column, rows;
	column = 1;
	rows = 1;

	printf("Enter size: ");
	scanf("%d", &size);

	while (rows <= size) {
		while (column <= size) {
		 if (column == rows || column == size + 1 - rows) {
		 	printf("*");
		 } else {
		 	printf("-");
		 }
		 	column=column+1;
		 }
		 
		 rows=rows+1;
		 column=1;
		 printf("\n");
		
	}
		
	return 0;

}
