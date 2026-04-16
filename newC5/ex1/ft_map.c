/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:03:18 by string            #+#    #+#             */
/*   Updated: 2026/03/10 10:40:15 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	add(int i)
{
	return (i + i);
}

int	main(void)
{
	int	arr[] = {-2100, 1200, 800, 10};
	int	*finalresult;
	int	i;

	finalresult = ft_map(arr, 4, add);
	i = 0;
	while (i < 4)
	{
		printf("%d, ", finalresult[i]);
		i++;
	}
	return (0);
}
*/
