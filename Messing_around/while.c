#include <stdio.h>

int main(void) {
    int sum, x;

    sum = 0;

    printf("Enter number: ");
    while (scanf("%d", &x) == 1) {
        sum = sum + x;
        printf("Enter number: ");
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}
