/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.

Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

	给程序传入 一个正整数参数，计算并输出 小于或等于这个数的所有质数之和，最后输出换行
	如果参数不合法：输出 0
	否则：从 2 遍历到 n, 如果当前数字是质数,加到 sum 里面
	输出 sum

	质数：大于 1，并且只能被 1 和它自己整除的整数
	注意：
		0 不是质数
		1 不是质数
		2 是最小的质数
		所有质数中，除了 2 以外，其余全部都是奇数
*/

#include <unistd.h>

// 把参数字符数组转成int数字，方便后面的计算和用于判断数字是否是质数
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
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

// 判断数字是否是质数
int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n < 2)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// 打印输出数字
// 先递归打印高位，再打印低位, 也就是“从左到右输出数字”
void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	num;
	int	sum;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	num = ft_atoi(argv[1]);
	if (num <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	i = 2;
	sum = 0;
	while (i <= num)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
