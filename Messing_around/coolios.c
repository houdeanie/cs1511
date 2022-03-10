#include <stdio.h>
#include <time.h>
#include <rand.h>
int main () {

	srand(time(NULL));
	printf("%d\n", rand() % 6 + 1);
	
	return 0;
}
