/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:31:24 by hL                #+#    #+#             */
/*   Updated: 2026/04/07 11:33:36 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	atoi意思是ASCII to integer，把字符串转换成整数
	即把字符串 str 中表示的十进制数字转换成 int 类型整数
		- 先跳过前导空白字符, 比如空格、\t、\n 等
		- 识别可选的正负号
		- 从第一个数字开始，连续读取 '0' 到 '9', 遇到非数字字符时停止
		- 如果一开始就不是合法数字, 通常返回 0
			注意这里有个大坑："0" 和 "abc" 都可能得到 0，你没法仅靠返回值区分“真的转换成 0”还是“根本没转换成功”
	atoi 的特点
		- 遇到非数字就停止
		- 开头非法则返回0
		- 不报错，即没法知道是真的输入了'0'还是输入无效导致返回0
		- 如果字符串表示的数字超过int取值范围，被认定为未定义行为，不会返回某个值
	atoi 的本质就是：
		1. 跳过空白
		2. 识别 + / -
		3. 逐字符读数字
		4. 用 result = result * 10 + digit 累积，返回最int result

*/

char	*ft_isspace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	return (str);
}

char	*ft_isnegative(char *str, int *sign)
{
	*sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	str = ft_isspace(str);
	str = ft_isnegative(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_atoi(" --+-+1234ab567"));
	printf("%d\n", atoi(" --+-+1234ab567"));
	printf("%d\n", ft_atoi("-1234ab567"));
	printf("%d\n", atoi("-1234ab567"));
	printf("%d\n", ft_atoi("+224ab567"));
	printf("%d\n", atoi("+224ab567"));
	printf("%d\n", ft_atoi("ab567"));
	printf("%d\n", atoi("ab567"));
	printf("%d\n", ft_atoi("11122256788888999999999"));
	printf("%d\n", atoi("11122256788888999999999"));
	return (0);
}
