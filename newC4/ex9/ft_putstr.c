#include <unistd.h>

int ft_strlen(char *str)
{
  int len;

  len = 0;
  while (str[len])
  {
    len++;
  }
  return (len);
}

void ft_putstr(char *str)
{
  int strlen;

  strlen = ft_strlen(str); 
  write(1, str, strlen);   // 直接从 str 开始读 strlen 个字节. str指向字符串首地址，strlen连续字节数
}

#include <stdio.h>

int main()
{
  char arr[] = "hello world, 42Paris!";
  ft_putstr(arr);
  return (0);
}