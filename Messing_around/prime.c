//prime number finder 
//copied off lecture examples and modified

#include <stdio.h>

int main(void) {
	
    int n, possibleFactor, nFactors, x;
    
    printf("Enter number: ");
    scanf("%d", &x);
    // loop through numbers 1..x
    n = 1;
    while (n < x) {
        // loop through numbers 1..n counting factors
        possibleFactor = 1;
        nFactors = 0;
        while (possibleFactor <= n) {
            if (n % possibleFactor == 0) {
                nFactors = nFactors + 1;
            }
            possibleFactor = possibleFactor + 1;
        }
        if (nFactors <= 2) {
            printf("%d is prime\n", n);
        }
        n = n + 1;
    }
    return 0;
}
