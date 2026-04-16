int ft_str_is_alpha(char *str)
{
  int i;

  i = 0;
  if (str[i] == '\0')
    return (1);

  while (str[i] != '\0')
  {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
    {
      i++; // 如果是字母，就继续检查下一个字符
    }
    else 
    {
      return (0); // 不是字母，则立即返回0
    }
  }
  return (1); // 所有字符都是字母
}

#include <stdio.h>

int main()
{
  char str[] = "abcABC1";
  char str1[] = "abcde";
  char str2[] = "abcDE";
  char str3[] = "ABCDE";
  char str4[] = "";

  printf("%d ", ft_str_is_alpha(str));
  printf("%d ", ft_str_is_alpha(str1));
  printf("%d ", ft_str_is_alpha(str2));
  printf("%d ", ft_str_is_alpha(str3));
  printf("%d ", ft_str_is_alpha(str4));
  return (0);
}
