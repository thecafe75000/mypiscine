#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_print_number(int x, int y)
{
  char num1;
  char num2;
  char num3;
  char num4;

  num1 = x / 10 + '0';
  num2 = x % 10 + '0';
  num3 = y / 10 + '0';
  num4 = y % 10 + '0';
  ft_putchar(num1);
  ft_putchar(num2);
  ft_putchar(' ');
  ft_putchar(num3);
  ft_putchar(num4);
  if (x != 98 || y != 99)
  {
    write(1, ", ", 2);
  }

}

void ft_print_comb2(void)
{
    int x;
    int y;

    x = 0;
    while (x < 99)
    {
      y = x + 1;
      while ( y < 100)
      {
        ft_print_number(x, y);
        y++;
      }
      x++;
    }
}

int main()
{
  ft_print_comb2();
  return (0);
}
