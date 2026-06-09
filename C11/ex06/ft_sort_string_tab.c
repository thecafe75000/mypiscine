
void	ft_strswap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_strswap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		ft_sort_string_tab(argv);
		while (i < argc)
			printf("%s\n", argv[i++]);
	}
}
*/
