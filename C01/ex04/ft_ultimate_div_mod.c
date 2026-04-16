void  ft_ultimate_div_mod(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *a / *b;
  *b = temp % *b;
}
#include <stdio.h>

int main()
{
  int x = 10;
  int y = 6;

  printf("x = %d , y = %d \n", x, y);
  ft_ultimate_div_mod(&x, &y);
  printf("division = %d , modulo = %d \n", x, y);
  return (0);
}