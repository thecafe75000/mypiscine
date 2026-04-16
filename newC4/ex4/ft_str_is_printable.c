/*
  在 ASCII 表里，printable（可打印）字符是指：在终端或文本中能“看得见”或有明确显示意义的字符(共95个)
  注意：空格是 printable，但不可见
  因此可打印的95个字符里有94个可见字符，只有空格是不可见的
  范围：
   - 可打印字符：char c >= 32 && char c <= 126, 即 printable (32-126)
   - 不可打印字符： char c >=0 && char c <= 31 && char c = 127, 即 非printable（0–31, 127）

  坑点: 
   - space ' ' 是 printable
   - \n, \t 虽然“能显示效果”，但 不是 printable
   - isprint() 包括空格 ≠ isgraph() 不包括空格
*/
int ft_str_is_printable(char *str)
{
  if (!*str)
    return (1);
   while (*str)
  {
    if (*str >= 32 && *str <= 126)
      str++;
    else
      return (0);
  }
  return (1);
}

#include <stdio.h>

int main()
{
  char arr1[] = "ABcdjiop123";
  char arr2[] = "ABHUIP\t";
  char arr3[] = " ";
  char arr4[] = "=>?";
  char arr5[] = "\n\a\r";
  printf("%d\n", ft_str_is_printable(arr1));
  printf("%d\n", ft_str_is_printable(arr2));
  printf("%d\n", ft_str_is_printable(arr3));
  printf("%d\n", ft_str_is_printable(arr4));
  printf("%d\n", ft_str_is_printable(arr5));
  return (0);
}