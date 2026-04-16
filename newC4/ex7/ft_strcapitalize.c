/*
  要求： 把字符串中每个“单词”的首字母变成大写，其余字母全部变成小写
  如果当前字符str[i]是字母，并且它是字符串的第一个字符，
  或者它前一个字符str[i-1]不是字母(不能是大小字母)也不是数字，那么这个字母str[i]必须是大写,
  否则，这个字母str[i]必须是小写

  注意：
  1- 当单词的第一个字符是数字，则数字后面的小写字母不能改成大写字母
  2- 即如果单词以数字开头，那么这个单词不会有大写字母
  
  核心逻辑：
  必须先把所有字母“压成小写”，然后满足条件：
  前一个字符str[i-1]不是数字， 并且str[i-1]不是小写字母，也不是大写字母
*/
int ft_letter_number(char c)
{
  return ((c >= '0' && c <= '9') 
    || (c >= 'a' && c <= 'z') 
    || (c >= 'A' && c <= 'Z'));
}

char *ft_strcapitalize(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += 32;  // 先把所有字母统一改成小写
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      // if (i == 0 || !((str[i-1] >= '0' && str[i -1] <= '9') || (str[i-1] >= 'a' && str[i-1] <= 'z') || (str[i-1] >= 'A' && str[i-1] <= 'Z')))
      if (i == 0 || !ft_letter_number(str[i - 1]))
        str[i] -= 32;
    }
    i++;
  }
  return (str);
}

#include <stdio.h>

int main()
{
  char arr1[] = "hello, how are you doing? 42words forty-two; fifty+and+one";
  char arr2[] = "addA, djioSO KI99-1pl ad? 88ss, enD!";
  printf("%s \n", ft_strcapitalize(arr1));
  printf("%s \n", ft_strcapitalize(arr2));
  return (0);
}