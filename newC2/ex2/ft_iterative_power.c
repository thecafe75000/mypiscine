/*
  求一个数的幂值(是乘方运算的结果)
  理解：a 的 n 次幂，意思是a连续乘自己 n 次，即a^n
  指数 n 决定了乘法出现的次数, 底数 a 是每次参与乘法的因子
  注意：a^0 = 1, 0次幂的结果是1，负数的0次幂的结果也是1
  例如：
  2^3 = 2 × 2 × 2 = 8
  5^4 = 5 × 5 × 5 × 5 = 625
  负数的整数幂：负数的偶次幂结果为正，奇数次幂结果为负
    -指数是 偶数 → 正
    -指数是 奇数 → 负
  
  幂在本质上是一个循环，是重复乘法，当是正整数时，是该数连续相乘n次
*/
int ft_iterative_power(int nb, int power)
{
  int result;

  result = 1;
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  while (power > 0)
  {
    result *= nb;
    power--;
  }
  return (result);
}

#include <stdio.h>

int main()
{
  printf("result = %d\n", ft_iterative_power(2, 3));
  printf("result = %d\n", ft_iterative_power(-2, 3));
  printf("result = %d\n", ft_iterative_power(5, 4));
  printf("result = %d\n", ft_iterative_power(5, -4));
  printf("result = %d\n", ft_iterative_power(5, 0));
  return (0);
}