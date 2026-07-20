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

int str_length(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int check_base(char *base)
{
	int i = 0;
	if (str_length(base) < 2)
		return (0);
	while (base[i])
	{
		int j = 0;
		while (base[j])
		{
			if (j != i && base[i] == base[j])
				return (0);
			if (base[j] == '+' || base[j] == '-'
				|| (base[j] >= 9 && base[j] <= 13) || base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int is_in_base(char c, char *base)
{
	int i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

