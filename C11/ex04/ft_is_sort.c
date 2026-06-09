
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	while (i < length - 1 && tab && f)
	{
		result = f(tab[i], tab[i + 1]);
		if (result != 0)
		{
			if (sign == 0)
				sign = result;
			else if ((sign > 0 && result < 0) || (sign < 0 && result > 0))
				return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	int_cmp(int l, int r)
{
	return (l - r);
}

int	main(void)
{
	int test0[] = {-181774,-178486,-164583};
	printf("%d\n", ft_is_sort(test0, 3, int_cmp)); // 1
	printf("%d\n", ft_is_sort(NULL, 0, int_cmp));  // 0
}
*/
