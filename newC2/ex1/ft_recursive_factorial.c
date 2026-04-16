/*
  一个正整数的阶乘（英语：factorial）是所有小于及等于该数的正整数的积，并且 0 的阶乘为 1
  阶乘亦可以递归方式定义：0!=1，1!=1，n!=(n-1)!×n
  比如：5! = 5*4*3*2*1
  注意：负数没有阶乘，阶乘只定义在非负整数上
  用递归实现：n!=(n-1)!×n
*/

int ft_recursive_factorial(int nb)
{
  int result;
  
  result = 1;
  if (nb < 0)
    return (0);
  if (nb == 0 || nb == 1)
    return (1);
  result = nb * ft_recursive_factorial(nb - 1);
  return (result);
}

#include <stdio.h>

int main()
{
  printf("-1 result = %d\n", ft_recursive_factorial(-1));
  printf("5 result = %d\n", ft_recursive_factorial(5));
  printf("0 result = %d\n", ft_recursive_factorial(0));
  printf("11 result = %d\n", ft_recursive_factorial(11));
  printf("1 result = %d\n", ft_recursive_factorial(1));
  return (0);
}