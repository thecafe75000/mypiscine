#include <unistd.h>

void		ft_putchar(char c);

static void	print_char(int row, int col, int x, int y)
{
	if (row == 1 && col == 1)
		ft_putchar('A');
	else if (row == 1 && col == x)
		ft_putchar('A');
	else if (row == y && col == 1)
		ft_putchar('C');
	else if (row == y && col == x)
		ft_putchar('C');
	else if (row == 1 || row == y || col == 1 || col == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

int	rush02(int x, int y)
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
