
void ft_ultimate_div_mod(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = temp / *a;
  *b = temp % *b;
}

#include <stdio.h>

int main()
{
  int x = 10;
  int y = 3;
  printf("x = %d, y = %d\n", x, y);
  ft_ultimate_div_mod(&x, &y);
  printf("div = %d, mod = % d\n", x, y);
  printf("after x = %d, y = %d\n", x, y);
  return (0);
}
