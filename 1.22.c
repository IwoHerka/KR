/*
 * 1. 22 Write a program to "fold" long input lines into two or more shorter 
 * lines after the last non-blank character that occurs before the n-th column
 * of input. Make sure your program does something intelligent with very long 
 * lines, and if there are no blanks or tabs before the specified column. 
 * 
 * TODO: Make breaking words more intelligent, e.g. don't allow to break-off
 * single letters.
 */
        
#include <stdio.h>

#define MAXLINE 1000
#define MAXLEN 20

int getl(char [], int);
void fold(char [], char [], int);

int main()
{
        int len;
        char line[MAXLINE], folded[MAXLINE];

        while ((len = getl(line, MAXLINE)) > 0) {
                fold(line, folded, MAXLEN);
                printf("\n%s\n", folded);
        }
        
        return 0;
}

void fold(char from[], char to[], int maxlen)
{
        char c;
        int i, j, ccount, fpos, skip_ws;

        fpos = -1;
        i = j = ccount = skip_ws = 0;
        
        while ((c = from[i++]) != '\0') {
                if (c == '\n' || (skip_ws == 1 && c == ' '))
                        continue;
                
                if (++ccount == maxlen) {
                        ccount = 0;
                        
                        if (fpos >= 0) {
                                j = fpos;
                                to[j++] = '\n';
                        } else {
                                if (c != ' ')
                                        to[j++] = '-';

                                to[j++] = '\n';
                        }

                        if (c != ' ') {
                                to[j++] = c;
                                ccount++;
                        } else {
                                skip_ws = 1;
                        }
                } else {
                        skip_ws = 0;
                        fpos = c == ' ' ? j : -1;
                        to[j++] = c;
                }
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


