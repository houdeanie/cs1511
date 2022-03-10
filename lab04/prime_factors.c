//program that reads an integer from standard input and prints the decomposition of n into its prime factors, if number is prime, print out message
//Dean Hou Week4
//z5163159

#include <stdio.h>
#include <math.h>

int main (void) {
	
	int n, pFactor, fCount, possi, i, iCount, x;
	
	printf("Enter number: ");
	scanf("%d", &n);
	
	//check if n is prime
	pFactor = 1;
	fCount = 0;
	x = n;
	while (pFactor <= n) {
		if (n % pFactor == 0) {
			fCount = fCount + 1;
		}
		pFactor = pFactor + 1;
	}
	
	
	if (fCount > 2) {
		printf("The prime factorization of %d is: \n", n);
		i=2;
		while (i < n) {
			possi = 1; //possible factors of n which are prime
			iCount = 0; //
			while (possi <= i) {
				if(i % possi == 0) {
					iCount = iCount + 1;
				}
				possi = possi + 1;
			}
			if (iCount <= 2 && n % i == 0) {
				printf("%d * ", i);
				n = n/i;
			} else {
				i = i + 1;
			}
		}
		 if (i == n) {
			possi = 1;
			iCount = 0;
			while (possi <= i) {
				if(i % possi == 0) {
					iCount = iCount + 1;
				}
				possi = possi + 1;
			}
			if (iCount <= 2 && n % i == 0) {
				printf("%d = %d\n", i, x);
			}
		}
	} else { 
		printf("%d is prime \n", n);
	}
	
	return 0;
}

//the program can successfully identity between prime and non prime entered numbers
//i need the program to divide n by a prime integer 
