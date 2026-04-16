
int ft_str_is_uppercase(char *str)
{
  if (!*str)
    return (1);
   while (*str)
  {
    if (*str >= 'A' && *str <= 'Z')
      str++;
    else
      return (0);
  }
  return (1);
}

#include <stdio.h>

int main()
{
  char arr1[] = "ABcdjiop";
  char arr2[] = "ABHUIP";
  char arr3[] = "";
  char arr4[] = "ahu89";
  char arr5[] = "SGH\t";
  printf("%d\n", ft_str_is_uppercase(arr1));
  printf("%d\n", ft_str_is_uppercase(arr2));
  printf("%d\n", ft_str_is_uppercase(arr3));
  printf("%d\n", ft_str_is_uppercase(arr4));
  printf("%d\n", ft_str_is_uppercase(arr5));
  return (0);
}