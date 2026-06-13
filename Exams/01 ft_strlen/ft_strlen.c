/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that returns the length of a string.

Your function must be declared as follows:
int	ft_strlen(char *str);
*/

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>

int main()
{
	char str[] = "1234567890abcdef !*.";
	printf("length str = %d\n", ft_strlen(str));
	char *str2 = NULL;
	if (!str2)
	{
		printf("error");
		return (0);
	}
	printf("length str2 = %d\n", ft_strlen(str2));
	return (0);
}
