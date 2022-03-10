//program which reads characters from its input and writes the characters to its output encrypted with a Caesar cipher
//Dean hou and Steven Ye week 6
//z5163159 and z5165199
#include <stdio.h>
#include <stdlib.h>
 
int main (int argc, char *argv[]) { 
	int shift;
	shift = atoi(argv[1]);
	
	char c;
	c = getchar();
	//if shift given is too big
	if ((shift > 26) || (shift < -26)) {
		shift = shift % 26;
	}
	
	while (c != EOF) {
		//lower case
		if (c >= 'a' && c <= 'z') {
			c = c - 26 + shift;
			//case if c goes above z
			if (c > ('z' - 26)) {
				c = c - 26 + 26;
			}
			//case if c goes below a
			else if (c < ('a' - 26)) {
				c = c + 26 + 26;
			}
			//no movement case
			else {
			c = c + 26;
			}
		}
		//upper case
		if (c >= 'A' && c <= 'Z') {
			c = c + shift;
			//case if c goes above Z
			if (c > 'Z') {
				c = c - 26;
			}
			//case if c goes below A
			if (c < 'A') {
				c = c + 26;
			}
		} 
		
		putchar(c);
		c = getchar();
	}	
	return 0;
}

