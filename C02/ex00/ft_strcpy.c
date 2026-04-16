char  *ft_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0'; // 一定要有这行代码
  return (dest);
}

#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "abcdef123***hijklmnopst789-2-8";
  char dest[10];
  // strcpy(dest, str);
  // printf("%s\n\n", dest);

  ft_strcpy(dest, str);
  printf("%s", dest);
  printf("\n%c", dest[20]);
  return (0);
}
