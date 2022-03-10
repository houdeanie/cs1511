#include <stdio.h>

int cipher1(int argc, char *argv[26]){
	int i=0, new_cipher[26];
	while (i<26){

		char strcpy(new_cipher, argv, 26);
	i++;
	}

	return new_cipher;
}

int cipher2(int argc, char *argv[26]){
	int new_cipher_cap[26];
	int i=0;

	while(i<26){
		char strcpy(char new_cipher_cap, char toupper(argv), 26);
		i++;
	}
}


int main(void){
	int msg;
	msg=getchar();
	putchar(msg);

	char old_cipher[27] = {"abcdefghijklmnopqrstuvwxyz"};
	char old_cipher_cap[27] ={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int code_cipher[26] = old_cipher[26], code_cipher_cap[26] = old_cipher_cap[26];
	int i =0;
	while (i<26){
		code_cipher[i] = cipher1(int argc, char *argv[26]);
	}
	i=0;
	while (i<26){
		code_cipher_cap[i] = cipher2(int argc, char *argv[26]);

	}
	i=0;
	while (i !=EOF){
		if (strcmp(msg[i], old_cipher[i] ==0)){
			putchar(code_cipher[i]);
		}
		if (strcmp(msg[i], old_cipher_cap[i]) ==0){
			putchar(code_cipher_cap[i]);
		}
		i++;
	}
	return 0;
}
