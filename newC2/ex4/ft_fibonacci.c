/*
  斐波那契数 序列有这样的公式： Fn = Fn-1 + Fn-2。换句话说，下一个数字是前两个数字的和
  斐波那契数的特点是每一个数都是前2个数的和。头2项是0和1
  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 ...
  
  该题要求使用递归实现
*/

int ft_fibonacci(int index)
{
  if (index < 0)
    return (-1);
  if (index == 0)
    return (0);
  if (index == 1 || index == 2)
    return (1);
  return (ft_fibonacci(index -1) + ft_fibonacci(index - 2));
}

#include <stdio.h>

int main()
{
  printf("result = %d\n", ft_fibonacci(0));
  printf("result = %d\n", ft_fibonacci(1));
  printf("result = %d\n", ft_fibonacci(2));
  printf("result = %d\n", ft_fibonacci(3));
  printf("result = %d\n", ft_fibonacci(7));
  printf("result = %d\n", ft_fibonacci(-2));
  printf("result = %d\n", ft_fibonacci(10));
  return (0);
}