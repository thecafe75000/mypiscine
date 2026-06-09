
#include <unistd.h>

void	ft_put_recursion(int nb)
{
	char	c;

	if (nb / 10 != 0)
		ft_put_recursion(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_put_recursion(nb);
}
/*
#include <stdio.h>

int	main(void)
{
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(100);
	write(1, "\n", 1);
	ft_putnbr(10);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-10);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
}
// int_max  2147483647
// int_min -2147483648
*/
