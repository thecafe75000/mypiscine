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

#include <stdio.h>

int	main(void)
{
	printf("1: %d\n", ft_atoi("42"));
	printf("2: %d\n", ft_atoi("   -42"));
	printf("3: %d\n", ft_atoi("+123"));
	printf("4: %d\n", ft_atoi("123abc"));
	printf("5: %d\n", ft_atoi("abc123"));
	printf("6: %d\n", ft_atoi("--123"));
	printf("7: %d\n", ft_atoi("+-123"));
	printf("8: %d\n", ft_atoi("1234567890123456789"));

	return (0);
}
