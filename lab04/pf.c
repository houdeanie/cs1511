//factorisation code

#include <stdio.h>
#include <math.h>

int main (void) {
	
	int n, possibleFactor, nFactors, x;
    
    printf("Enter number: ");
    scanf("%d", &x);
    
    n = 2;
    while (n < x) {
        
        possibleFactor = 1;
        nFactors = 0;
        while (possibleFactor <= n) {
            if (n % possibleFactor == 0) {
                nFactors = nFactors + 1;
            }
            possibleFactor = possibleFactor + 1;
        }
        if (nFactors <= 2) {
            printf("%d * ", n);
        }
        n = n + 1;
    }
    return 0;
}
//test for prime factors of n
		//part2, make sure that i is a prime number, see if n is divisible by i, then change i to next prime number
		//printf("%d ", i);
		//printf("* %d ", i);
		//printf("= %d", n);
		possiblei = 1;
		iCount = 0;
		i = 2;
		while (i < n) {
			
			while (possiblei <= i) {
				if(i % possiblei == 0) {
					iCount = iCount + 1;
				}
				possiblei = possiblei + 1;
			} 
			if (iCount <= 2) {
				if (n % i == 0) {
					printf("%d ", i);
					n = n/i;
					}
