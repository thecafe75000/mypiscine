/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays a number's multiplication table.
The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.
If there are no parameters, the program displays \n.

Examples:
$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>

	接收一个正整数参数，然后打印这个数从 1 到 9 的乘法表
	注意不是99乘法表，其中一个乘数是固定的argv[1]数值

	注意：
	数字转字符：+ '0'
	字符转数字：- '0'
*/

#include <unistd.h>

// 把数字字符串转成int数字
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '9' && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// 递归打印输出数字，尤其是十位，百位，千位以上的数字
void	print_number(int n)
{
	char	c;

	if (n >= 10)
		print_number(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
int	main(int argc, char **argv)
{
	int	i;
	int	num;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	num = ft_atoi(argv[1]);
	i = 1;
	while (i <= 9)
	{
		print_number(i);
		write(1, " x ", 3);
		print_number(num);
		write(1, " = ", 3);
		print_number(i * num);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
