/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:25:04 by hL                #+#    #+#             */
/*   Updated: 2026/04/07 22:47:18 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
	printf("x= %d, y= %d \n", point->x, point->y);
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	return (0);
}
