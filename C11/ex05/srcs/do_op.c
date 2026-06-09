
#include <unistd.h>

int	calc_add(int l, int r);
int	calc_sub(int l, int r);
int	calc_mul(int l, int r);
int	calc_div(int l, int r);
int	calc_mod(int l, int r);
int	ft_atoi(char *str);

int	(*get_operator(char *opt))(int l, int r)
{
	int	i;

	i = 0;
	while (opt[i])
		i++;
	if (i == 1)
	{
		if (opt[0] == '+')
			return (calc_add);
		if (opt[0] == '-')
			return (calc_sub);
		if (opt[0] == '*')
			return (calc_mul);
		if (opt[0] == '/')
			return (calc_div);
		if (opt[0] == '%')
			return (calc_mod);
	}
	write(1, "0\n", 2);
	return (0);
}

void	putnbr(int nb)
{
	char	c;

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
	if (nb / 10 != 0)
		putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	argv_process(char **argv, int (**opt)(int, int), int *l, int *r)
{
	*opt = get_operator(argv[2]);
	if (*opt == 0)
		return (0);
	*l = ft_atoi(argv[1]);
	*r = ft_atoi(argv[3]);
	return (1);
}

int	main(int argc, char **argv)
{
	int	(*opt)(int, int);
	int	l;
	int	r;

	if (argc != 4)
		return (0);
	if (argv_process(argv, &opt, &l, &r) == 1)
	{
		if (r == 0 && opt == calc_div)
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		if (r == 0 && opt == calc_mod)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
		putnbr(opt(l, r));
		write(1, "\n", 1);
	}
}
