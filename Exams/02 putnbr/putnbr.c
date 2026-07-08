#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void ft_putnbr(int nb)
{
  long x;
  char c;

  x = nb;
  if (x < 0)
  {
    write(1, "-", 1);
    x = -x;
  }
  if (x >= 0 && x <= 9)
  {
	  c = x + '0';
	  write(1, &c, 1);
  }
  if (x > 9)
  {
	ft_putnbr(x / 10);
	c = x % 10 + '0';
	write(1, &c, 1);
  }
}

int main()
{
  ft_putnbr(42);
  printf("\n");
  ft_putnbr(9);
  printf("\n");
  ft_putnbr(0);
  printf("\n");
  ft_putnbr(-12345);
  printf("\n");
  ft_putnbr(2147483647);
  printf("\n");
  ft_putnbr(-2147483648);
  printf("\n");
  printf("INT_MIN = %d\n", INT_MIN);
  printf("INT_MAX = %d\n", INT_MAX);
  return (0);
}
