/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:
char	*ft_strrev(char *str);
*/

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (j < i )
	{
		temp = str[i-1];
		str[i-1] = str[j];
		str[j] = temp;
		i--;
		j++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char str[] = " * abc123456 efg ";
	printf("%s\n", ft_strrev(str));
	return (0);
}
