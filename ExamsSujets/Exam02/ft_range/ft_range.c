/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int	get_len(int start, int end)
{
	int	len;

	len = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	return (len);
}

int	*ft_range(int start, int end)
{
	int	i;
	int	*result;
	int	len;

	i = 0;
	len = get_len(start, end);
	result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = start;
		if (start < end)
			start += 1;
		else
			start -= 1;
		i++;
	}
	return (result);
}

#include <stdio.h>

int	main(void)
{
	int i;
	int *arr1;
	int j;
	int *arr2;
	int k;
	int *arr3;
	int m;
	int *arr4;
	int length1;
	int length2;
	int length3;
	int length4;

	length1 = get_len(1, 3);
	length2 = get_len(-1, 2);
	length3 = get_len(0, 0);
	length4 = get_len(0, -3);
	i = 0;
	arr1 = ft_range(1, 3);
	while (i < length1)
	{
		printf("%d ", arr1[i]);
		i++;
	}
	free(arr1);
	printf("\n\n");
	j = 0;
	arr2 = ft_range(-1, 2);
	while (j < length2)
	{
		printf("%d ", arr2[j]);
		j++;
	}
	free(arr2);
	printf("\n\n");
	k = 0;
	arr3 = ft_range(0, 0);
	while (k < length3)
	{
		printf("%d ", arr3[k]);
		k++;
	}
	free(arr3);
	printf("\n\n");
	m = 0;
	arr4 = ft_range(0, -3);
	while (m < length4)
	{
		printf("%d ", arr4[m]);
		m++;
	}
	free(arr4);
	printf("\n");
	return (0);
}
