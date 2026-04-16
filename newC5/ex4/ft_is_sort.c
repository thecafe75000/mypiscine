/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:58:13 by string            #+#    #+#             */
/*   Updated: 2026/03/11 12:55:15 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	创建一个函数 ft_is_sort。如果数组已排序，则返回 1；如果未排序，则返回 0。
	传入的函数f是一个比较函数：
		- 第1个参数 < 第2个参数，返回值是负数
		- 第1个参数 > 第2个参数，返回值是正数
		- 第1个参数 == 第2个参数，返回值是0

	判断数组的所有相邻元素：
		- 所有相邻比较结果 >= 0 代码全部元素都符合升序 ordre croissant
		- 所有相邻比较结果 <= 0 代码全部元素都符合降序 ordre decroissant
*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_up;
	int	is_down;

	if (!tab || length < 0 || !f)
		return (0);
	i = 0;
	is_up = 1;
	is_down = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_up = 0;
		else if (f(tab[i], tab[i + 1]) < 0)
			is_down = 0;
		i++;
	}
	return (is_up || is_down);
}

/*
#include <stdio.h>

int	compare(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	arr1[] = {1, 3, 5, 0, 6, 7, -9};
	int	arr2[] = {9, 8, 7, 3, 2};
	int	arr3[] = {-2, -1, 0, 5, 6};
	int	arr4[] = {-2, -4, 7, 100, 33};
	int	arr5[] = {6, 6, 6, 6};

	printf("%d \n", ft_is_sort(arr1, 5, compare));
	printf("%d \n", ft_is_sort(arr2, 5, compare));
	printf("%d \n", ft_is_sort(arr3, 5, compare));
	printf("%d \n", ft_is_sort(arr4, 5, compare));
	printf("%d \n", ft_is_sort(arr5, 4, compare));
	return (0);
}
*/
