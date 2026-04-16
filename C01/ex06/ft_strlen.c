int ft_strlen(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

#include <stdio.h>

int main()
{
  char str[] = "123abc7891123456789";
  int length = ft_strlen(str);
  printf("length of str = %d \n", length);
  return (0);
}