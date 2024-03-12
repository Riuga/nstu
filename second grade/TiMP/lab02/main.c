#include <stdio.h>

extern int sgn(float x);

int main()
{
  float value;
  printf("Введите число: \n");
  scanf("%f", &value);
  printf("Результат: %d\n", sgn(value));
  return 0;
}