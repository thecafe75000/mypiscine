
int ft_str_is_lowercase(char *str)
{
  if (!*str)
    return (1);
   while (*str)
  {
    if (*str >= 'a' && *str <= 'z')
      str++;
    else
      return (0);
  }
  return (1);
}

#include <stdio.h>

int main()
{
  char arr1[] = "abcdjiop";
  char arr2[] = "ABhui";
  char arr3[] = "";
  char arr4[] = "ahu89";
  printf("%d\n", ft_str_is_lowercase(arr1));
  printf("%d\n", ft_str_is_lowercase(arr2));
  printf("%d\n", ft_str_is_lowercase(arr3));
  printf("%d\n", ft_str_is_lowercase(arr4));
  return (0);
}