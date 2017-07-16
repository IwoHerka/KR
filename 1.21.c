/* 
 * 1.21 Write a program entab that replaces strings of blanks with the minimum 
 * number of tabs and blanks to achieve the same spacing. Use the same stops as 
 * for detab. When either a tab or a single blank would suffice to reach a tab 
 * stop, which should be given preference? 
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABLEN 4

int getl(char [], int);
void entab(char [], char []);

int main()
{
        int len;
        char c, line[MAXLINE], eline[MAXLINE];

        while ((len = getl(line, MAXLINE)) > 0) {
                entab(line, eline);
                printf("%s\n", eline);
        }

        return 0;
}

void entab(char from[], char to[])
{
        int i, j, k, wcount, ntabs;
        char c;

        i = j = wcount = 0;
        
        while ((c = from[i++]) != '\0') {
                if (c == ' ') {
                        ++wcount;
                        continue;
                } else if (wcount > 0) {
                        printf("(wc: %d, %d, %d", wcount, wcount / TABLEN, wcount % TABLEN);
                        for (k = 0; k < wcount / TABLEN; j++, k++)
                                to[j] = '\t';

                        for (k = 0; k < wcount % TABLEN; j++, k++)
                                to[j] = ' ';

                        wcount = 0;
                }
                
                to[j++] = c;
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
