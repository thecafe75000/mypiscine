
void ft_ft(int *nbr)
{
  *nbr = 42;
}

#include <stdio.h>

int main()
{
  int i = 0;
  ft_ft(&i);
  printf("%d\n", i);
  return (0);
}
