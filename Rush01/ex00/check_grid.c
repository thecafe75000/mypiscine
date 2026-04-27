#include "rush01.h"

/*
	这个c文件检查数据是否符合棋盘规则
*/
// 检查可见数量是否符合要求
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

// 同时检查两个方向
int	check_line(int line[SIZE], int left, int right)
{
	if (count_visible(line, 0, 1) != left)
		return (0);
	return (count_visible(line, SIZE - 1, -1) == right);
}

// 检查一整行
int	check_row(int grid[SIZE][SIZE], int inputs[16], int row)
{
	int	line[SIZE];
	int	col;

	col = 0;
	while (col < SIZE)
	{
		line[col] = grid[row][col];
		col++;
	}
	return (check_line(line, inputs[8 + row], inputs[12 + row]));
}

// 检查一整列
int	check_col(int grid[SIZE][SIZE], int inputs[16], int col)
{
	int	line[SIZE];
	int	row;

	row = 0;
	while (row < SIZE)
	{
		line[row] = grid[row][col];
		row++;
	}
	return (check_line(line, inputs[col], inputs[4 + col]));
}
