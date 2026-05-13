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
*/
/*
	给程序传入 一个正整数参数，计算并输出 小于或等于这个数的所有质数之和，最后输出换行
	如果参数不合法：输出 0
	否则：从 2 遍历到 n, 如果当前数字是质数,加到 sum 里面
	输出 sum

	合法的参数只包含数字字符，并且数值大于 0
	需要自己写一个函数，功能和atoi函数一样，把字符串转成整数，同时检查是否合法

	质数：大于 1，并且只能被 1 和它自己整除的整数
	注意：
		0 不是质数
		1 不是质数
		2 是最小的质数
*/

#include <unistd.h>

/*
	这个函数是把字符数字转成int数字
	str[i] - '0' 可以把数字字符变成真正的数字
	result = result * 10 + str[i] - '0' 把已有的数字往左移动一位，再加上当前这一位数字
	result 原来是前面已经读到的数字
	result * 10 是给新的一位腾位置
*/
int	ft_atoi_check(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

// 判断某个数字是否是质数
int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// 打印输出数字
void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	sum;

	if (argc == 2)
	{
		n = ft_atoi_check(argv[1]);
		if (n <= 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		i = 2;
		sum = 0;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
