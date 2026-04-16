#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}
// 递归版本
void ft_putnbr(int nb)
{
  long x;

  x = nb;
  if (x < 0)
  {
    ft_putchar('-');
    x = -x;
  }
  if (x > 9)
  {
    ft_putnbr(x / 10);
  }
  ft_putchar((x % 10) + '0');
}

// 打印输出代码后的自动另起新行
void ft_newline(int nb)
{
  ft_putnbr(nb);
  ft_putchar('\n');
}

int main()
{
  int x = 42;
  int y = 10002;
  int z = -6789234;
  ft_newline(x);
  ft_newline(y);
  ft_newline(z);
  return (0);
}