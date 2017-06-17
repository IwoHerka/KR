#include <stdio.h>

/*
 * This simple program assumes word to be any
 * sequence of characters delimited with white space.
 */
void main()
{
        int c, ws;

        ws = 0;

        while ((c = getchar()) != EOF)
                if (c == ' ') {
                        ws = 1;
                } else {
                        if (ws == 1) {
                                putchar('\n');
                                ws = 0;
                        }

                        putchar(c);
                }
}
