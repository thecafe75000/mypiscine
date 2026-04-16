#include <unistd.h>
#include <stdio.h>

void  ft_putstr(const char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    write(1, &str[i], 1);
    i++;
  }
  write(1, "\n", 1);
}

int main()
{
  char characters[] = "abcdef123*&9080kmlopqrst";
  ft_putstr(characters);
  return (0);
}