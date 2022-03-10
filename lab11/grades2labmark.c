// program that will read a given string of lab grades in command line arguments 
// then print the corresponding total lab mark to 1 dp 
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 11 lab

// uses argv and arrays and chars to determine mark
// max mark is 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// calculates lab mark 
double grades2labmark(char grades[]) {
	int loopCount = 0;
	double sumGrades= 0;
	while (grades[loopCount] != '\0') {
		if (grades[loopCount] == 'A') {
			sumGrades = sumGrades + 1;
		} else if (grades[loopCount] == '+') { // not legit if B+ but the lab says only A+ is allowed
			sumGrades = sumGrades + 0.2;
		}  else if (grades[loopCount] == 'B') {
			sumGrades = sumGrades + 0.8;
		} else if (grades[loopCount] == 'C') {
			sumGrades = sumGrades + 0.5;
		} else if (grades[loopCount] == '.') {
			sumGrades = sumGrades + 0;	
		}
		loopCount++;
	}
	if (sumGrades > 10) {
		sumGrades = 10;
	}
	return sumGrades; 	
}
int main(int argc, char *argv[]) {
	double grades;
	if ( argc != 2) {
		fprintf(stderr, "Usage: %s <marks>\n", argv[0]);
        return 1;
    }
	grades = grades2labmark(argv[1]);
	printf("%.1lf\n", grades);
	return 0;
}
