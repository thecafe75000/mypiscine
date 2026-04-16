char  *ft_strupcase(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'a' && str[i] <= 'z' )
    {
      str[i] -= 32;
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

  printf("%s\n", ft_strupcase(str));
  printf("%s\n", ft_strupcase(str1));
  printf("%s\n", ft_strupcase(str2));
  return (0);
}