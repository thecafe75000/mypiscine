
int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	if (tab == 0 || length <= 0 || f == 0)
		return (0);
	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}
/*
int	char_check(char *str)
{
	while (*str)
	{
		if (*str == 'g')
			return (1);
		str++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	*tab[] = {"abc", "dafga", "daawehey", "", "22", "3", "emgqeiowgn"};

	printf("%d", ft_count_if(tab, 7, char_check));
}
*/
