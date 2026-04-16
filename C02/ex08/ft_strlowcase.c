char  *ft_strlowcase(char *str)
{
   int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i] <= 'Z' )
    {
      str[i] += 32;
    }
    i++;
  }
  return (str);
}
#include <stdio.h>

int main()
{
  char str[] = "abc12";
  char str1[] = "abCDef";
  char str2[] = "ABCD";

  printf("%s\n", ft_strlowcase(str));
  printf("%s\n", ft_strlowcase(str1));
  printf("%s\n", ft_strlowcase(str2));
  return (0);
}
