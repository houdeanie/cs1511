//prime checker

#include <stdio.h>

int main(void) {
	
    int n, possibleFactor, nFactors;
    
    printf("Enter number: ");
    scanf("%d", &n);
    // loop through numbers 1..i
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
    } else {
    		printf("%d is not prime\n", n);
   	}
    return 0;
}
