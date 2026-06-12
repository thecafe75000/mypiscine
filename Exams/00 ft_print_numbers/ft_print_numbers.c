/*
Assignment name  : ft_print_numbers
Expected files   : ft_print_numbers.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that displays all digits in ascending order.

Your function must be declared as follows:
void	ft_print_numbers(void);
*/

#include <unistd.h>

// 版本1
void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

// 版本2
void	ft_print_numbers2(void)
{
	write(1, "0123456789", 10);
}

int	main(void)
{
	ft_print_numbers();
	ft_print_numbers2();
	return (0);
}
