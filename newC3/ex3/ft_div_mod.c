
void ft_div_mod(int a, int b, int *div, int *mod)
{
  *div = a / b;
  *mod = a % b;
}

#include <stdio.h>

int main()
{
  int x = 10;
  int y = 3;
  int i = 0;
  int j = 0;
  ft_div_mod(x, y, &i, &j);
  printf("div = %d, mod = %d\n", i, j);
  return (0);
}
