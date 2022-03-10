#include <stdio.h>

int main(void) {
    int x, sum;

    sum = 0;
    printf("Enter numbers, terminate with a negative number:\n");

    scanf("%d", &x);
    while (x >= 0) {
        sum = sum + x;
        scanf("%d", &x);
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}
