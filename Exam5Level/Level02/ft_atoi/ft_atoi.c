/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

/*
	标准 atoi 本身不处理int取值范围的溢出问题
	1. 跳过开头的空白字符 (开头的空白字符可以有多个)
	2. 判断是否有一个正负号 (正负号最多只能有一个)
	3. 从当前位置开始读取连续数字 (数字必须连续), 每读到一个数字字符，就把它转换成int类型的数字
	4. 遇到第1个非数字就立即停止转换
	5. 返回转换得到的整数
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
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

int	is_overflow(long result, int sign, char c)
{
	if (sign == 1 && (result > 214748364 || (result == 214748364 && c > '7')))
		return (1);
	if (sign == -1 && (result > 214748364 || (result == 214748364 && c > '8')))
		return (-1);
	return (0);
}

// 把主函数里的下标变量 i 的地址传进去，让辅助函数可以修改主函数里的 i
int	ft_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

// 加入溢出处理后的版本
int	ft_atoi2(const char *str)
{
	int		i;
	int		sign;
	long	result;
	int		overflow;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = ft_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow = is_overflow(result, sign, str[i]);
		if (overflow == 1)
			return (2147483647);
		if (overflow == -1)
			return (-2147483647 - 1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int)(result * sign));
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("   -42"));
	printf("%d\n", ft_atoi("+123"));
	printf("%d\n", ft_atoi("123abc"));
	printf("%d\n", ft_atoi("abc123"));
	printf("%d\n", ft_atoi("--123"));
	printf("%d\n", ft_atoi("+-123"));
	printf("%d\n", ft_atoi("1234567890123456789"));
	printf("----------\n\n");
	printf("%d\n", ft_atoi2("42"));
	printf("%d\n", ft_atoi2("   -42"));
	printf("%d\n", ft_atoi2("+123"));
	printf("%d\n", ft_atoi2("123abc"));
	printf("%d\n", ft_atoi2("abc123"));
	printf("%d\n", ft_atoi2("--123"));
	printf("%d\n", ft_atoi2("+-123"));
	printf("%d\n", ft_atoi2("1234567890123456789"));
	printf("%d\n", ft_atoi2("-1234567890123456789"));
	return (0);
}
