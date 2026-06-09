
int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	if (nb == 2)
		return (2);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
#include <stdio.h>

int main()
{
	printf("%d! = %d\n", -1, ft_recursive_factorial(-1));
	printf("%d! = %d\n", 0, ft_recursive_factorial(0));
	printf("%d! = %d\n", 1, ft_recursive_factorial(1));
	printf("%d! = %d\n", 2, ft_recursive_factorial(2));
	printf("%d! = %d\n", 3, ft_recursive_factorial(3));
	printf("%d! = %d\n", 4, ft_recursive_factorial(4));
	printf("%d! = %d\n", 5, ft_recursive_factorial(5));
	printf("%d! = %d\n", 11, ft_recursive_factorial(11));
}
*/
