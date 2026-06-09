
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = (int *)malloc((max - min) * sizeof(int));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

void	printiints(int *ints, int size)
{
	int	i;

	i = 0;
	if (!ints)
	{
		printf("null");
	}
	while (i < size)
		printf("%d,", ints[i++]);
	printf("\n");
}

int	main(void)
{
	int	*test;

	test = ft_range(0, 1);
	printiints(test, 1);
	free(test);
	test = ft_range(-10, 10);
	printiints(test, 20);
	free(test);
	test = ft_range(10, 1);
	printiints(test, 0);
	free(test);
	test = ft_range(0, 100);
	printiints(test, 100);
	free(test);
	test = ft_range(-100, 50);
	printiints(test, 150);
	free(test);
}
*/
