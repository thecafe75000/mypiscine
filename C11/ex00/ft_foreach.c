
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (f != 0 && tab != 0 && length > 0)
	{
		i = 0;
		while (i < length)
		{
			f(tab[i++]);
		}
	}
}
/*
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = '0' + nbr % 10;
	write(1, &c, 1);
}

int	main(void)
{
	int	tab[] = {-2147483648, 13568, 611648, 6184, 684, 684684,
			6816,168,1681,61354,684,61,8,46};

	ft_foreach(tab, 14, &ft_putnbr);
}
*/
