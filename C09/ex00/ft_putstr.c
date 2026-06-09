
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
/*
int	main(void)
{
	ft_putstr("abcd");
	write(1, "\n\n", 2);
	ft_putstr("abc\td\n");
}
*/
