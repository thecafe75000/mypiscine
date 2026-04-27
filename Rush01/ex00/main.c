#include "rush01.h"

static void	init_grid(int grid[SIZE][SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < SIZE)
	{
		col = 0;
		while (col < SIZE)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	inputs[16];
	int	grid[SIZE][SIZE];

	if (argc != 2 || !parse_input(argv[1], inputs))
	{
		print_error();
		return (1);
	}
	init_grid(grid);
	if (!solve_grid(grid, inputs, 0))
	{
		print_error();
		return (1);
	}
	print_grid(grid);
	return (0);
}
