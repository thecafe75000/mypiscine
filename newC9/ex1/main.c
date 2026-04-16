/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:52:17 by hL                #+#    #+#             */
/*   Updated: 2026/04/09 17:11:22 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

t_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int ac, char **av)
{
	int i;
	t_stock_str *tab;

	if (ac < 2)
		return (0);
	tab = ft_strs_to_tab(ac - 1, av + 1);
	if (!tab)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	i = 0;
	while (tab[i].str)
	{
		printf("tab[%d].size = %d\n", i, tab[i].size);
		printf("tab[%d].str = %s\n", i, tab[i].str);
		printf("tab[%d].copy = %s\n", i, tab[i].copy);
		printf("\n");
		i++;
	}
	while (i > 0)
	{
		i--;
		free(tab[i].copy);
	}
	free(tab);
	return (0);
}
