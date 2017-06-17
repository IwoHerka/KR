/*
 * 1.16 Revise the main routine of the longest-line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of 
 * the text. 
 */

#include <stdio.h>

#define MAXLINE 100
#define MAXTOTAL 1000

int getl(char line[], int lim);
void copy(char to[], char from[]);

int main()
{
        int len, max;
        char line[MAXTOTAL], longest[MAXLINE];

        max = 0;

        while ((len = getl(line, MAXTOTAL)) > 0)
                if (len <= MAXLINE) {
                        if (len > max) {
                                max = len;
                                copy(longest, line);
                        }
                        
                        printf("\nLine: %sLine length valid: %d\n", line, len);
                } else {
                        printf("\nLine: %s" \
                               "Line length invalid, exceeded by %d.\n",
                               line,
                               len - MAXLINE);
                }

        if (max > 0)
                printf("\nLongest line: %s", longest);

        return 0;
}

int getl(char line[], int lim)
{
        int c, i;

        for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
                if (i < lim-1)
                        line[i] = c;                

        if (c == '\n') {
                line[i] = c;
                ++i;
        }

        line[i] = '\0';

        return i;
}

void copy(char to[], char from[])
{
        int i = 0;

        while ((to[i] = from[i]) != '\0')
                ++i;
}
        
