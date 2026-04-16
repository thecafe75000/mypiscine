/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hL <hL@stu.42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:53:19 by string            #+#    #+#             */
/*   Updated: 2026/03/26 21:01:18 by hL               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	要求：把字符串 nbr 按照 base_from 的规则读成一个数，再把这个数按 base_to 的规则重新写成新的字符串返回
	也就是说：
		- 输入是一个 char * 字符串, 这个字符串的数值意义，要根据 base_from 来解释
		- 然后输出一个新字符串，内容用 base_to 表示
		- 返回值也是char * 类型
	• 如果 base 不合法，函数必须返回 NULL. 以下是 非法 base 的例子：
		- base 为空字符串，或者只有 一个字符
		- base 中包含 重复字符
		- base 中包含 '+'、'-' 或者空白字符（whitespace）

	进制系统（base system）由用于表示数字的所有符号组成：
		- 0123456789 是常用的十进制
		- 01 是二进制
		- 0123456789ABCDEF 是十六进制
		- poneyvif 是八进制

	2个c文件：
		- convert_base: 主控制逻辑，只负责流程控制和调用工具函数
		- convert_base2: 用来放所有工具函数
*/
#include <stdlib.h>

char	*ft_putnbr_base(long nbr, char *base);


int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9
				&& base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}


int	in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_atoi_base(char *str, char *base)
{
	long	nb;
	int		sign;
	int		base_len;
	int		digit;

	nb = 0;
	sign = 1;
	base_len = check_base(base);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	digit = in_base(*str, base);
	while (digit != -1)
	{
		nb = nb * base_len + digit;
		str++;
		digit = in_base(*str, base);
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	char	*convert_str;

	num = 0;
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	convert_str = ft_putnbr_base(num, base_to);
	return (convert_str);
}

#include <stdio.h>

void	ft_test(char *nbr, char *base_from, char *base_to)
{
	char	*res;

	res = ft_convert_base(nbr, base_from, base_to);
	printf("nbr       : \"%s\"\n", nbr);
	printf("base_from : \"%s\"\n", base_from);
	printf("base_to   : \"%s\"\n", base_to);
	if (res)
	{
		printf("result    : \"%s\"\n", res);
		free(res);
	}
	else
		printf("result    : NULL\n");
	printf("-----------------------------\n");
}

int	main(void)
{
	ft_test("42", "0123456789", "01");
	ft_test("101010", "01", "0123456789");
	ft_test("52", "01234567", "0123456789");
	ft_test("2a", "0123456789abcdef", "0123456789");
	ft_test("-42", "0123456789", "01");
	ft_test("0", "0123456789", "0123456789abcdef");
	ft_test("-0", "0123456789", "01");
	ft_test("", "0123456789", "01");
	ft_test("   ---42", "0123456789", "01");
	ft_test("42abc", "0123456789", "01");
	ft_test("abc42", "0123456789", "01");
	ft_test(" - 42", "0123456789", "01");
	ft_test("---+     42", "0123456789", "01");
	ft_test("42", "0", "01");
	ft_test("42", "01234056789", "01");
	ft_test("42", "0123456789", "0+1");
	ft_test("0", "0123456789", "12");
	return (0);
}
