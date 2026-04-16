/*
  - ASCII控制字符的编号范围是0-31和127（0x00-0x1F和0x7F），共33个字符
    即ASCII 编码中第0~31 个字符（开头的32 个字符）以及第127 个字符（最后一个字符）都是不可见的（无法显示）
    但是它们都具有一些特殊功能，所以称为控制字符
  
  - ASCII中可显示字符编号范围是32-126, 共95个字符
*/
int ft_str_is_printable(char *str)
{
  int i;

  i = 0;
  if (str[i] == '\0')
    return (1);

  while (str[i] != '\0')
  {
    if (str[i] >= 32 && str[i] <= 126) 
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
  char str[] = "!#abcABC1";
  char str1[] = "#&()+-/";
  char str2[] = "12*ab";
  char str3[] = "";
  char str4[] = "\t\n"; // ascii不可显示字符

  printf("%d ", ft_str_is_printable(str));
  printf("%d ", ft_str_is_printable(str1));
  printf("%d ", ft_str_is_printable(str2));
  printf("%d ", ft_str_is_printable(str3));
  printf("%d ", ft_str_is_printable(str4));
  
  return (0);
}