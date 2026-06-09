#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	putint2hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str)
	{
		c = (unsigned char)*str;
		if (*str > 31 && *str < 127)
			ft_putchar((char)c);
		else
			putint2hex(c);
		str++;
	}
}
/*
#include <stdio.h>
#include <string.h>

void ft_putstr_non_printable(char *str);

int	main(void)
{
	char a[50] = "Hello\nHow \tare you?";
	ft_putstr_non_printable(a);
}
*/
