#include <stdio.h>


void
main()
{
  int c, ws;

  ws = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ws = 1;
    } else {
      if (ws == 1) {
        putchar(' ');
        ws = 0;
      }
      putchar(c);
    }
  }
}
