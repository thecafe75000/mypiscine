/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that returns the length of a string.

Your function must be declared as follows:
int	ft_strlen(char *str);
*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strlen("abcd1234"));
	printf("%d\n", ft_strlen("*1234567890!"));
	return (0);
}
