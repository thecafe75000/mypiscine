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
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "1234567890*!abc";
	char	*str1;

	str1 = "abcdefg123*@#+9988";
	printf("str= %d\n", ft_strlen(str));
	printf("str1= %d\n", ft_strlen(str1));
	return (0);
}
