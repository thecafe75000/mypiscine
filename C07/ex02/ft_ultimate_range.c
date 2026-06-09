
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
/*
#include <stdio.h>
void	printiints(int *ints, int size)
{
	int i = 0;
	if (!ints)
	{
		printf("null");
	}
	while (i < size)
		printf("%d,", ints[i++]);
	printf("\n");
}

int	main()
{
	int *test0, *test1, *test2, *test3, *test4;
	int size;

	size = ft_ultimate_range(&test0, 0, 1);
	printiints(test0, size);
	free(test0);

	size = ft_ultimate_range(&test1, -10, 10);
	printiints(test1, size);
	free(test1);

	size = ft_ultimate_range(&test2, 10, 1);
	printiints(test2, size);
	free(test2);

	size = ft_ultimate_range(&test3, 0, 100);
	printiints(test3, size);
	free(test3);

	size = ft_ultimate_range(&test4, -100, 50);
	printiints(test4, size);
	free(test4);
}
*/
