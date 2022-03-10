
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 9999
#define ABCD 26
//encryption
void encrypt(char input[ABCD], char output[ABCD]) {
	int count = 0;
	while (count < ABCD) {
		output[count] = input[count];
		count++;
	}
}

int main (int argc, char *argv[]) {
	
	char c; 
	char abc[] = {"abcdefghijklmnopqrstuvwxyz"};
	char ABC[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	
	c = getchar();
	
	char key[1][ABCD];
	
	encrypt(argv[1][ABCD],key[1][ABCD]);
	int loop;
	loop = 0;
	while (c != EOF) {
		while (loop < ABCD) {
			if (c == abc[loop] || c == ABC[loop]) {
				c = argv[1][loop];
			}
			loop++;
		}		
		putchar(c);
		c = getchar();
	}
	return 0;
}
