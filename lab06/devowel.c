//program that reads characters from its input and writes the same characters to its output except for lower case vowels
//Dean Hou and Steven Ye week 6 
//z5163159 and z5165199
#include <stdio.h>

int main (void) {
	
	char c;
	
	c = getchar();
	
	while (c != EOF) {
		//if the ASCII for c isn't a vowel, print it out with putchar
		if ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u')) {
			putchar(c);
			c = getchar();
		//else printf a nothing value
		} else {
			printf("");
			c = getchar();
		}
	}
	
	return 0;
}
		
			
