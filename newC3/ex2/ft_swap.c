
void ft_swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

#include <stdio.h>

int main()
{
  int x = 10;
  int y = 600;
  printf("before x = %d, y = %d\n", x, y);
  ft_swap(&x, &y);
  printf("after swap x = %d, y = %d\n", x, y);
  return (0);
}
