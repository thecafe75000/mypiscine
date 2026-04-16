
#include <string.h>
#include <stdlib.h>
/*
  dest -- 指向用于存储复制内容的目标数组
  src -- 要复制的字符串
  n -- 要从src中复制的最多字符数, 当src的长度 < n时，dest 的剩余部分用空字节填充
  返回最终复制的字符串
*/
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
  unsigned int i;

  if (n == 0 || dest == NULL || src == NULL)
    return NULL;

  i = 0;
  while (i < n && src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
  return (dest);
}

#include <stdio.h>
// int main(int ac, char **av)
// {
//   (void)ac;
//   char *str = av[1];
//   unsigned int n = atoi(av[2]);
//   char dest1[30], dest2[30];
//   strncpy(dest1, str, n);
//   ft_strncpy(dest2, str, n);
//   printf("%s\n%s", dest1, dest2);
// }

int main()
{
  char src[] = "abcd123*";
  char dest[12];

  // strncpy(dest, src, 3);
  // int i = 0;
  // while (i < 9)
  // {
  //   printf("%c", dest[i]);
  //   i++;
  // }
  // printf("%s", dest);

  ft_strncpy(dest, src, 5);
  printf("%s", dest);
  
  return (0);
}
