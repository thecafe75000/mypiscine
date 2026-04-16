int ft_letter_number(char c)
{
  return ((c >= 'a' && c <= 'z') 
    || (c >= 'A' && c <= 'Z') 
    || (c >= '0' && c <= '9'));
}

char  *ft_strcapitalize(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] >= 'A' && str[i] <= 'Z') 
    {
      str[i] += 32; // 先把所有字母改成小写
    }
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      /*
       字符串首字母 或 前一个字符不是字母也不是数字，即空格，标点(- + , .)及其他非字母数字字符
       也就是：
       如果当前字符是字符串的第一个字符，或者它前面的字符不是字母也不是数字，那么当前字符就是一个“单词的首字母”
      */
      if (i == 0 || !ft_letter_number(str[i-1])) 
      {
        str[i] -= 32;
      }
    }
    i++;
  }
  return (str);
}

#include <stdio.h>

int main()
{
  char str[] = "hi, how are you? 42woRds forty-two; fifty+and+one";
  char str1[] = "Hello world, this is C 2222 []! 42pAris+toKyo-honGkonG**";

  printf("%s\n\n", ft_strcapitalize(str));
  printf("%s\n", ft_strcapitalize(str1));
  return (0);
}
