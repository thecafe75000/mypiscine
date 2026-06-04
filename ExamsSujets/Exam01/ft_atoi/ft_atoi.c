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
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	str1[] = "abc123";
	char	str2[] = "123467890";
	char	str3[] = "12e3abc";

	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", ft_atoi(str3));
	printf("atoi: %d\n", atoi(str1));
	printf("atoi: %d\n", atoi(str2));
	printf("atoi: %d\n", atoi(str3));
	return (0);
}
