#include <stdio.h>
#include <stdlib.h>

extern int sgn(int x);

int main(int argc, char **argv)
{
  int input = atoi(argv[1]);
  printf("%d\n", sgn(input));
  return 0;
}