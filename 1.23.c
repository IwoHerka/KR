/*
 * 1.23 Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments do not 
 * nest. 
 */

#include <stdio.h>

#define FREE          0
#define STRING        1
#define CCONST        2
#define START_COMMENT 3
#define SHORT_COMMENT 4
#define MULTI_COMMENT 5

int main(void)
{
        int state;
        char c, last_char;

        state = FREE;

        while ((c = getchar()) != EOF) {
                switch (c) {
                case '"':
                        if (state == FREE)
                                state = STRING;
                        else if (state == STRING)
                                state = FREE;
                        break;
                case '\'':
                        if (state == FREE)
                                state = CCONST;
                        else if (state == CCONST)
                                state = FREE;
                        break;
                case '/':
                        if (state == START_COMMENT && last_char == '/') {
                                state = SHORT_COMMENT;
                        } else if (state == MULTI_COMMENT && last_char == '*') {
                                state = FREE;
                                continue;
                        } else if (state == FREE) {
                                state = START_COMMENT;
                        }
                        break;
                case '*':
                        if (state == START_COMMENT && last_char == '/') {
                                state = MULTI_COMMENT;
                                continue;
                        }
                        break;
                case '\n':
                        if (state == SHORT_COMMENT) {
                                state = FREE;
                        } else if (state == START_COMMENT) {
                                state = FREE;
                                putchar('/');
                        }
                        break;
                default:
                        if (state == START_COMMENT) {
                                putchar('/');
                                state = FREE;
                        }
                }
                
                if (state < START_COMMENT)
                        putchar(c);

                last_char = c;   
        }

        return 0;
}
