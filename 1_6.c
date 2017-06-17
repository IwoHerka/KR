#include <stdio.h>


void
main()
{
  // This will always be 0.
  printf("%d\n", getchar() == EOF);
}
