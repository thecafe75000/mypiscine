/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:36:18 by hL                #+#    #+#             */
/*   Updated: 2026/04/15 12:59:10 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void		ft_putchar(char c);

static void	print_char(int row, int col, int x, int y)
{
	if (row == 1 && col == 1)
		ft_putchar('/');
	else if (row == 1 && col == x)
		ft_putchar('\\');
	else if (row == y && col == 1)
		ft_putchar('\\');
	else if (row == y && col == x)
		ft_putchar('/');
	else if (row == 1 || row == y || col == 1 || col == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

int	rush01(int x, int y)
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
