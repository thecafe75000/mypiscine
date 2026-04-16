/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:51:54 by string            #+#    #+#             */
/*   Updated: 2026/03/15 22:25:02 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *p 一级指针：存变量地址
 **p 二级指针：存指针地址
 */
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	size = max - min;
	i = 0;
	arr = (int *)malloc(size * sizeof(int));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}

/*
#include <stdlib.h>

void	printnum(int *arr, int size)
{
	int	i;

	i = 0;
	if (!arr)
		printf("null");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
}

int	main(void)
{
	int	size;
	int	*arr1;
	int	*arr2;
	int	*arr3;

	size = ft_ultimate_range(&arr1, 1, 10);
	printnum(arr1, size);
	free(arr1);
	printf("\n");
	size = ft_ultimate_range(&arr2, -5, 9);
	printnum(arr2, size);
	free(arr2);
	printf("\n");
	size = ft_ultimate_range(&arr3, 10, 1);
	printnum(arr3, size);
	free(arr3);
	return (0);
}
*/
