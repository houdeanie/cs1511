#include <stdio.h>

int main(void) {
    int sum, x, numbersRead;

    sum = 0;
    numbersRead = 1;
    printf("Enter numbers, indicate end-of-input with control-D:\n");

    while (numbersRead == 1) {

        // if scanf can read an integer it will place it in x and it will return 1
        // if scanf can't read an integer it will not change x and it will return 0 or -1
        numbersRead = scanf("%d", &x);

        if (numbersRead == 1) {
            sum = sum + x;
        }
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}

