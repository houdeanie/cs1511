#include <stdio.h>

int
main(void) {
    int c;
    int alphabetPosition;

    // getchar returns an int which will contain either
    // the ASCII code of the character read or EOF

    c = getchar();
    while (c != EOF) {

        if (c >= 'a' && c <= 'z') {
            // toupper() would be better
            alphabetPosition = c - 'a';
            c = 'A' + alphabetPosition;
        }

        putchar(c);

        c = getchar();
    }
    return 0;
}

