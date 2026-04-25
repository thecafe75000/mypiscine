#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

# define SIZE 4

int	parse_input(char *str, int clues[16]);
int	solve_grid(int grid[SIZE][SIZE], int clues[16], int pos);
int	can_place(int grid[SIZE][SIZE], int row, int col, int value);
int	check_line(int line[SIZE], int left, int right);
int	check_row(int grid[SIZE][SIZE], int clues[16], int row);
int	check_col(int grid[SIZE][SIZE], int clues[16], int col);
void	print_grid(int grid[SIZE][SIZE]);
void	print_error(void);

#endif
