#include <stdio.h>

#define MAX_WLEN 45 // Pneumonoultramicroscopicsilicovolcanoconiosis.
#define ASC_HMNR 33 // Cutoff for ASCII control sequences.

void main()
{
        int c, wc, ws, i, j;
        int lns[MAX_WLEN];

        wc = ws = 0;

        for (i = 0; i < MAX_WLEN - 1; ++i)
                lns[i] = 0;

        while ((c = getchar()) != EOF)
                if (c == ' ') {
                        ws = 1;
                } else if (c >= ASC_HMNR) {
                        if (ws == 1) {
                                ++lns[wc];
                                wc = ws = 0;
                        }
                        
                        ++wc;
                }

        if (wc != 0)
                ++lns[wc];

        for (i = 1; i < MAX_WLEN - 1; ++i) {
                j = lns[i];

                if (j != 0) {
                        printf("%d: %d ", i, j);

                        for (; j > 0; --j)
                                putchar('=');

                        putchar('\n');
                }
        }
}
