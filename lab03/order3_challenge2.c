//order3_challenge2.c 
//order3 except without if statements, no while statements and only three variables
//Dean Hou week 3
//z5163159

#include <stdio.h>
int main(void) {

    int x, y, z;

	printf("Enter integer: ");
	scanf("%d", &x);
	printf("Enter integer: ");
	scanf("%d", &y);
	printf("Enter integer: ");
	scanf("%d", &z);

	//get rid of extra variables by substituting all possibilities into printf statement
	
	printf("The integers in order are: ");
	printf("%d ", x*(x<y && y<z) + x*(x<z && z<y) + y*(y<z && z<x) + y*(y<x && x<z) + z*(z<y && y<x) + z*(z<x && x<y) + x*(x==y && y<z) + z*(x==y && z<y) + x*(x==z && x<y) + y*(x==z && y<x) + y*(y==z && z<x) + x*(y==z && x<z) + x*(x==y && y==z));
	printf("%d ", y*(x<y && y<z) + z*(x<z && z<y) + z*(y<z && z<x) + x*(y<x && x<z) + y*(z<y && y<x) + x*(z<x && x<y) + x*(x==y && y<z) + x*(x==y && z<y) + x*(x==z && x<y) + x*(x==z && y<x) + y*(y==z && z<x) + y*(y==z && x<z) + x*(x==y && y==z));
	printf("%d ", z*(x<y && y<z) + y*(x<z && z<y) + x*(y<z && z<x) + z*(y<x && x<z) + x*(z<y && y<x) + y*(z<x && x<y) + z*(x==y && y<z) + x*(x==y && z<y) + y*(x==z && x<y) + x*(x==z && y<x) + x*(y==z && z<x) + y*(y==z && x<z) + x*(x==y && y==z));
	printf("\n");
	
	return 0;
}
