//order threee numbers without using if statements 
//Dean Hou week 3
//z5163159

#include <stdio.h>

int main (void) {
	
	int x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m;

	printf("Enter integer: ");
	scanf("%d", &x);
	printf("Enter integer: ");
	scanf("%d", &y);
	printf("Enter integer: ");
	scanf("%d", &z);
	
	//all possible combinations
	a= (x<y && y<z);
	b= (x<z && z<y);
	c= (y<z && z<x);
	d= (y<x && x<z);
	e= (z<y && y<x);
	f= (z<x && x<y);
	g= (x==y && y<z);
	h= (x==y && z<y);
	i= (x==z && x<y);
	j= (x==z && y<x);
	k= (y==z && z<x);
	l= (y==z && x<z);
	m= (x==y && y==z);
	
	printf("The integers in order are: ");
	printf("%d ", x*a + x*b + y*c + y*d + z*e + z*f + x*g + z*h + x*i + y*j + y*k + x*l + x*m);
	printf("%d ", y*a + z*b + z*c + x*d + y*e + x*f + x*g + x*h + x*i + x*j + y*k + y*l + x*m);
	printf("%d ", z*a + y*b + x*c + z*d + x*e + y*f + z*g + x*h + y*i + x*j + x*k + y*l + x*m);
	printf("\n");
	
	return 0;
}
