int ft_str_is_lowercase(char *str)
{
  int i;

  i = 0;
  if (str[i] == '\0')
    return (1);

  while (str[i] != '\0')
  {
    if (str[i] >= 'a' && str[i] <= 'z') 
    {
      i++;
    }
    else 
    {
      return (0); 
    }
  }
  return (1); 
}
#include <stdio.h>

int main()
{
  char str[] = "abcABC1";
  char str1[] = "abcde";
  char str2[] = "abcDE";
  char str3[] = "ABCDE";
  char str4[] = "";

  printf("%d ", ft_str_is_lowercase(str));
  printf("%d ", ft_str_is_lowercase(str1));
  printf("%d ", ft_str_is_lowercase(str2));
  printf("%d ", ft_str_is_lowercase(str3));
  printf("%d ", ft_str_is_lowercase(str4));
  return (0);
}