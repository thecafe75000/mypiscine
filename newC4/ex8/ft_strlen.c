
int ft_strlen(char *str)
{
  int number;

  number = 0;
  while (str[number])
  {
    number++;
  }
  return (number);
}

#include <stdio.h>

int main()
{
  char arr[] = "123456abc@#!-DFG";
  printf("number of characters: %d \n", ft_strlen(arr));
  return (0);
}