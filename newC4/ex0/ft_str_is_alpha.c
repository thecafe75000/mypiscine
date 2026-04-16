
int ft_str_is_alpha(char *str)
{
  if (!*str) return (1);
  while (*str)
  {
    if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
      str++;
    else
      return (0);
  }
  return (1);
}

#include <stdio.h>

int main()
{
  char arr1[] = "42hello, world!";
  char arr2[] = "";
  char arr3[] = "PARISbonjour";
  printf("%d \n", ft_str_is_alpha(arr1));
  printf("%d \n", ft_str_is_alpha(arr2));
  printf("%d \n", ft_str_is_alpha(arr3));
  return (0);
}
