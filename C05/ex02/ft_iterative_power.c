
int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d^%d = %d\n",  0,  0, ft_iterative_power(0 ,  0));
	printf("%d^%d = %d\n",  1,  0, ft_iterative_power(1 ,  0));
	printf("%d^%d = %d\n",  0,  2, ft_iterative_power(0 ,  2));
	printf("%d^%d = %d\n",  1,  2, ft_iterative_power(1 ,  2));
	printf("%d^%d = %d\n",  2,  2, ft_iterative_power(2 ,  2));
	printf("%d^%d = %d\n",  3,  3, ft_iterative_power(3 ,  3));
	printf("%d^%d = %d\n",  2, 10, ft_iterative_power(2 , 10));
	printf("%d^%d = %d\n", 10, 10, ft_iterative_power(10, 10));
}
*/
