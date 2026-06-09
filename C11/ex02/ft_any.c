
int	ft_any(char **tab, int (*f)(char *))
{
	if (tab == 0 || f == 0)
		return (0);
	while (*tab)
	{
		if (f(*tab) > 0)
			return (1);
		tab++;
	}
	return (0);
}
/*
#include <stdio.h>

int	check_letter(char *str)
{
	while (*str)
	{
		if (*str == 'z')
			return (1);
		str++;
	}
	return (0);
}

int	main(void)
{
	char	*tab[] = {"abc", "dafga", "daawehey", "", "22", "3", NULL};

	printf("%d", ft_any(tab, &check_letter));
}
*/
