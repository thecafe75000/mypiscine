#include <unistd.h>

void ft_putchar(char c1, char c2, char c3)
{
  write(1, &c1, 1);
  write(1, &c2, 1);
  write(1, &c3, 1);
}

void ft_print_comb(void)
{
  int x;
  int y;
  int z;

  x = 0;
  while (x <= 7)
  {
    y = x + 1;
    while (y <= 8)
    {
      z = y + 1;
      while (z <= 9)
      {
        ft_putchar(x + '0', y + '0', z + '0');
        if (!(x == 7 && y ==8 && z ==9))
          write(1, ", ", 2);
        z++;
      }
      y++;
    }
    x++;
  }
}

#include <stdio.h>

int main()
{
  ft_print_comb();
  return (0);
}