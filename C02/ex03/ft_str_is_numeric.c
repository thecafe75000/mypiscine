int ft_str_is_numeric(char *str)
{
  int i;

  i = 0;
  if (str[i] == '\0')
    return (1);

  while (str[i] != '\0')
  {
    if (str[i] >= 48 && str[i] <= 57) 
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
  char str[] = "012345678910";
  char str1[] = "123abcde";
  char str2[] = "123DE";
  char str3[] = "12*abCDE";
  char str4[] = "";

  printf("%d ", ft_str_is_numeric(str));
  printf("%d ", ft_str_is_numeric(str1));
  printf("%d ", ft_str_is_numeric(str2));
  printf("%d ", ft_str_is_numeric(str3));
  printf("%d ", ft_str_is_numeric(str4));
  
  return (0);
}