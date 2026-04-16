int ft_str_is_uppercase(char *str)
{
  int i;

  i = 0;
  if (str[i] == '\0')
    return (1);

  while (str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i] <= 'Z') 
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

  printf("%d ", ft_str_is_uppercase(str));
  printf("%d ", ft_str_is_uppercase(str1));
  printf("%d ", ft_str_is_uppercase(str2));
  printf("%d ", ft_str_is_uppercase(str3));
  printf("%d ", ft_str_is_uppercase(str4));
  return (0);
}