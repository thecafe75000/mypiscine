
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	if (!*str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int	strlen;

	strlen = ft_strlen(str);
	write(1, str, strlen);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	ft_putstr("abcd");
	write(1, "\n\n", 2);
	ft_putstr("abc\td\n");
}
*/
