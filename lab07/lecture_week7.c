//for some lab
#include <stdio.h>

void fun(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main (void) {
	int i, j;
	i = 42;
	j = 0;
	printf("i=%d j=%d\n", i, j);
	fun(&i, &j);
	printf("i=%d j=%d\n", i, j);
	return 0;
}
/*	
int main(int argc, char *argv[]) {
	int k;
	printf("%p\n", &k);
	return 0;
} 
*/
