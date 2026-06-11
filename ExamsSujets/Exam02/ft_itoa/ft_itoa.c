/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:
char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int	ft_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	long	num;
	int		len;

	num = nbr;
	len = ft_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	// 从后往前填数字
	while (num > 0)
	{
		result[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	s1 = ft_itoa(123);
	s2 = ft_itoa(-42);
	s3 = ft_itoa(0);
	s4 = ft_itoa(-2147483648);
	s5 = ft_itoa(889900);
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	printf("%s\n", s4);
	printf("%s\n", s5);
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	free(s5);
	return (0);
}
