int ft_recursive_power(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)   // 递归终止条件
    return (1);

  return (nb * ft_recursive_power(nb, power - 1));
}

#include <stdio.h>

int main()
{
  printf("result = %d\n", ft_recursive_power(2, 3));
  printf("result = %d\n", ft_recursive_power(-2, 3));
  printf("result = %d\n", ft_recursive_power(5, 4));
  printf("result = %d\n", ft_recursive_power(5, -2));
  printf("result = %d\n", ft_recursive_power(5, 0));
  return (0);
}
