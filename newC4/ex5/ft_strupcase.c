/*
char  *ft_strupcase(char *str)
{
  char *p;

  p = str;
  while (*p)
  {
    if (*p >= 'a' && *p <= 'z')
      *p -= 32;
    p++;
  }
  return (str);
}
*/

int ft_islowcase(char c)
{
  if (c >= 'a' && c <='z')
    return (1);
  return (0);
}

char *ft_strupcase(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (ft_islowcase(str[i]))
      str[i] -= 32;
    i++;
  }
  return (str);
}

#include <stdio.h>

int main()
{
  char arr[] = "123abc&=!";
  char *p = ft_strupcase(arr);
  printf("%s \n", p);
  return (0);
}