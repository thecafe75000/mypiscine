/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:48:08 by hL                #+#    #+#             */
/*   Updated: 2026/04/15 23:12:36 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

/*
	row: ligne , col:colonne, x: largeur, y: hauteur
	row = 1 ... y; col = 1 ... x
	row == 1 -> la 1ere ligne; row == y -> la derniere ligne
	col == 1 -> la 1ere colonne; col == x -> la derniere colonne

	所有位置：
	左上角：row == 1 && col == 1
	右上角：row == 1 && col == x
	左下角：row == y && col == 1
	右下角：row == y && col == x
	上边：row == 1
	下边：row == y
	左边：col == 1
	右边：col == x
*/
static void	print_char(int row, int col, int x, int y)
{
	if ((row == 1 && col == 1) || (row == 1 && col == x) || (row == y
			&& col == 1) || (row == y && col == x))
		ft_putchar('o');
	else if (row == 1 || row == y)
		ft_putchar('-');
	else if (col == 1 || col == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

int	rush00(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
	{
		write(1, "error!\n", 7);
		write(1, "the parameter must be at least 1\n", 33);
		return (-1);
	}
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			print_char(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	return (0);
}
