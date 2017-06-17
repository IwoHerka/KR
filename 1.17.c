/*
 * 1.17. Write a program to print all input lines that are longer than 80 
 * characters.
 */

#include <stdio.h>

#define MAXLEN 80
#define MAXTOTAL 1000

int getl(char line[], int lim);

int main()
{
        int len;
        char line[MAXTOTAL];

        while ((len = getl(line, MAXTOTAL)) > 0)
                if (len > MAXLEN)
                        printf("\n%d+ line: %s\n", MAXLEN, line);
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
