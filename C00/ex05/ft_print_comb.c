#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_print_number(int x, int y, int z)
{
  char num1;
  char num2;
  char num3;

  num1 = x + '0';
  num2 = y + '0';
  num3 = z + '0';
  ft_putchar(num1);
  ft_putchar(num2);
  ft_putchar(num3);
}

void ft_print_comb(void)
{
  int x;
  int y;
  int z;

  x = 0;
  while (x < 8)
  {
    y = x + 1;
    while (y < 9)
    {
      z = y + 1;
      while (z < 10)
      {
        ft_print_number(x, y, z);
        if (x < 7 || y < 8 || z < 9)
           write(1, ", ", 2);
        z++;
      }
      y++;
    }
    x++;
  }
}

int main()
{
  ft_print_comb();
  return (0);
}