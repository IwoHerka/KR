#include <stdio.h>


void
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\t':
        printf("%c%c", '\\', 't');
        break;
      case '\b':
        printf("%c%c", '\\', 'b');
        break;
      case '\\':
        printf("%c%c", '\\', '\\');
        break;
      default:
        putchar(c);
        break;
    }
  }
}
