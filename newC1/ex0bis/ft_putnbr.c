#include <unistd.h>

void ft_putchar(char c)
{
  write(1, &c, 1);
}

// 非递归while版本
void    ft_putnbr(int n)
{
    long nb;
    long div;

    nb = n;
    div = 1;
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }

    while ((nb / div) > 9)
        div *= 10; // 把 div 当前的值乘以 10，然后赋回 div, 从个位开始，不断扩大 div，直到找到数字的最高位

    while (div > 0)
    {
        ft_putchar((nb / div) + '0');
        nb %= div;// nb = 99 9 9
        div /= 10; // div =10 1  0
    }
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