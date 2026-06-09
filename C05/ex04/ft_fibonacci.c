
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("index %d: %d\n",-99, ft_fibonacci(-99));
	printf("index %d: %d\n",  0, ft_fibonacci(  0));
	printf("index %d: %d\n",  1, ft_fibonacci(  1));
	printf("index %d: %d\n",  2, ft_fibonacci(  2));
	printf("index %d: %d\n",  3, ft_fibonacci(  3));
	printf("index %d: %d\n",  4, ft_fibonacci(  4));
	printf("index %d: %d\n",  5, ft_fibonacci(  5));
	printf("index %d: %d\n",  6, ft_fibonacci(  6));
	printf("index %d: %d\n",  7, ft_fibonacci(  7));
	printf("index %d: %d\n",  8, ft_fibonacci(  8));
	printf("index %d: %d\n", 20, ft_fibonacci( 20));
	printf("index %d: %d\n", 21, ft_fibonacci( 21));
	printf("index %d: %d\n", 22, ft_fibonacci( 22));
}
*/
