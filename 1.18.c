/*
 * 1.18. Write a program to remove all trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines. 
 *
 * TODO: Filter and print lines *after* EOF.
 */

#include <stdio.h>

#define MAXLEN 1000

int getl(char [], int);
void trim_trailing(char []);

int main()
{
        int len;
        char line[MAXLEN];

        while ((len = getl(line, MAXLEN)) > 0)
                if (len > 1) {
                        trim_trailing(line);
                        printf("\"%s\"", line);
                }
           
        return 0;
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

void trim_trailing(char line[])
{
        char c;
        int i, lastch;
        
        for (i = 0; (c = line[i]) != '\0'; i++)
                if (c != ' ' && c != '\t' && c != '\n')
                        lastch = i;
        
        line[++lastch] = '\n';
        line[++lastch] = '\0';
}
