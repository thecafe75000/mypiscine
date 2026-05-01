#include "rush01.h"

// 判断value能不能放在grid[row][col]这个位置，主要检查行和列有没有重复的value
// 返回值1可以放，返回值0不可以放
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

/*
	用来做 回溯过程中“当前这一步放完数字后，棋盘目前是否还合法”的检查，
	可以理解成：当前这一步放完后，还能不能继续走？
	它不是检查整个最终答案，而是检查：
		我刚刚在某个格子放了一个数字, 现在有没有已经违反规则？
		如果已经违反，就没必要继续往后递归
		比如 你刚刚放了一个数字进去：grid[row][col] = value;
		这时候要马上判断：
			如果这一行已经填满了，它的左右可见数量对不对？
			如果这一列已经填满了，它的上下可见数量对不对？
		如果不对，就说明这个 value 放错了，应该立刻撤销，换下一个数字
*/
static int	is_valid_now(int grid[SIZE][SIZE], int inputs[16], int row, int col)
{
	if (col == SIZE - 1 && !check_row(grid, inputs, row))
		return (0);
	if (row == SIZE - 1 && !check_col(grid, inputs, col))
		return (0);
	return (1);
}

// 用回溯法填满 4x4 棋盘
// Remplir un tableau 4x4 avec la méthode de backtracking
int	solve_grid(int grid[SIZE][SIZE], int inputs[16], int pos)
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
			if (is_valid_now(grid, inputs, row, col)
				&& solve_grid(grid, inputs, pos + 1))
					return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}
