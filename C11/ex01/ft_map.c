
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	if (tab == NULL || length <= 0 || f == NULL)
		return (NULL);
	i = 0;
	result = (int *)malloc(length * sizeof(int));
	if (result == NULL)
		return (NULL);
	while ((i < length))
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	add_self(int i)
{
	return (i + i);
}
int	main(void)
{
	int	src[] = {-2147483648, 13568, 611648, 6184, 684, 684684,
			6816,168,1681,61354,684,61,8,46};
	int	*dest;
	int	i;

	i = 0;
	dest = ft_map(src, 14, add_self);
	while(i < 14)
		printf("%d, ", dest[i++]);
}
*/
