
int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		else
			i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("nb:%d, %d\n",    0, ft_is_prime(   0));
	printf("nb:%d, %d\n",    1, ft_is_prime(   1));
	printf("nb:%d, %d\n",    2, ft_is_prime(   2));
	printf("nb:%d, %d\n",    3, ft_is_prime(   3));
	printf("nb:%d, %d\n",    4, ft_is_prime(   4));
	printf("nb:%d, %d\n",    5, ft_is_prime(   5));
	printf("nb:%d, %d\n",   10, ft_is_prime(  10));
	printf("nb:%d, %d\n",   11, ft_is_prime(  11));
	printf("nb:%d, %d\n",   89, ft_is_prime(  89));
	printf("nb:%d, %d\n",   97, ft_is_prime(  97));
	printf("nb:%d, %d\n", 7841, ft_is_prime(7841));
	printf("nb:%d, %d\n", 7853, ft_is_prime(7853));
}
*/
