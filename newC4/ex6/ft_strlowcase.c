
int ft_isupcase(char c)
{
  if (c >= 'A' && c <= 'Z')
    return (1);
  return (0);
}

char *ft_strlowcase(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (ft_isupcase(str[i]))
      str[i] += 32;
    i++;
  }
  return (str);
}

#include <stdio.h>

int main()
{
  char arr[] = "abcDE96\n";
  printf("%s\n", ft_strlowcase(arr));
  return (0);
}