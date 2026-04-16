/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:17:26 by string            #+#    #+#             */
/*   Updated: 2026/03/11 18:49:52 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_range(min, max) 要 创建一个整数数组，内容是 从 min 到 max - 1 的所有整数
// 所有整数意味着数组的长度是max - min, 且当前元素的值+1 = 其后面元素的值
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

void	print_ints(int *ints, int size)
{
	int	i;

	i = 0;
	if (!ints)
		printf("null");
	while (i < size)
	{
		printf("%d ", ints[i]);
		i++;
	}
	printf("\n\n");
}

int	main(void)
{
	int	*test;

	test = ft_range(1, 5);
	print_ints(test, 4);
	free(test);
	test = ft_range(1, 100);
	print_ints(test, 99);
	free(test);
	test = ft_range(-10, 10);
	print_ints(test, 20);
	free(test);
	return (0);
}
*/
