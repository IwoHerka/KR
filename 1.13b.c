/*
 * 1.13. Write a program to print a histogram of the lengths of words in its 
 * input. It is easy to draw the histogram with the bars horizontal; a vertical 
 * orientation is more challenging. 
 * 
 * b) Vertical version (TODO: Dynamically calculate column width).
 * Example output:
 *
 * 5 | *        
 * 4 | *   *    
 * 3 | *   *    
 * 2 | * * *    
 * 1 | * * * *  
 *   +--------
 *     1 2 3 4
 */

#include <stdio.h>

#define MAXLEN 1000

int main()
{
        char c;
        short int len = 0;
        int max, last, i, hist[MAXLEN];

        for (i = 1; i < MAXLEN; i++)
                hist[i] = 0;

        while (c = getchar()) {
                if (c != ' ') {
                        if (c == '\n') {
                                continue;
                        } else if (c == EOF) {
                                if (len > 0)
                                        hist[len]++;
                                break;
                        }

                        ++len;
                } else if (len > MAXLEN) {
                        printf("Error: word is too long.\n");
                        return 1;
                } else {
                        hist[len]++;
                        len = 0;
                }
        }

        for (i = 0; i < 10; i++)
                printf("%d - %d\n", i, hist[i]);

        last = 0;
        
        for (i = 1; i < MAXLEN; i++) {
                max = hist[i] > max ? hist[i] : max;
                last = hist[i] > 0 ? i : last;
        }

        ++last;
        --max;

        for (; max >= 0; max--) {
                printf("%d |", max + 1);
                
                for (i = 1; i < MAXLEN; i++)
                        if (i > last)
                                break;
                        else if ((max - hist[i]) < 0)
                                printf(" *");
                        else
                                printf("  ");
                                        
                putchar('\n');
        }

        printf("  +");

        for (i = 1; i < MAXLEN; i++)
                if (i > last)
                        break;
                else if (hist[i] > 0)
                        printf("--");
        
        printf("\n   ");
        
        for (i = 1; i < MAXLEN; i++)
                if (i > last)
                        break;
                else if (hist[i] > 0)
                        printf(" %d", i);

        putchar('\n');
                       
        return 0;
}
