#include "rush01.h"

static int	count_visible(int line[SIZE], int start, int step)
{
	int	index;
	int	max;
	int	count;

	index = start;
	max = 0;
	count = 0;
	while (index >= 0 && index < SIZE)
	{
		if (line[index] > max)
		{
			max = line[index];
			count++;
		}
		index += step;
	}
	return (count);
}

int	check_line(int line[SIZE], int left, int right)
{
	if (count_visible(line, 0, 1) != left)
		return (0);
	return (count_visible(line, SIZE - 1, -1) == right);
}

int	check_row(int grid[SIZE][SIZE], int clues[16], int row)
{
	int	line[SIZE];
	int	col;

	col = 0;
	while (col < SIZE)
	{
		line[col] = grid[row][col];
		col++;
	}
	return (check_line(line, clues[8 + row], clues[12 + row]));
}

int	check_col(int grid[SIZE][SIZE], int clues[16], int col)
{
	int	line[SIZE];
	int	row;

	row = 0;
	while (row < SIZE)
	{
		line[row] = grid[row][col];
		row++;
	}
	return (check_line(line, clues[col], clues[4 + col]));
}
