#include <unistd.h>

void ft_putchar(char c)
{
   write(1, &c, 1);
}

void  ft_print_numbers(void)
{
  int i;
  char c;

  i = 0;
  while (i <= 9)
  {
    c = i + '0';
    ft_putchar(c);
    i++;
  }
}

int main()
{
  ft_print_numbers();
  return (0);
}