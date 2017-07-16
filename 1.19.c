/*
 * 1.19 Write a function reverse(s) that reverses the character string s. 
 * Use it to write a program that reverses its input a line at a time. 
 */

#include <stdio.h>

#define MAXLINE 1000

int getl(char [], int);
void reverse(char *, int);

int main()
{
        int len;
        char line[MAXLINE];

        while ((len = getl(line, MAXLINE)) > 0) {
                reverse(line, len);
                printf("%s\n", line);
        }
        
        return 0;
}

void reverse(char *p1, int len)
{
        char *p2 = p1 + len - 1;

        while (p1 < p2) {
                char tmp = *p1;
                *p1++ = *p2;
                *p2-- = tmp;
        }
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
