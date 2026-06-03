/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:
void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;

	x = 10;
	y = 900;
	printf("value -> x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("swap -> x = %d, y = %d\n", x, y);
	return (0);
}
