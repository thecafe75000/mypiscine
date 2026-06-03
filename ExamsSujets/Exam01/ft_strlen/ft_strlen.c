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
	printf("length = %d\n", ft_strlen("12345678"));
	printf("length = %d\n", ft_strlen("ab12345678cd"));
	return (0);
}
