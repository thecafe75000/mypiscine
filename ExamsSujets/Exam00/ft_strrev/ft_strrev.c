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
	j = 0;
	while (str[i])
		i++;
	while (j < i - 1)
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
	char	str1[] = "12345abcde";
	char	str2[] = "ABC*54321";

	printf("%s\n", ft_strrev(str1));
	printf("%s\n", ft_strrev(str2));
	return (0);
}
