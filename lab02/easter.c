//Dating easter program calculates the date of Easter sunday for a year using formula
//Dean Hou
//8/03/2017

#include <stdio.h>

int main (void) {
	int year, a, b, c, d, e, f, g, h, i, k, l, m, easterMonth, p, easterDate;

	printf("Enter year: ");
	scanf("%d", &year);
	
	a=year%19;
	b=year/100;
	c=year%100;
	d=b/4;
	e=b%4;
	f=(b+8)/25;
	g=(b-f+1)/3;
	h=(19*a+b-d-g+15)%30;
	i=c/4;
	k=c%4;
	l=(32+2*e+2*i-h-k)%7;
	m=(a+11*h+22*l)/451;
	easterMonth =(h+l-7*m+114)/31;
	p=(h+l-7*m+114)%31;
	easterDate=p+1;

	if (easterMonth == 3) {	
		printf("Easter is March %d in %d.\n", easterDate, year);
	} else if (easterMonth == 4) {
		printf("Easter is April %d in %d.\n", easterDate, year);
	}

	return 0;
}
