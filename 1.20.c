/*
 * 1.20 Write a program detab that replaces tabs in the input with the proper 
 * number of blanks to space to the next tab stop. Assume a fixed set of tab 
 * stops, say every n columns. Should n be a variable or a symbolic parameter? 
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABLEN 4

int getl(char [], int);
void detab(char [], char []);

int main()
{
        int len;
        char line[MAXLINE];
        char dline[MAXLINE];

        while ((len = getl(line, MAXLINE)) > 0) {
                detab(line, dline);
                printf("%s", dline);
        }

        return 0;
}

void detab(char from[], char to[])
{
        int i, j, n;

        i = j = n = 0;
        
        while ((to[j] = from[i]) != '\0') {
                if (to[j] == '\t')
                        for (n = 0; n < TABLEN; ++n, ++j)
                                to[j] = ' ';
                else
                        ++j;
                ++i;
        }

        to[j] = '\0';
}

int getl(char line[], int lim)
{
        int i;
        char c;
        
        for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
                line[i] = c;

        if (c == '\n') {
                line[i] = '\n';
                ++i;
        }

        line[i] = '\0';

        return i;
}
