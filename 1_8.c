#include <stdio.h>

void main()
{
        int c, ws, t, nl;

        ws = t = nl = 0;

        while ((c = getchar()) != EOF) {
                switch (c) {
                case ' ':
                        ++ws; break;
                case '\t':
                        ++t; break;
                case '\n':
                        ++nl; break;
                }

        printf("White spaces: %d, tabs: %d, new-lines: %d\n", ws, t, nl);
}
