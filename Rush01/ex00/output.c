#include "rush01.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_grid(int grid[SIZE][SIZE])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col != SIZE - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
