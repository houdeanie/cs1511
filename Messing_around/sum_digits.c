#include <stdio.h>

int main () {
	int count = 0;
	int sum = 0;

	char c;

	c = getchar();

	while (c != EOF) {
		if (c <= '9' && c >= '0') {
			sum = sum + c - '0';
			count = count + 1;
		}
		c = getchar();
	}
	printf("Input contained %d digits which summed to %d\n", count, sum);
	return 0;
}
