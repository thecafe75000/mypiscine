#include "rush01.h"

int	can_place(int grid[SIZE][SIZE], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == value || grid[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_now(int grid[SIZE][SIZE], int clues[16], int row, int col)
{
	if (col == SIZE - 1 && !check_row(grid, clues, row))
		return (0);
	if (row == SIZE - 1 && !check_col(grid, clues, col))
		return (0);
	return (1);
}

int	solve_grid(int grid[SIZE][SIZE], int clues[16], int pos)
{
	int	row;
	int	col;
	int	value;

	if (pos == SIZE * SIZE)
		return (1);
	row = pos / SIZE;
	col = pos % SIZE;
	value = 1;
	while (value <= SIZE)
	{
		if (can_place(grid, row, col, value))
		{
			grid[row][col] = value;
			if (is_valid_now(grid, clues, row, col)
				&& solve_grid(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
