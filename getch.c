#include <stdio.h>
#include <signal.h>

#define MAXBUFF 100

static char buff[MAXBUFF];
static short int ptr = 0;

int getch(void)
{
        return (ptr > 0) ? buff[--ptr] : getchar();
}

void ungetch(int c)
{
        if (ptr >= MAXBUFF)
                raise(SIGSEGV);
        else
                buff[ptr++] = c;
}
